//Emmanuel Atanga
//09/05/2020
#include <array>
#include <iostream>
using namespace std;

const int SIZE = 9;

int main(){
    array<double,SIZE> items;

    cout<<"Please enter 9 decimal numbers"<<endl;

    //use a for loop to store input in array

    for(size_t i=0; i<SIZE;i++){

        cin>>items[i];
    }
    cout<<"The first element is "<<items[0]<<endl;
    cout<<"The fifth element is "<<items[4]<<endl;
    cout<<"The last element is "<<items.back()<<endl;
}
