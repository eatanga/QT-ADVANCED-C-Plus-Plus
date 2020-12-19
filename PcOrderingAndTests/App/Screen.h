#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
using namespace std;

class Screen{
private://Encapsulation of variables to hide data
    string sizeInInches;
    double price;
public:
    Screen(){}
    Screen(string sizeInInches, double price): sizeInInches(sizeInInches), price(price){}

    //Accessors
    double getPrice(){
                    return price;
    }
    string getSize(){
        return sizeInInches;
    }

    //Mutators
    void setSize(string size){
        this->sizeInInches = size;
    }
    void setPrice(double price){
        this->price = price;
    }
};
#endif // SCREEN_H
