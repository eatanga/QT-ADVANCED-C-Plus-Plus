//Emmanuel Atanga
//09/12/2020
//Parse CSV Purchase Order Assignment


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;


int main()
{
   ifstream inpfile("../PurchaseOrderToCSV/orders.csv");   //open the csv file to read
   string line, cell;
   double totalCost = 0;       //intialize total cost to 0

   while(getline(inpfile, line))   //read each line from the csv
   {
       stringstream stream(line); //convert line into stream in order to  extract each field
       int cellNumber = 0;       //variable to hold the field count for each line initialized to 0
       int qty;
       double Unitprice;
       while(getline(stream, cell, ',')) //extract fields separated by comma
       {
           cellNumber++;
           if(cellNumber == 2){
               qty = atoi(cell.c_str());    //convert string quantity to integer
           }
           if(cellNumber == 3){
               Unitprice = atof(cell.c_str()); //convert unitprice to double/float
           }
       }
       totalCost += (qty * Unitprice);   //add cost to running total cost
   }


   cout << "Total Cost of  purchased Order: $" << totalCost << endl;

   return 0;
}
