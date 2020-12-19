#ifndef DESKTOP_H
#define DESKTOP_H
#include "CPU.h"
#include "Memory.h"
#include "Storage.h"
#include "PowerSupply.h"

class Desktop
{
private://Encapsulation of variables to hide data
    double price;
    CPU cpu;
    Memory mem;
    Storage storage;
    PowerSupply powersupply;
public:
    Desktop();
    Desktop(CPU cpu,Memory mem,Storage storage, PowerSupply pwr): cpu(cpu),mem(mem),storage(storage),powersupply(pwr){}
    string display();
    double totalPrice();

    double getPrice(){
           return totalPrice();
       }
       void setPrice(double price){
           this->price = price;
       }
};

#endif // DESKTOP_H
