//Emmanuel Atanga
//Reference parameter assignment
//10/16/2020

#include <iostream>
using namespace std;

int getNumber(int &num){

    while(true)
    {
        cout<<"Enter a number between 1 and  100\n"<<endl;
        cin>>num;
        if(num >=1 && num <= 100)
            break;
        else
          cout<<"Invalid input. Please try again.\n"<<endl;
    }
    return num;
}

int main(){
    int userInput;
    int result = getNumber(userInput);
    cout<<"You entered "<<result<<endl;
}
