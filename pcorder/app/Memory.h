#ifndef MEMORY_H
#define MEMORY_H
#include "computer.h"
#include <iostream>
using namespace std;

class Memory : public Computer{
private://Encapsulation of variables to hide data
    string clockSpeedInMHZ;
    string sizeInGB;
    double price;
public:
    Memory(){}
    Memory(string clockSpeedInMHZ, string sizeInGB, double price): clockSpeedInMHZ(clockSpeedInMHZ),sizeInGB(sizeInGB),price(price){}

    //Accessors
    double getPrice(){
       return price;
    }
    string getCLockSpeed(){
        return clockSpeedInMHZ;
    }
    string getSize(){
        return sizeInGB;
    }

    //Mutators
    void setClockSpeed(string clockSpeed){
        this->clockSpeedInMHZ =clockSpeed;
    }
    void setSize(string size){
        this->sizeInGB = size;
    }
    void setPrice(double price){
        this->price = price;
    }

};
#endif // MEMORY_H
