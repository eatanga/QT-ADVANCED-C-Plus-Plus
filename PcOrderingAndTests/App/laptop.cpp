#include "laptop.h"

Laptop::Laptop()
{

}
//Method to Calculate the total price of the desktop using abstraction to hide implementation details
    double Laptop :: totalPrice(){
        return (cpu.getPrice() + mem.getPrice() + storage.getPrice() + screen.getPrice() + battery.getPrice());
    }

    //Method to display Laptop details using abstraction to hide implementation details
        string Laptop :: display(){
            string specs = "CPU Name:" + cpu.getName() + " CPU Speed:" + cpu.getSpeed() + " Number of cores: "
                    + to_string(cpu.getCores()) + "\nCPU Price:" + to_string(cpu.getPrice()) + " Memory Speed:"
                    + mem.getCLockSpeed() + " Memory Size:" + mem.getSize() + "\nMemory Price:"
                    + to_string(mem.getPrice()) + " Storage Size:" + storage.getSize() + " Storage Price:"
                    + to_string(storage.getPrice()) + "\nScreen Size:"
                    + screen.getSize() + " Screen Price:" + to_string(screen.getPrice())
                    + " Battery Capacity:" + battery.getCapacity() + " Battery Proce:" +to_string(battery.getPrice());
            return specs;
        }
