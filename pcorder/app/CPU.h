#ifndef CPU_H
#define CPU_H
#include <iostream>
#include "computer.h"
using namespace std;

class CPU : public Computer {
private: //Encapsulation of variables to hide data
    string name;
    string speedInGHZ;
    int numOfCores;
    double price;

public:
        CPU(){}
        CPU(string name, string speedInGHZ, int numOfCores, double price): name(name),speedInGHZ(speedInGHZ),numOfCores(numOfCores),price(price){}

        //Accessors
        double getPrice(){
            return price;
        }
        string getName(){
            return name;
        }
        string getSpeed(){
            return speedInGHZ;
        }
        int getCores(){
            return numOfCores;
        }

        //Mutators
        void setName(string name){
            this->name = name;
        }
        void setSpeed(string speed){
            this->speedInGHZ = speed;
        }
        void setNumOfCores(int cores){
            this->numOfCores = cores;
        }
        void setPrice(double price){
            this->price = price;
        }

    };

#endif // CPU_H
