// CSCI 1300 Fall 2022
// Authors: Mariana Vadas-Arendt and Daria Ruchala
// Project 3
 
#include "Action.h"
#include "Merchant.h"
#include "Map.h"
#include "User.h"
#include "Npc.h"
#include "unistd.h"
#include <ctime>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
 
using namespace std;
 
int main()
{
   ifstream fin;
   string line;
   Map map;
   Merchant temp_merchant;
   User temp_user;
   Action temp_action;
   NPC npc;
   while (temp_user.getPlayersFullness(0) > 0 && temp_action.getEndGame() == false && npc.getSuccess() == false)
   {
       fin.open("intro.txt");
       while (!fin.eof()) // continue looping as long as there is data to be processed in the file
       {
           getline(fin, line);
           cout << line << endl;
           sleep(2);
       }
       fin.close();
 
       string player_name;
       string companion1;
       string companion2;
       string companion3;
       string companion4;
       cout << "What is your name?" << endl;
       cin >> player_name;
       cout << "Nice to meet you, " << player_name << "!!" << endl;
       cout << "What is the name of your first companion? (1/4)" << endl;
       cin >> companion1;
       cout <<"Good to have you on board, " << companion1 << "!!" << endl;
       cout << "What is the name of your second companion? (2/4)" << endl;
       cin >> companion2;
       cout << "What a wonderful name, " << companion2 << "!!" << endl;
       cout << "What is the name of your third companion? (3/4)" << endl;
       cin >> companion3;
       cout << "Delighted to make your acquaintance, " << companion3 << "!!" << endl;
       cout << "What is the name of your fourth companion? (4/4)" << endl;
       cin >> companion4;
       cout << "Pleased to meet you, " << companion4 << "!!" << endl;
       temp_user.setPlayers(player_name, companion1, companion2, companion3, companion4);
 
       fin.open("merchant.txt");
       while (!fin.eof()) // continue looping as long as there is data to be processed in the file
       {
           getline(fin, line);
           cout << line << endl;
           sleep(2);
       }
       fin.close();
 
       temp_user.displayMenu(temp_user, temp_merchant, temp_action);
 
       srand(time(0));
       int x;
       int y;
       int count = 0;
 
       //creating rooms
       while (count < 5)
       {
           x = rand() % (12 - 1 + 1) + 1;
           y = rand() % (12 - 1 + 1) + 1;
           while (map.isRoomLocation(x, y) == true)
           {
               x = rand() % (12 - 1 + 1) + 1;
               y = rand() % (12 - 1 + 1) + 1;
           }
           if (map.isRoomLocation(x, y) == false)
           {
               if (map.addRoom(x, y) == true)
               {
                   count++;
               }
           }
       }
      
       count = 0;
       //spawning npc's
       while (count < 5)
       {
           x = rand() % (12 - 1 + 1) + 1;
           y = rand() % (12 - 1 + 1) + 1;
           while (map.isNPCLocation(x, y) == true)
           {
               x = rand() % (12 - 1 + 1) + 1;
               y = rand() % (12 - 1 + 1) + 1;
           }
           if (map.isNPCLocation(x, y) == false)
           {
               if (map.addNPC(x, y) == true)
               {
                   count++;
               }
           }
       }
       Map map1;
       temp_user.displayStatus(temp_user, map, temp_action);
 
       if (temp_user.normalMenu(map, temp_user, temp_action, npc, temp_merchant) == -1)
       {
           break;
       }
   }
   if (temp_action.getEndGame() == true)
   {
       fin.open("goodbye.txt");
       while (!fin.eof()) // continue looping as long as there is data to be processed in the file
       {
           getline(fin, line);
           cout << line << endl;
           sleep(2);
       }
       fin.close();
   }
   else if (npc.getSuccess() == true)
   {
       fin.open("success.txt");
       while (!fin.eof()) // continue looping as long as there is data to be processed in the file
       {
           getline(fin, line);
           cout << line << endl;
           sleep(2);
       }
       fin.close();
   }
 
   int numExplored = 0;
   for (int i = 0; i < 12; i++)
   {
       for (int j = 0; j < 12; j++)
       {
           if (map.isExplored(i, j) == true)
           {
               numExplored++;
           }
       }
   }
   int temp_fullness_array[5];
   string temp_players_names[5];
 
   cout << "+-------------+" << endl;
   cout << "| STATUS      |" << endl;
   cout << "+-------------+" << endl;
   cout << "| Rooms Cleared: " << temp_action.getClearedRooms() << endl;
   cout << "+-------------+" << endl;
   cout << "| # of turns  |" << temp_action.getTurnsElapsed() << endl;
   cout << "+-------------+" << endl;
   cout << "| Amount of   |" << endl;
   cout << "| monsters    |" << temp_action.getMonstersDefeated() << endl;
   cout << "| defeated    |" << endl;
   cout << "+-------------+" << endl;
   cout << "| # of spaces |" << endl;
   cout << "| explored    |" << numExplored << endl;
   cout << "+-------------+" << endl;
   cout << "| INVENTORY   |" << endl;
   cout << "+-------------+" << endl;
   cout << "| Gold        | " << temp_user.getUserGold() << endl;
   cout << "| Treasures   | R: " << temp_user.getUserTreasures(0) << " | N: " << temp_user.getUserTreasures(1) << " | B: " << temp_user.getUserTreasures(2) << " | C: " << temp_user.getUserTreasures(3) << " | G: " << temp_user.getUserTreasures(4) << endl;
   cout << "+-------------+" << endl;
   cout << "| Leader      |" << temp_user.getPlayers(0) << endl;
   cout << "+-------------+" << endl;
   cout << "| PARTY IN     |" << endl;
   cout << "| ORDER OF     |" << endl;
   cout << "| HEALTH, MOST |" << endl;
   cout << "| TO LEAST     |" << endl;
   if (temp_user.getPlayersFullness(0) == temp_user.getPlayersFullness(1) && temp_user.getPlayersFullness(0) == temp_user.getPlayersFullness(2) && temp_user.getPlayersFullness(0) == temp_user.getPlayersFullness(3) && temp_user.getPlayersFullness(0) == temp_user.getPlayersFullness(4))
   {
       cout << "| " << temp_user.getPlayers(0) << " | Fullness: " << temp_user.getPlayersFullness(0) << endl;
       cout << "| " << temp_user.getPlayers(1) << " | Fullness: " << temp_user.getPlayersFullness(1) << endl;
       cout << "| " << temp_user.getPlayers(2) << " | Fullness: " << temp_user.getPlayersFullness(2) << endl;
       cout << "| " << temp_user.getPlayers(3) << " | Fullness: " << temp_user.getPlayersFullness(3) << endl;
       cout << "| " << temp_user.getPlayers(4) << " | Fullness: " << temp_user.getPlayersFullness(4) << endl;
   }
   else
   {
       for (int i = 0; i < 5; i++)
       {
           temp_fullness_array[i] = temp_user.getPlayersFullness(i);
       }
       for (int i = 0; i < 5; i++)
       {
           temp_players_names[i] = temp_user.getPlayers(i);
       }
       int pos = 0;
       string pos2 = "";
       for (int j = 0; j < 5; j++)
       {      
           for (int k = j + 1; k < 5; k++) //traverses through the elements
           {
               if (temp_fullness_array[k] > temp_fullness_array[j]) //checks the numbers with the first number, if the second number is bigger then
               {
                   pos2 = temp_players_names[j]; //stores name in variable
                   pos = temp_fullness_array[j]; //store number in variable
                   temp_players_names[j] = temp_players_names[k]; //switches the names of the numbers
                   temp_fullness_array[j] = temp_fullness_array[k]; //make the smaller number equal to the bigger number
                   temp_players_names[k] = pos2; //puts name back in
                   temp_fullness_array[k] = pos; //put smaller number where bigger number goes
               }
           }
       }
       for (int h = 0; h < 5; h++)
       {
           if (temp_fullness_array[h] > 0)
           {
               cout << "| " << temp_players_names[h] << " | Fullness: " << temp_fullness_array[h] << endl;
           }
       }
   }
   cout << "Total amount of ingredients bought: " << temp_merchant.getIngredients() << endl;
   cout << "Total amount of armor bought: " << temp_merchant.getArmor()<< endl;
   cout << "Total amount of pots bought: " << temp_merchant.getMerchantPot()<< endl;
   cout << "Total amount of pans bought: " << temp_merchant.getMerchantPan()<< endl;
   cout << "Total amount of cauldrons bought: " << temp_merchant.getMerchantCauldron()<< endl;
   cout << "Total amount of clubs bought: " << temp_merchant.getMerchantClub()<< endl;
   cout << "Total amount of spears bought: " << temp_merchant.getMerchantSpear()<< endl;
   cout << "Total amount of rapiers bought: " << temp_merchant.getMerchantRapier()<< endl;
   cout << "Total amount of axes bought: " << temp_merchant.getMerchantAxe()<< endl;
   cout << "Total amount of longswords bought: "<< temp_merchant.getMerchantLongsword()<< endl;
   cout << "Total amount of rings sold: " << temp_merchant.getMerchantRing()<< endl;
   cout << "Total amount of necklaces sold: " << temp_merchant.getMerchantNecklace()<< endl;
   cout << "Total amount of bracelets sold: "<< temp_merchant.getMerchantBracelet() << endl;
   cout << "Total amount of circlets sold: " << temp_merchant.getMerchantCirclet()<< endl;
   cout << "Total amount of goblets sold: " << temp_merchant.getMerchantGoblet()<< endl;
  
   ofstream fout;
   fout.open("results.txt");
   fout << "+-------------+" << endl;
   fout << "| STATUS      |" << endl;
   fout << "+-------------+" << endl;
   fout << "| Rooms Cleared: " << temp_action.getClearedRooms() << endl;
   fout << "+-------------+" << endl;
   fout << "| # of turns  |" << temp_action.getTurnsElapsed() << endl;
   fout << "+-------------+" << endl;
   fout << "| Amount of   |" << endl;
   fout << "| monsters    |" << temp_action.getMonstersDefeated() << endl;
   fout << "| defeated    |" << endl;
   fout << "+-------------+" << endl;
   fout << "| # of spaces |" << endl;
   fout << "| explored    |" << numExplored << endl;
   fout << "+-------------+" << endl;
   fout << "| INVENTORY   |" << endl;
   fout << "+-------------+" << endl;
   fout << "| Gold        | " << temp_user.getUserGold() << endl;
   fout << "| Treasures   | R: " << temp_user.getUserTreasures(0) << " | N: " << temp_user.getUserTreasures(1) << " | B: " << temp_user.getUserTreasures(2) << " | C: " << temp_user.getUserTreasures(3) << " | G: " << temp_user.getUserTreasures(4) << endl;
   fout << "+-------------+" << endl;
   fout << "| Leader       |" << temp_user.getPlayers(0) << endl;
   fout << "+-------------+" << endl;
   fout << "| PARTY IN     |" << endl;
   fout << "| ORDER OF     |" << endl;
   fout << "| HEALTH, MOST |" << endl;
   fout << "| TO LEAST     |" << endl;
   if (temp_user.getPlayersFullness(0) == temp_user.getPlayersFullness(1) && temp_user.getPlayersFullness(0) == temp_user.getPlayersFullness(2) && temp_user.getPlayersFullness(0) == temp_user.getPlayersFullness(3) && temp_user.getPlayersFullness(0) == temp_user.getPlayersFullness(4))
   {
       fout << "| " << temp_user.getPlayers(0) << " | Fullness: " << temp_user.getPlayersFullness(0) << endl;
       fout << "| " << temp_user.getPlayers(1) << " | Fullness: " << temp_user.getPlayersFullness(1) << endl;
       fout << "| " << temp_user.getPlayers(2) << " | Fullness: " << temp_user.getPlayersFullness(2) << endl;
       fout << "| " << temp_user.getPlayers(3) << " | Fullness: " << temp_user.getPlayersFullness(3) << endl;
       fout << "| " << temp_user.getPlayers(4) << " | Fullness: " << temp_user.getPlayersFullness(4) << endl;
   }
   else
   {
       for (int i = 0; i < 5; i++)
       {
           temp_fullness_array[i] = temp_user.getPlayersFullness(i);
       }
       for (int i = 0; i < 5; i++)
       {
           temp_players_names[i] = temp_user.getPlayers(i);
       }
       int pos = 0;
       string pos2 = "";
       for (int j = 0; j < 5; j++)
       {      
           for (int k = j + 1; k < 5; k++) //traverses through the elements
           {
               if (temp_fullness_array[k] > temp_fullness_array[j]) //checks the numbers with the first number, if the second number is bigger then
               {
                   pos2 = temp_players_names[j]; //stores name in variable
                   pos = temp_fullness_array[j]; //store number in variable
                   temp_players_names[j] = temp_players_names[k]; //switches the names of the numbers
                   temp_fullness_array[j] = temp_fullness_array[k]; //make the smaller number equal to the bigger number
                   temp_players_names[k] = pos2; //puts name back in
                   temp_fullness_array[k] = pos; //put smaller number where bigger number goes
               }
           }
       }
       for (int h = 0; h < 5; h++)
       {
           if (temp_fullness_array[h] > 0)
           {
               fout << "| " << temp_players_names[h] << " | Fullness: " << temp_fullness_array[h] << endl;
           }
       }
   }
   fout << "Total amount of ingredients bought: " << temp_merchant.getIngredients() << endl;
   fout << "Total amount of armor bought: " << temp_merchant.getArmor()<< endl;
   fout << "Total amount of pots bought: " << temp_merchant.getMerchantPot()<< endl;
   fout << "Total amount of pans bought: " << temp_merchant.getMerchantPan()<< endl;
   fout << "Total amount of cauldrons bought: " << temp_merchant.getMerchantCauldron()<< endl;
   fout << "Total amount of clubs bought: " << temp_merchant.getMerchantClub()<< endl;
   fout << "Total amount of spears bought: " << temp_merchant.getMerchantSpear()<< endl;
   fout << "Total amount of rapiers bought: " << temp_merchant.getMerchantRapier()<< endl;
   fout << "Total amount of axes bought: " << temp_merchant.getMerchantAxe()<< endl;
   fout << "Total amount of longswords bought: "<< temp_merchant.getMerchantLongsword()<< endl;
   fout << "Total amount of rings sold: " << temp_merchant.getMerchantRing()<< endl;
   fout << "Total amount of necklaces sold: " << temp_merchant.getMerchantNecklace()<< endl;
   fout << "Total amount of bracelets sold: "<< temp_merchant.getMerchantBracelet() << endl;
   fout << "Total amount of circlets sold: " << temp_merchant.getMerchantCirclet()<< endl;
   fout << "Total amount of goblets sold: " << temp_merchant.getMerchantGoblet()<< endl;
 
   fout.close();
}