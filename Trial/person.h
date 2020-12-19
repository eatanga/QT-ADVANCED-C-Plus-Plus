#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;


class Person
{
private:
    int id;
    string name;
    int age;
    double weight;
    string eyeColor;
public:
    Person();
    int getId(){return id;}
    void setId(int id){this->id =id;}
    string getName(){return name;}
    void setName(string n){this->name =n;}
    int getAge(){return age;}
    void setAge(int a){this->age =a;}
    double getWeight(){return weight;}
    void setWeight(double w){this->weight =w;}
    string getEyeColor(){return eyeColor;}
    void setEyeColor(string eye){this->eyeColor =eye;}
};

#endif // PERSON_H
