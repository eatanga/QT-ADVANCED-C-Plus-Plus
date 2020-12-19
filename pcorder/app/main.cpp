//Emmanuel Atanga
//09/25/2020
//PcOrdering Assignment.

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Battery.h"
#include "CPU.h"
#include "Memory.h"
#include "PowerSupply.h"
#include "Screen.h"
#include "Storage.h"
#include "computer.h"
#include "desktop.h"
#include "laptop.h"
#include <fstream>
using namespace std;


//Protoype of method to display menu
void displayMenu();

int main(){

    //declare variables to collect user input
    char item, newItem, choice;
    double total =0;

            // create new instances of the pc header sub classes in the main class
            CPU cpu;
            Memory m;
            Storage s;
            PowerSupply ps;
            Screen sc;
            Battery b;

            cout<<"Enter (A) for desktop and (B) for Laptop"<<endl;
            cin>>choice;

            // Use a switch case loop to get the users choice of pc
            switch(choice){
            case 'a': case 'A':
                cout<<"You  are Ordering a Desktop"<<endl;
                break;
            case 'b' : case 'B':
                cout<<"You are ordering a Laptop"<<endl;
                break;
            default:
                cout<<"Invalid Entry, Please Restart.";
                break;
}
    // Use a do while loop plus switch case loops to collect all user selected components
    //Then use mutators to assign user selections to variables in the classes.
    do
    {

    displayMenu(); // display the menu
    cin>>item;

    switch(item)
    {
    case 'a': case 'A':
    cout<<"You selected Intel Core i9 speed: 2.3GHZ - 5.5GHZ CPU";
    cpu.setName("Intel i9");
    cpu.setSpeed("2.8GHZ");
    cpu.setNumOfCores(9);
    cpu.setPrice(2500);
    break;
    case 'b': case 'B':
    cout<<"You selected Intel Core i7 speed: 1.3GHZ - 3.2GHZ  CPU";
    cpu.setName("Intel i7");
    cpu.setSpeed("2.5GHZ");
    cpu.setNumOfCores(6);
    cpu.setPrice(1000);
    break;
    case 'c': case 'C':
    cout<<"You selected Intel Core i5 speed: 1.1GHZ - 2.5GHZ CPU";
    cpu.setName("Intel i5");
    cpu.setSpeed("2.2GHZ");
    cpu.setNumOfCores(4);
    cpu.setPrice(500);
    break;
    case 'd': case 'D':
    cout<<"You selected Intel Core i3 speed: 1.1GHZ- 2.3GHZ CPU";
    cpu.setName("Intel i3");
    cpu.setSpeed("1.3GHZ");
    cpu.setNumOfCores(4);
    cpu.setPrice(250);
    break;
    case 'e': case 'E':
    cout<<"You selected AMD Ryzen 9 Zen 2 (AMD4) speed:3.2GHZ CPU";
    cpu.setName("AMD Ryzen 9 Zen 2");
    cpu.setSpeed("3.4GHZ");
    cpu.setNumOfCores(8);
    cpu.setPrice(1000);
    break;
    case 'f': case 'F':
    cout<<"You Ordered DDR4-2133 288-pin DIMM 2x4GB Memory";
    m.setClockSpeed("2133MHZ");
    m.setSize("8GB");
    m.setPrice(100);
    break;
    case 'g': case 'G':
    cout<<"You selected DDR4-3000 288-pin DIMM 2x8GB Memory";
    m.setClockSpeed("3000MHZ");
    m.setSize("16GB");
    m.setPrice(250);
    break;
    case 'h': case 'H':
    cout<<"You selected DDR4-3200 288-pin DIMM 2x16GB Memory";
    m.setClockSpeed("3200MHZ");
    m.setSize("32GB");
    m.setPrice(500);
    break;
    case 'i': case 'I':
    cout<<"You selected DDR4-3600 288-pin DIMM 2x8GB Memory";
    m.setClockSpeed("3600MHZ");
    m.setSize("16GB");
    m.setPrice(250);
    break;
    case 'j': case 'J':
    cout<<"You selected DDR4-2800 288-pin DIMM 2x4GB Memory";
    m.setClockSpeed("2800MHZ");
    m.setSize("8GB");
    m.setPrice(100);
    break;
    case 'k': case 'K':
    cout<<"You selected Solid State Drive - 2.5 inches SATA 0.128 TB Storage";
    s.setSize("0.128TB");
    s.setPrice(100);
    break;
    case 'l': case 'L':
    cout<<"You selected Solid State Drive - 2.5inches SATA 0.512 TB Storage";
    s.setSize("0.512TB");
    s.setPrice(250);
    break;
    case 'm': case 'M':
    cout<<"You selected Solid State Drive - 2.5inches SATA 1 TB Storage";
    s.setSize("1TB");
    s.setPrice(500);
    break;
    case 'n': case 'N':
    cout<<"You selected Solid State Drive - 2.5inches SATA 2 TB Storage";
    s.setSize("2TB");
    s.setPrice(1000);
    break;
    case 'o': case 'O':
    cout<<"You Ordered Hard Drive - 3.5 inches SATA 4 TB Storage";
    s.setSize("4TB");
    s.setPrice(250);
    break;
    case 'p': case 'P':
    cout<<"You selected Less than 500W 80+ Bronze Power Supply";
    ps.setRating("300W");
    ps.setPrice(250);
    break;
    case 'q': case 'Q':
    cout<<"You Ordered 500W - 799 80+ bronze Power Supply";
    ps.setRating("650W");
    ps.setPrice(125);
    break;
    case 'r': case 'R':
    cout<<"You selected 800W - 999W 80+ Bronze Power Supply";
    ps.setRating("850W");
    ps.setPrice(500);
    break;
    case 's': case 'S':
    cout<<"You Ordered 1000W - 1199W 80+ Bronze Power Supply";
    ps.setRating("1050W");
    ps.setPrice(250);
    break;
    case 't': case 'T':
    cout<<"You selected 1500W - 2000W 80+ Gold Power Supply";
    ps.setRating("1800W");
    ps.setPrice(500);
    break;
    case 'u': case 'U':
    cout<<"You Ordered 23 - 26 inches, 1920 x 1080 Screen";
    sc.setSize("23 inches");
    sc.setPrice(500);
    break;
    case 'v': case 'V':
    cout<<"You selected 27 - 30 inches, 1920 x 1080 Screen";
    sc.setSize("29 inches");
    sc.setPrice(1000);
    break;
    case 'W': case 'w':
    cout<<"You selected 32+ inches, 3840 x 2160 Screen";
    sc.setSize("55 inches");
    sc.setPrice(3000);
    break;
    case 'x': case 'X':
    cout<<"You selected New Dell Laptop Battery";
    b.setCapacity("3HRS");
    b.setPrice(150);
    break;
    case 'y': case 'Y':
    cout<<"You selected New HP Laptop Battery";
    b.setCapacity("4HRS");
    b.setPrice(350);
    break;
    case 'z': case 'Z':
    cout<<"You selected New Lenovo Laptop Battery";
    b.setCapacity("6HRS");
    b.setPrice(250);
    break;
    default:
    cout<<"Invalid Entry, Please Restart.";
    break;
    }

    cout<<"   Add Another PC Item? Y/N"<<endl;
    cin>>newItem;

    }while(newItem=='Y'||newItem=='y');

    if (newItem=='N' ||newItem=='n')
    {
        //check user choice of PC and build corresponding PC
        if (choice=='a'|| choice=='A'){

            //create a vector of unique pointers of the base class Computer
            vector<unique_ptr<Computer>> pc;
            //create unique pointers to all selected user components
            unique_ptr<CPU> cp = make_unique<CPU>();
            unique_ptr<Memory> me = make_unique<Memory>();
            unique_ptr<Storage> stor = make_unique<Storage>();
            unique_ptr<PowerSupply> power = make_unique<PowerSupply>();

            //Add the components to the vector
            pc.push_back(move(cp));
            pc.push_back(move(me));
            pc.push_back(move(stor));
            pc.push_back(move(power));

            //Use constructor to create a desktop object
           Desktop desk(cpu,m,s,ps);
           //use virtual methods to calculate the total price and the string details
           total = desk.totalPrice();
           string comp = desk.display();

           //Use a loop to iterate though the vector and display the elements
           for (auto& computer : pc)
           {
               cout<<computer->totalPrice()<<endl;
           }

           cout<<"These are your Desktop components:\n"<< comp<<endl;
           cout<<"********************************************"<<endl;
           //display the total price
           cout<<"Total Price for your Desktop is: $"<<total<<endl;


        }else
            if(choice=='b'||choice=='B'){
                vector<Laptop> lapVector = { Laptop(cpu,m,s,sc,b)};
                Laptop lap(cpu,m,s,sc,b);
                total =lap.totalPrice();
                string comp = lap.display();
                 cout<<"These are your Laptop components: "<< comp<<endl;
                 cout<<"Total Price for your Laptop is: $"<<total<<endl;


            }
    cout<<" THANK YOU VERY MUCH! "<<endl;
    }
    else
    {
    cout<<"Invalid Choice, Please Restart";

    }

    return 0;
   }
//*************************************************************************************************
void displayMenu()
{
    cout<<"====================="<<endl;
    cout<<"        PC ORDERING"<<endl;
    cout<<"====================="<<endl;
    cout<<"CPUs:"<<endl;
    cout<<"(A)   Intel Core i9 speed: 2.3GHZ - 5.5GHZ   $2500.00	(D)  Intel Core i3 speed: 1.1GHZ- 2.3GHZ     $250.00"<<endl;
    cout<<"(B)   Intel Core i7 speed: 1.3GHZ - 3.2GHZ   $1000.00	(E)  AMD Ryzen 9 Zen 2 (AMD4) speed:3.2GHZ   $1000.00"<<endl;
    cout<<"(C)   Intel Core i5 speed: 1.1GHZ - 2.5GHZ	$500.00"<<endl;
    cout<<"MEMORY:"<<endl;
    cout<<"(F)   DDR4-2133 288-pin DIMM 2x4GB	$100.00	   (I)   DDR4-3600 288-pin DIMM 2x8GB  $250.00"<<endl;
    cout<<"(G)   DDR4-3000 288-pin DIMM 2x8GB   $250.00	   (J)   DDR4-2800 288-pin DIMM 2x4GB  $100.00"<<endl;
    cout<<"(H)   DDR4-3200 288-pin DIMM 2x16GB  $500.00"<<endl;
    cout<<"STORAGE:"<<endl;
    cout<<"(K)   Solid State Drive - 2.5 inch SATA 0.128 TB  $100.00	  (N) Solid State Drive - 2.5 inch SATA 2 TB   $1000.00"<<endl;
    cout<<"(L)   Solid State Drive - 2.5 inch SATA 0.512 TB  $250.00      (O) Hard Drive - 3.5 inches SATA 4 TB        $250.00"<<endl;
    cout<<"(M)   Solid State Drive - 2.5 inch SATA 1 TB      $500.00"<<endl;
    cout<<"POWER SUPPLY:"<<endl;
    cout<<"(P)   Less than 500W 80+ Bronze $250.00         (S)   1000W - 1199W 80+ Bronze   $250.00"<<endl;
    cout<<"(Q)   500W - 799 80+ bronze     $125.00         (T)   1500W - 2000W 80+ Gold     $500.00"<<endl;
    cout<<"(R)   800W - 999W 80+ Bronze    $500.00"<<endl;
    cout<<"SCREEN & BATTERY:"<<endl;
    cout<<"(U)   23 inches - 26 inches, 1920 x 1080 Screen  $500.00        (X) New Dell Laptop Battery    $150.00"<<endl;
    cout<<"(V)   27 inches - 30 inches , 1920 x 1080 Screen $1000.00       (Y) New HP Laptop Battery      $350.00"<<endl;
    cout<<"(W)   32 inches +, 3840 x 2160 Screen            $3000.00       (Z) New Lenovo Laptop Battery  $250.00"<<endl;

    cout<<"Select a PC Item"<<endl;
}
