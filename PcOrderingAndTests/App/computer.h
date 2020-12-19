#ifndef COMPUTER_H
#define COMPUTER_H
#include "Computer.h"
#include <iostream>
using namespace std;

// Base Class computer because both the desktop and the laptop are computers with added components
class Computer{
private:

public:
     Computer(){}

     //Virtual method using polymorphism to decider the total price for both the laptop and the desktop
     // This one method if used multiple times in different parts of the program with different parameters.
    virtual double totalPrice(){
        return 0;
    }
     //Virtual method using polymorphism to decider the display for both the laptop and the desktop
     virtual string display(){
         return 0;
     }
};


#endif // COMPUTER_H
