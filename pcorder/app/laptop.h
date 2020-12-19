#ifndef LAPTOP_H
#define LAPTOP_H
#include "CPU.h"
#include "Memory.h"
#include "Storage.h"
#include "Screen.h"
#include "Battery.h"

class Laptop
{
private:
    double price;
    CPU cpu;
    Memory mem;
    Storage storage;
    Screen screen;
    Battery battery;
public:
    Laptop();
    // Constructor with parameters
        Laptop(CPU cpu, Memory mem, Storage storage, Screen sc, Battery batt):cpu(cpu),mem(mem),storage(storage), screen(sc),battery(batt){}
    string display();
    double totalPrice();

    double getPrice(){
           return totalPrice();
       }
    void setPrice(double price){
            this->price = price;
        }
};

#endif // LAPTOP_H
