//Emmanuel Atanga
//09/07/2020

#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;
int main()
{
   //Ratings tracker
   map<string, int> playerInfo;   //Store player names and ratings in a map container.
   string playerName;
   int playerRating;

   cout << "Enter player name (q to quit): ";
   cin >> playerName;
   while(playerName!= "q")
   {
       cout << "Enter rating: ";
       cin >> playerRating;
       playerInfo.insert(pair<string, int>(playerName, playerRating));   //insert player name, player rating rating into map
       cout << "Enter name (q to quit): ";
       cin >> playerName;
   }

   map<string, int>::iterator itr;   //Use iterator to iterate through map
   cout << "Enter player name tp find player (q to quit): ";
   cin >> playerName;
   while(playerName!= "q")
   {
       itr = playerInfo.find(playerName);
       if(itr != playerInfo.end())
           cout << playerName << " has a rating of " << itr->second << endl;
       else
           cout << "Unknown Player" << endl;
       cout << "Enter player name to find player (q to quit): ";
       cin >> playerName;
   }
   cout << "Bye" << endl;
   return 0;
}
