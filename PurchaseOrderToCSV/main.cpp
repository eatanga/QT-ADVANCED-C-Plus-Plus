//Emmanuel Atanga
//09/12/2020
//Purchase Order to CSV Assignment

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
   ofstream outfile("../PurchaseOrderToCSV/orders.csv");   //open CSV file to write
   string sku;
   int qty;
   double Unitprice;

   cout << "SKU (q to quit): ";
   cin >> sku;                       //read user sku input
   while(sku != "q"){               //check if user entered q
       cout << "Quantity: ";
       cin >> qty;           //read user input of quantity and price
       cout << "Unit price: ";
       cin >> Unitprice;
       outfile << sku << "," << qty << "," << Unitprice << endl;   //write to file
       cout << "SKU (q to quit): ";
       cin >> sku;                   //read next sku user enters
   }

   return 0;
}
