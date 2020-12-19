#ifndef STORAGE_H
#define STORAGE_H
#include "computer.h"
#include <iostream>

using namespace std;

class Storage : public Computer {
private://Encapsulation of variables to hide data
    string sizeInTB;
    double price;
public:
    Storage(){}
    Storage(string sizeInTB, double price): sizeInTB(sizeInTB), price(price){}

    //Accesors
    double getPrice(){
        return price;
    }
    string getSize(){
        return sizeInTB;
    }

    //Muatators
    void setSize(string size){
        this->sizeInTB = size;
    }
    void setPrice(double price){
        this->price = price;
    }
};

#endif // STORAGE_H
