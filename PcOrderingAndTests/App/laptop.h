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
