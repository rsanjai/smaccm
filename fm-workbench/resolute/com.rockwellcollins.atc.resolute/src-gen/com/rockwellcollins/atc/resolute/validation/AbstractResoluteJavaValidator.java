/*
* generated by Xtext
*/
package com.rockwellcollins.atc.resolute.validation;
 
import java.util.ArrayList;
import java.util.List;

import org.eclipse.emf.ecore.EPackage;

public class AbstractResoluteJavaValidator extends org.osate.xtext.aadl2.properties.validation.PropertiesJavaValidator {

	@Override
	protected List<EPackage> getEPackages() {
	    List<EPackage> result = new ArrayList<EPackage>();
	    result.add(com.rockwellcollins.atc.resolute.resolute.ResolutePackage.eINSTANCE);
	    result.add(EPackage.Registry.INSTANCE.getEPackage("http://aadl.info/AADL/2.0"));
		return result;
	}

}
