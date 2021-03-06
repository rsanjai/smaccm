/**
 * 
 */
package edu.umn.cs.crisys.smaccm.aadl2rtos.codegen.CAmkES;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import edu.umn.cs.crisys.smaccm.aadl2rtos.model.port.OutputEventPort;
import edu.umn.cs.crisys.smaccm.aadl2rtos.model.thread.OutgoingDispatchContract;

/**
 * @author Whalen
 *
 */
public class OutgoingDispatchContractNames {
  OutgoingDispatchContract odc; 
  
  OutgoingDispatchContractNames(OutgoingDispatchContract odc) {
    this.odc = odc;
  }
  
  public List<DispatchContractNames> getContracts() {
    List<DispatchContractNames> pdl = new ArrayList<>(); 
    for (Map.Entry<OutputEventPort, Integer> elem : odc.getContract().entrySet()) {
      pdl.add(new DispatchContractNames(elem));
    }
    return pdl;
  }
  
  public String getFoo() { 
    return "foo!"; 
  }
}

