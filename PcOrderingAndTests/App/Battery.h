#ifndef BATTERY_H
#define BATTERY_H
#include <string>
#include <iostream>
#include "Computer.h"
using namespace std;

class Battery : public Computer {
private://Encapsulation of variables to hide data
    string capacityInHrs;
    double price;
public:
    Battery(){}
    Battery(string capacityInHrs, double price): capacityInHrs(capacityInHrs), price(price){}

    //Accessors
    double getPrice(){
       return price;
    }
    string getCapacity(){
        return capacityInHrs;
    }
    //Muatators
    void setCapacity(string capacity){
        this->capacityInHrs = capacity;
    }
    void setPrice(double price){
        this->price = price;
    }
};

#endif // BATTERY_H
