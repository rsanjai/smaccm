package com.rockwellcollins.atc.resolute.analysis.handlers;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.swt.widgets.Display;
import org.eclipse.ui.IWorkbenchPage;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.handlers.IHandlerActivation;
import org.eclipse.ui.handlers.IHandlerService;
import org.eclipse.xtext.EcoreUtil2;
import org.osate.aadl2.AnnexSubclause;
import org.osate.aadl2.ComponentCategory;
import org.osate.aadl2.Element;
import org.osate.aadl2.NamedElement;
import org.osate.aadl2.SystemImplementation;
import org.osate.aadl2.instance.ComponentInstance;
import org.osate.aadl2.instance.ConnectionInstance;
import org.osate.aadl2.instance.SystemInstance;
import org.osate.aadl2.instantiation.InstantiateModel;
import org.osate.annexsupport.AnnexUtil;
import org.osate.ui.dialogs.Dialog;

import com.rockwellcollins.atc.resolute.analysis.execution.EvaluationContext;
import com.rockwellcollins.atc.resolute.analysis.execution.FeatureToConnectionsMap;
import com.rockwellcollins.atc.resolute.analysis.execution.NamedElementComparator;
import com.rockwellcollins.atc.resolute.analysis.execution.ResoluteInterpreter;
import com.rockwellcollins.atc.resolute.analysis.results.ResoluteResult;
import com.rockwellcollins.atc.resolute.analysis.views.AssuranceCaseView;
import com.rockwellcollins.atc.resolute.resolute.ProveStatement;
import com.rockwellcollins.atc.resolute.resolute.ResolutePackage;
import com.rockwellcollins.atc.resolute.resolute.ResoluteSubclause;
import com.rockwellcollins.atc.resolute.validation.BaseType;

public class ResoluteHandler extends AadlHandler {
    private static final String RERUN_ID = "com.rockwellcollins.atc.resolute.analysis.commands.rerunResolute";
    private IHandlerActivation rerunActivation;

    @Override
    protected String getJobName() {
        return "Resolute Analysis";
    }

    @Override
    protected IStatus runJob(Element root, IProgressMonitor monitor) {
        clearProofs();
        disableRerunHandler();

        long start = System.currentTimeMillis();
        SystemInstance si;
        if (root instanceof SystemImplementation) {
            SystemImplementation sysimpl = (SystemImplementation) root;
            try {
                si = InstantiateModel.buildInstanceModelFile(sysimpl);
            } catch (Exception e) {
                Dialog.showError("Model Instantiate", "Error while re-instantiating the model: "
                        + e.getMessage());
                return Status.CANCEL_STATUS;
            }
        } else {
            Dialog.showError("Model Instantiate",
                    "You must select a System Implementation to instantiate");
            return Status.CANCEL_STATUS;
        }
        long stop = System.currentTimeMillis();
        System.out.println("Instantiation time: " + (stop - start) / 1000.0 + "s");

        start = System.currentTimeMillis();

        Map<String, SortedSet<NamedElement>> sets = new HashMap<>();
        initializeSets(si, sets);
        FeatureToConnectionsMap featToConnsMap = new FeatureToConnectionsMap(si);

        // Right now OSATE has a bug where subclauses will show up twice, 
        Set<AnnexSubclause> osateBugWorkaround = new HashSet<>();
        
        List<ResoluteResult> proofTrees = new ArrayList<>();
        for (NamedElement el : sets.get("component")) {
            ComponentInstance compInst = (ComponentInstance) el;
            EClass resoluteSubclauseEClass = ResolutePackage.eINSTANCE.getResoluteSubclause();
            for (AnnexSubclause subclause : AnnexUtil.getAllAnnexSubclauses(
                    compInst.getComponentClassifier(), resoluteSubclauseEClass)) {
                if (osateBugWorkaround.contains(subclause)) {
                    continue;
                } else {
                    osateBugWorkaround.add(subclause);
                }
                if (subclause instanceof ResoluteSubclause) {
                    ResoluteSubclause resoluteSubclause = (ResoluteSubclause) subclause;
                    EvaluationContext context = new EvaluationContext(compInst, sets,
                            featToConnsMap);
                    ResoluteInterpreter interpreter = new ResoluteInterpreter(context);
                    for (ProveStatement ps : resoluteSubclause.getProves()) {
                        proofTrees.add(interpreter.evaluateProveStatement(ps));
                        drawProofs(proofTrees);
                    }
                }
            }
        }
        stop = System.currentTimeMillis();
        System.out.println("Evaluation time: " + (stop - start) / 1000.0 + "s");

        enableRerunHandler(root);
        System.out.println(EcoreUtil2.getURI(root));

        return Status.OK_STATUS;
    }

    private void enableRerunHandler(final Element root) {
        getWindow().getShell().getDisplay().syncExec(new Runnable() {
            @Override
            public void run() {
                IHandlerService handlerService = getHandlerService();
                rerunActivation = handlerService.activateHandler(RERUN_ID, new RerunHandler(root, ResoluteHandler.this));
            }
        });
    }

    private void disableRerunHandler() {
        if (rerunActivation != null) {
            getWindow().getShell().getDisplay().syncExec(new Runnable() {
                @Override
                public void run() {
                    IHandlerService handlerService = getHandlerService();
                    handlerService.deactivateHandler(rerunActivation);
                    rerunActivation = null;
                }
            });
        }
    }

    private IHandlerService getHandlerService() {
        return (IHandlerService) getWindow().getService(IHandlerService.class);
    }

    private void initializeSets(ComponentInstance ci, Map<String, SortedSet<NamedElement>> sets) {
        if (ci == null) {
            return;
        }

        addToSet(sets, getCategoryName(ci.getCategory()), ci);
        addToSet(sets, "component", ci);

        for (ComponentInstance sub : ci.getComponentInstances()) {
            initializeSets(sub, sets);
        }

        for (ConnectionInstance conn : ci.getConnectionInstances()) {
            addToSet(sets, "connection", conn);
        }
    }

    private String getCategoryName(ComponentCategory category) {
        return new BaseType(category).toString();
    }

    private void addToSet(Map<String, SortedSet<NamedElement>> sets, String name, NamedElement ne) {
        SortedSet<NamedElement> set = sets.get(name);
        if (set == null) {
            set = new TreeSet<>(new NamedElementComparator());
            sets.put(name, set);
        }
        set.add(ne);
    }

    private void drawProofs(final List<ResoluteResult> proofTrees) {
        final IWorkbenchPage page = getWindow().getActivePage();

        Display.getDefault().asyncExec(new Runnable() {
            @Override
            public void run() {
                displayView(proofTrees, page);
            }
        });
    }

    private void displayView(final List<ResoluteResult> proofTrees, final IWorkbenchPage page) {
        try {
            AssuranceCaseView view = (AssuranceCaseView) page.showView(AssuranceCaseView.ID);
            view.setProofs(proofTrees);
            view.setFocus();
        } catch (PartInitException e) {
            e.printStackTrace();
        }
    }

    protected void clearProofs() {
        drawProofs(Collections.<ResoluteResult> emptyList());
    }
}
