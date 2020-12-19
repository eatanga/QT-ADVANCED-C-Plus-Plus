//Emmanuel Atanga
//09/25/2020
//PcOrdering Assignment.
#include "desktop.h"

Desktop::Desktop()
{

}

//Method to Calculate the total price of the desktop using abstraction to hide implementation details
   double Desktop :: totalPrice(){
       return (cpu.getPrice() + mem.getPrice() + storage.getPrice() + powersupply.getPrice());
   }
   //Method to display desktop details using abstraction to hide implementation details
   string Desktop :: display(){
       string specs = "CPU Name:" + cpu.getName() + " CPU Speed:" + cpu.getSpeed() + " Number of cores: " +
               to_string(cpu.getCores()) + "\nCPU Price:" + to_string(cpu.getPrice()) + " Memory Speed:"
               + mem.getCLockSpeed() + " Memory Size:" + mem.getSize() + "\nMemory Price:" +
               to_string(mem.getPrice()) + " Storage Size:" + storage.getSize() + "\nStorage Price:"
               + to_string(storage.getPrice()) + " Power Supply Voltage:"
               + powersupply.getRatings() + " Power Supply Price:" + to_string(powersupply.getPrice());
       return specs;
   }
