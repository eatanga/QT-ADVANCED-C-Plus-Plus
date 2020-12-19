#ifndef POWERSUPPLY_H
#define POWERSUPPLY_H
#include "computer.h"
#include <iostream>
using namespace std;

class PowerSupply : public Computer {
private://Encapsulation of variables to hide data
    string ratingInWatts;
    double price;
public:
    PowerSupply(){}
    PowerSupply(string ratingInWatts, double price): ratingInWatts(ratingInWatts), price(price){}

    //Accessors
    double getPrice(){
                    return price;
    }
    string getRatings(){
        return ratingInWatts;
    }
    //Muatators
    void setRating(string rating){
        this->ratingInWatts = rating;
    }
    void setPrice(double price){
        this->price = price;
    }
};
#endif // POWERSUPPLY_H
