// CSCI 1300 Fall 2022
// Authors: Mariana Vadas-Arendt and Daria Ruchala
// Project 3
 
#include <iostream>
#include "unistd.h"
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <ctime>
#include "User.h"
 
using namespace std;
 
User::User() //Sets both num_posts_ and num_users_ to value 0
{
    for (int i = 0; i < 5; i++)
    {
        fullness[i] = 50;
    }
    key = 0;
    angerLevel = 0;
    gold = 100; 
    ingredients = 0; 
    armor = 0; 
    for (int i = 0; i < 3; i++)
    {
        cookware[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        weapons[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        treasures[i] = 0;
    }
}
User::User(int fullness_[], string players_[], int key_, int angerLevel_, double gold_, int ingredients_, int armor_, int cookware_[], int weapons_[], int treasures_[])
{
    for (int i = 0; i < 5; i++)
    {
        fullness[i] = fullness_[i];
    }
    for (int i = 0; i < 5; i++)
    {
        playerobj[i].setName(players_[i]);
    }
    key = key_;
    angerLevel = angerLevel_;
    gold = gold_;
    ingredients = ingredients_;
    armor = armor_;
    for (int i = 0; i < 3; i++)
    {
        cookware[i] = cookware_[i];
    }
    for (int i = 0; i < 5; i++)
    {
        weapons[i] = weapons_[i];
    }
    for (int i = 0; i < 5; i++)
    {
        treasures[i] = treasures_[i];
    }
}
string User::getPlayers(int type)
{
    return playerobj[type].getName();
}
void User::setPlayers(string player, string companion1, string companion2, string companion3, string companion4)
{
    playerobj[0].setName(player);
    playerobj[1].setName(companion1);
    playerobj[2].setName(companion2);
    playerobj[3].setName(companion3);
    playerobj[4].setName(companion4);
}
int User::getPlayersFullness(int type)
{
   return fullness[type];
}
void User::setPlayersFullness(int player, int companion1, int companion2, int companion3, int companion4)
{
   fullness[0] = player;
   fullness[1] = companion1;
   fullness[2] = companion2;
   fullness[3] = companion3;
   fullness[4] = companion4;
}
int User::getUserKey()
{
    return key;
}
void User::setUserKey(int key_)
{
    key = key_;
}
int User::getAngerLevel()
{
    return angerLevel;
}
void User::setAngerLevel(int angerLevel_)
{
    angerLevel = angerLevel_;
}
double User::getUserGold()
{
    return gold;
}
void User::setUserGold(double gold_)
{
    gold = gold_;
}
int User::getUserIngredients()
{
    return ingredients;
}
void User::setUserIngredients(int ingredients_)
{
    ingredients = ingredients_;
}
int User::getUserArmor()
{
    return armor;
}
void User::setUserArmor(int armor_)
{
    armor = armor_;
}
int User::getUserCookware(int type)
{
    return cookware[type];
}
void User::setUserCookware(int pot, int pan, int cauldron)
{
    cookware[0] = pot;
    cookware[1] = pan;
    cookware[2] = cauldron;
}
int User::getUserWeapons(int type)
{
    return weapons[type];
}
void User::setUserWeapons(int club, int spear, int rapier, int axe, int longsword)
{
    weapons[0] = club;
    weapons[1] = spear;
    weapons[2] = rapier;
    weapons[3] = axe;
    weapons[4] = longsword;
}
int User::getUserTreasures(int type)
{
    return treasures[type];
}
void User::setUserTreasures(int ring, int necklace, int bracelet, int circlet, int goblet)
{
    treasures[0] = ring;
    treasures[1] = necklace;
    treasures[2] = bracelet;
    treasures[3] = circlet;
    treasures[4] = goblet;
}
bool User::potBreak()
{
    srand(time(0));
    if ((rand() % (4 - 1 + 1) + 1) % 4 == 0)
    {
        int num_pot = cookware[0] - 1;
        setUserCookware(num_pot, cookware[1], cookware[2]);
        return true;
    }
    return false;
}
bool User::panBreak()
{
    //run a random number checker between 1 and 100 and if the number modulo 10 is 0 then the pan will break
    //if pan breaks then subtract one from pan count in merchant and user class
    //if the number modulo 10 is not 0 then the pan will not break
    srand(time(0));
    if ((rand() % (100 - 1 + 1) + 1) < 10)
    {
        int num_pan = cookware[1] - 1;
        setUserCookware(cookware[0], num_pan, cookware[2]);
        return true;
    }
    return false;
}
bool User::cauldronBreak()
{
    //run a random number checker between 1 and 20 and if the number modulo 10 is 0 then the cauldron will break
    //if cauldron breaks then subtract one from cauldron count in merchant and user class
    //if the number modulo 10 is not 0 then the cauldron will not break
    srand(time(0));
    if ((rand() % (100 - 1 + 1) + 1) % 50 == 0)
    {
        int num_cauldron = cookware[2] - 1;
        setUserCookware(cookware[0], cookware[1], num_cauldron);
 
        return true;
    }
    return false;
}
//--------------------------------------------------------------------------------------------------
int User::displayStatus(User &temp_user, Map &map, Action &temp_action)
{
    
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << temp_action.getClearedRooms() << " | Keys: " << temp_user.getUserKey() << "| Anger Level: " << temp_user.getAngerLevel() << endl;
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << temp_user.getUserGold() << endl;
    cout << "| Ingredients | " << temp_user.getUserIngredients() << " kg" << endl;
    cout << "| Cookware    | P: " << temp_user.getUserCookware(0) << " | F: " << temp_user.getUserCookware(1) << " | C: " << temp_user.getUserCookware(2) << endl;
    cout << "| Weapons     | C: " << temp_user.getUserWeapons(0) << " | S: " << temp_user.getUserWeapons(1) << " | R: " << temp_user.getUserWeapons(2) << " | B: " << temp_user.getUserWeapons(3) << " | L: " << temp_user.getUserWeapons(4) << endl;
    cout << "| Armor       | " << temp_user.getUserArmor() << endl;
    cout << "| Treasures   | R: " << temp_user.getUserTreasures(0) << " | N: " << temp_user.getUserTreasures(1) << " | B: " << temp_user.getUserTreasures(2) << " | C: " << temp_user.getUserTreasures(3) << " | G: " << temp_user.getUserTreasures(4) << endl;
    cout << "+-------------+" << endl;
    cout << "| PARTY       |" << endl;
    cout << "+-------------+" << endl;
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
        /**
         * sorting function psuedo code
         * bubble sort, used https://visualgo.net/en/sorting for help visualizing
         * have an outer for loop that traverses through the elements
         * have an inner for loop that traverses through the elements plus one 
         * check if the inner for loop number is bigger than the outer for loop number
         * if so swap the two by storing the smaller number in a variable to hold
         * then make the bigger number equal to the smaller number position and put the smaller number in the former bigger number pos
         */
        int temp_fullness_array[5];
        string temp_players_names[5];
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
    cout << "+-------------+" << endl;
    map.displayMap();
    return 1;
}
//--------------------------------------------------------------------------------------------------
int User::cooking(User &temp_user, Action &temp_action)
{
  int decision = 0;
  int ingredients = 0;
   cout << "Which cookware did you want to use?" << endl;
  sleep(1);
  cout << "(1) Pot" << endl;
  sleep(1);
  cout << "(2) Pan" << endl;
  sleep(1);
  cout << "(3) Cauldron" << endl;
  sleep(1);
  cout << "(4) Cancel" << endl;
  cin >> decision;
   while (decision != 4)
  {  
      cout << "How many ingredients did you want to use? (increment of 5) or 0 to cancel" << endl;
      cin >> ingredients;
      while (ingredients > temp_user.getUserIngredients() || ingredients < 0 || ingredients % 5 != 0)
      {
          cout << "You don't have that many ingredients, please try again or 0 to cancel" << endl;
          cout << "You have " << temp_user.getUserIngredients() << " kg of ingredients" << endl;
          cin >> ingredients;
          if (ingredients == 0)
          {
              break;
          }
      }
      if (decision == 1) //pot
      {
          if (temp_user.getUserCookware(0) == 0)
          {
              cout << "You don't have any pots" << endl;
              break;
          }
          else
          {
              temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1); //update that they took a turn
              bool outcome = temp_user.potBreak();
              if (outcome == true) //if the pot breaks
              {
                  int num_ingredients = 0;
                  num_ingredients = temp_user.getUserIngredients() - ingredients;
                  temp_user.setUserIngredients(num_ingredients);
                  cout << "Uh oh, your pot has broken." << endl;
                  cout << "Your pot and ingredients have been lost" << endl;
              }
              else
              {
                  cout << "Cooking was successful!" << endl;
                  cout << "Lovely meal and everyones health went up!" << endl;
                  int setIngredients = temp_user.getUserIngredients() - ingredients;
                  temp_user.setUserIngredients(setIngredients); //makes sure the new ingredients ate stored
                  int num = 0;
                  num = ingredients / 5;
                  int firstPlayer = 0;
                  int secondPlayer = 0;
                  int thirdPlayer = 0;
                  int fourthPlayer = 0;
                  int fifthPlayer = 0;
                   if (temp_user.getPlayersFullness(0) + num > 50)
                  {
                      firstPlayer= 50;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(0) != 0) //if they are not dead
                      {
                          firstPlayer = temp_user.getPlayersFullness(0) + num;
                      }
                      else
                      {
                          firstPlayer = 0;
                      }
                  }
                  if (temp_user.getPlayersFullness(1) + num > 50) //updates the player to have full fullness again
                  {
                      secondPlayer= 50;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(1) != 0)
                      {
                          secondPlayer = temp_user.getPlayersFullness(1) + num;
                      }
                      else
                      {
                          secondPlayer = 0;
                      }
                  }
                  if (temp_user.getPlayersFullness(2) + num > 50)
                  {
                     thirdPlayer= 50;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(2) != 0)
                      {
                          thirdPlayer = temp_user.getPlayersFullness(2) + num;
                      }
                      else
                      {
                          thirdPlayer = 0;
                      }
                  }
                  if (temp_user.getPlayersFullness(3) + num > 50)
                  {
                      thirdPlayer= 50;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(3) != 0)
                      {
                          fourthPlayer = temp_user.getPlayersFullness(3) + num;
                      }
                      else
                      {
                          fourthPlayer = 0;
                      }
                  }
                  if (temp_user.getPlayersFullness(4) + num > 50)
                  {
                      fifthPlayer= 50;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(4) != 0)
                      {
                          fifthPlayer = temp_user.getPlayersFullness(4) + num;
                      }
                      else
                      {
                          fifthPlayer = 0;
                      }
                  }
                  temp_user.setPlayersFullness(firstPlayer, secondPlayer, thirdPlayer, fourthPlayer, fifthPlayer);
              }
          }
      }
      else if (decision == 2)//pan
      {
          if (temp_user.getUserCookware(1) == 0)
          {
              cout << "You don't have any pans" << endl;
              break;
          }
          else
          {
              temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
              bool outcome = temp_user.panBreak(); //calls the pan breaking function
              if (outcome == true)
              {
                  int num_ingredients = 0;
                  num_ingredients = temp_user.getUserIngredients() - ingredients;
                  temp_user.setUserIngredients(num_ingredients);
                  cout << "Uh oh, your pot has broken." << endl;
                  cout << "Your pot and ingredients have been lost" << endl;
              }
              else
              {
                  cout << "Cooking was successful!" << endl;
                  cout << "Lovely meal and everyones health went up!" << endl;
                  int setIngredients = temp_user.getUserIngredients() - ingredients; //ingredients user has - the ingredients bought
                  temp_user.setUserIngredients(setIngredients);
                  int num = 0;
                  num = ingredients / 5;
                  int firstPlayer = 0;
                  int secondPlayer = 0;
                  int thirdPlayer = 0;
                  int fourthPlayer = 0;
                  int fifthPlayer = 0;
                  if (temp_user.getPlayersFullness(0) + num > 50)
                  {
                      int extra = 0;
                      extra = temp_user.getPlayersFullness(0) + num;
                      extra = extra - 50;
                      firstPlayer = temp_user.getPlayersFullness(0) + num;
                      firstPlayer = firstPlayer - extra;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(0) != 0)
                      {
                          firstPlayer = temp_user.getPlayersFullness(0) + num;
                      }
                      else
                      {
                          firstPlayer = 0;
                      }
                  }
                  if (temp_user.getPlayersFullness(1) + num > 50)
                  {
                      int extra = 0;
                      extra = temp_user.getPlayersFullness(1) + num;
                      extra = extra - 50;
                      secondPlayer = temp_user.getPlayersFullness(1) + num;
                      secondPlayer = secondPlayer - extra;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(1) != 0)
                      {
                          firstPlayer = temp_user.getPlayersFullness(1) + num;
                      }
                      else
                      {
                          firstPlayer = 0;
                      }
                  }
                  if (temp_user.getPlayersFullness(2) + num > 50)
                  {
                      int extra = 0;
                      extra = temp_user.getPlayersFullness(2) + num;
                      extra = extra - 50;
                      thirdPlayer = temp_user.getPlayersFullness(2) + num;
                      thirdPlayer = thirdPlayer - extra;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(2) != 0)
                      {
                          firstPlayer = temp_user.getPlayersFullness(2) + num;
                      }
                      else
                      {
                          firstPlayer = 0;
                      }
                  }
                  if (temp_user.getPlayersFullness(3) + num > 50)
                  {
                      int extra = 0;
                      extra = temp_user.getPlayersFullness(3) + num;
                      extra = extra - 50;
                      fourthPlayer = temp_user.getPlayersFullness(3) + num;
                      fourthPlayer = fourthPlayer - extra;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(3) != 0)
                      {
                          firstPlayer = temp_user.getPlayersFullness(3) + num;
                      }
                      else
                      {
                          firstPlayer = 0;
                      }
                  }
                  if (temp_user.getPlayersFullness(4) + num > 50)
                  {
                      int extra = 0;
                      extra = temp_user.getPlayersFullness(4) + num;
                      extra = extra - 50;
                      fifthPlayer = temp_user.getPlayersFullness(4) + num;
                      fifthPlayer = fifthPlayer - extra;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(4) != 0)
                      {
                          firstPlayer = temp_user.getPlayersFullness(4) + num;
                      }
                      else
                      {
                          firstPlayer = 0;
                      }
                  }
                  temp_user.setPlayersFullness(firstPlayer, secondPlayer, thirdPlayer, fourthPlayer, fifthPlayer);
              }
          }
      }
      else if (decision == 3)//cauldron
      {
          if (temp_user.getUserCookware(2) == 0)
          {
              cout << "You don't have any cauldrons" << endl;
              break;
          }
          else
          {
              temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
              bool outcome = temp_user.cauldronBreak();
              if (outcome == true)
              {
                  int num_ingredients = 0;
                  num_ingredients = temp_user.getUserIngredients() - ingredients;
                  temp_user.setUserIngredients(num_ingredients);
                  cout << "Uh oh, your pot has broken." << endl;
                  cout << "Your pot and ingredients have been lost" << endl;
              }
              else
              {
                  cout << "Cooking was successful!" << endl;
                  cout << "Lovely meal and everyones health went up!" << endl;
                  int setIngredients = temp_user.getUserIngredients() - ingredients;
                  temp_user.setUserIngredients(setIngredients);
                  int num = 0;
                  num = ingredients / 5;
                  int firstPlayer = 0;
                  int secondPlayer = 0;
                  int thirdPlayer = 0;
                  int fourthPlayer = 0;
                  int fifthPlayer = 0;
                  if (temp_user.getPlayersFullness(0) + num > 50)
                  {
                      int extra = 0;
                      extra = temp_user.getPlayersFullness(0) + num;
                      extra = extra - 50;
                      firstPlayer = temp_user.getPlayersFullness(0) + num;
                      firstPlayer = firstPlayer - extra;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(0) != 0)
                      {
                          firstPlayer = temp_user.getPlayersFullness(0) + num;
                      }
                      else
                      {
                          firstPlayer = 0;
                      }
                  }
                  if (temp_user.getPlayersFullness(1) + num > 50)
                  {
                      int extra = 0;
                      extra = temp_user.getPlayersFullness(1) + num;
                      extra = extra - 50;
                      secondPlayer = temp_user.getPlayersFullness(1) + num;
                      secondPlayer = secondPlayer - extra;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(1) != 0)
                      {
                          firstPlayer = temp_user.getPlayersFullness(1) + num;
                      }
                      else
                      {
                          firstPlayer = 0;
                      }
                  }
                  if (temp_user.getPlayersFullness(2) + num > 50)
                  {
                      int extra = 0;
                      extra = temp_user.getPlayersFullness(2) + num;
                      extra = extra - 50;
                      thirdPlayer = temp_user.getPlayersFullness(2) + num;
                      thirdPlayer = thirdPlayer - extra;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(2) != 0)
                      {
                          firstPlayer = temp_user.getPlayersFullness(2) + num;
                      }
                      else
                      {
                          firstPlayer = 0;
                      }
                  }
                  if (temp_user.getPlayersFullness(3) + num > 50)
                  {
                      int extra = 0;
                      extra = temp_user.getPlayersFullness(3) + num;
                      extra = extra - 50;
                      fourthPlayer = temp_user.getPlayersFullness(3) + num;
                      fourthPlayer = fourthPlayer - extra;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(3) != 0)
                      {
                          firstPlayer = temp_user.getPlayersFullness(3) + num;
                      }
                      else
                      {
                          firstPlayer = 0;
                      }
                  }
                  if (temp_user.getPlayersFullness(4) + num > 50)
                  {
                      int extra = 0;
                      extra = temp_user.getPlayersFullness(4) + num;
                      extra = extra - 50;
                      fifthPlayer = temp_user.getPlayersFullness(4) + num;
                      fifthPlayer = fifthPlayer - extra;
                  }
                  else
                  {
                      if (temp_user.getPlayersFullness(4) != 0)
                      {
                          firstPlayer = temp_user.getPlayersFullness(4) + num;
                      }
                      else
                      {
                          firstPlayer = 0;
                      }
                  }
                  temp_user.setPlayersFullness(firstPlayer, secondPlayer, thirdPlayer, fourthPlayer, fifthPlayer);
              }
          }
      }
      else
      {
          cout << "Invalid input, please try again" << endl;
          cin >> decision;
      }
      cout << "+-------------+" << endl;
      cout << "| STATUS      |" << endl;
      cout << "+-------------+" << endl;
      cout << "| Ingredients | " << temp_user.getUserIngredients() << " kg" << endl;
      cout << "| Cookware    | P: " << temp_user.getUserCookware(0) << " | F: " << temp_user.getUserCookware(1) << " | C: " << temp_user.getUserCookware(2) << endl;
      cout << "+-------------+" << endl;
      cout << "| PARTY       |" << endl;
      cout << "+-------------+" << endl;
      cout << "| " << temp_user.getPlayers(0) << " | Fullness: " << temp_user.getPlayersFullness(0) << endl;
      cout << "| " << temp_user.getPlayers(1) << " | Fullness: " << temp_user.getPlayersFullness(1) << endl;
      cout << "| " << temp_user.getPlayers(2) << " | Fullness: " << temp_user.getPlayersFullness(2) << endl;
      cout << "| " << temp_user.getPlayers(3) << " | Fullness: " << temp_user.getPlayersFullness(3) << endl;
      cout << "| " << temp_user.getPlayers(4) << " | Fullness: " << temp_user.getPlayersFullness(4) << endl;
      cout << "+-------------+" << endl;
      return 1;
  }
  cout << "Exiting cooking menu" << endl;
  return 1;
}

//------------------------------------------------------------------------------------------------------------
 
int User::misfortunes(User &temp_user, Action &temp_action)
{
   srand(time(0));
   if ((rand() % (80 - 1 + 1) + 1) % 4 < 32) //if its less than 32 it will be 40%
   {
       if ((rand() % (80 - 1 + 1) + 1) % 4 < 24) //if its less than 24 it will be a 30%
       {
           int choice = (rand() % (3 - 1 + 1) + 1);
           if (choice == 1) //player loses ingredients
           {
               if (temp_user.getUserIngredients() > 10) //if user has more than 10 ingredients they will lose them
               {
                   temp_user.setUserIngredients(temp_user.getUserIngredients() - 10);
               }
               else if (temp_user.getUserIngredients() <= 10) //if user has less than 10 they will will just have zero in the end
               {
                   temp_user.setUserIngredients(0);
               }
               cout << "You lost 10 kg of ingredients!" << endl;
           }
           else if (choice == 2) //player loses cookware
           {
               int cookware = (rand() % (3 - 1 + 1) + 1);
               if (cookware == 1)
               {
                   if (temp_user.getUserCookware(0) >= 1)
                   {
                       temp_user.setUserCookware(temp_user.getUserCookware(0) - 1, temp_user.getUserCookware(1), temp_user.getUserCookware(2)); //takes the position 0 and subtracts one which would be pot
                   }
                   else
                   {
                       temp_user.setUserCookware(temp_user.getUserCookware(0), temp_user.getUserCookware(1), temp_user.getUserCookware(2));
                   }
                   cout << "You lost one pot!" << endl;
               }
               else if (cookware == 2)
               {
                   if (temp_user.getUserCookware(1) >= 1)
                   {
                       temp_user.setUserCookware(temp_user.getUserCookware(0), temp_user.getUserCookware(1) - 1, temp_user.getUserCookware(2));
                   }
                   else
                   {
                       temp_user.setUserCookware(temp_user.getUserCookware(0), temp_user.getUserCookware(1), temp_user.getUserCookware(2));
                   }
                   cout << "You lost one pan!" << endl;
               }
               else
               {
                   if (temp_user.getUserCookware(2) >= 1)
                   {
                       temp_user.setUserCookware(temp_user.getUserCookware(0), temp_user.getUserCookware(1), temp_user.getUserCookware(2) - 1);
                   }
                   else
                   {
                       temp_user.setUserCookware(temp_user.getUserCookware(0), temp_user.getUserCookware(1), temp_user.getUserCookware(2));
                   }
                   cout << "You lost one cauldron!" << endl;
               }
           }
           else
           {
               if (temp_user.getUserArmor() >= 1)
               {
                   temp_user.setUserArmor(temp_user.getUserArmor() - 1);
               }
               else
               {
                   temp_user.setUserArmor(0);
               }
               cout << "You lost one piece of armor!" << endl;
           }
       }
       else if ((rand() % (80 - 1 + 1) + 1) % 4 < 8) //genrates a 10% chence of losing armor or weapons
       {
           int choice = (rand() % (2 - 1 + 1) + 1);
           if (choice == 1) //armor
           {
               if (temp_user.getUserArmor() >= 1)
               {
                   temp_user.setUserArmor(temp_user.getUserArmor() - 1);
               }
               else
               {
                   temp_user.setUserArmor(0);
               }
               cout << "You lost one piece of armor!" << endl;
           }
           else if (choice == 2) //weapons
           {
               int weapons = (rand() % (5 - 1 + 1) + 1);
               if (weapons == 1) //club
               {
                   if (temp_user.getUserWeapons(0) >= 1)
                   {
                       temp_user.setUserWeapons(temp_user.getUserWeapons(0) - 1, temp_user.getUserWeapons(1), temp_user.getUserWeapons(2), temp_user.getUserWeapons(3), temp_user.getUserWeapons(4));
                   }
                   else
                   {
                       temp_user.setUserWeapons(temp_user.getUserWeapons(0), temp_user.getUserWeapons(1), temp_user.getUserWeapons(2), temp_user.getUserWeapons(3), temp_user.getUserWeapons(4));
                   }
                   cout << "Oops! You lost one stone club!" << endl;
               }
               else if (weapons == 2) //spear
               {
                   if (temp_user.getUserWeapons(1) >= 1)
                   {
                       temp_user.setUserWeapons(temp_user.getUserWeapons(0), temp_user.getUserWeapons(1) - 1, temp_user.getUserWeapons(2), temp_user.getUserWeapons(3), temp_user.getUserWeapons(4));
                   }
                   else
                   {
                       temp_user.setUserWeapons(temp_user.getUserWeapons(0), temp_user.getUserWeapons(1), temp_user.getUserWeapons(2), temp_user.getUserWeapons(3), temp_user.getUserWeapons(4));
                   }
                   cout << "Oops! You lost one iron spear!" << endl;
               }
               else if (weapons == 3) //rapier
               {
                   if (temp_user.getUserWeapons(2) >= 1)
                   {
                       temp_user.setUserWeapons(temp_user.getUserWeapons(0), temp_user.getUserWeapons(1), temp_user.getUserWeapons(2) - 1, temp_user.getUserWeapons(3), temp_user.getUserWeapons(4));
                   }
                   else
                   {
                       temp_user.setUserWeapons(temp_user.getUserWeapons(0), temp_user.getUserWeapons(1), temp_user.getUserWeapons(2), temp_user.getUserWeapons(3), temp_user.getUserWeapons(4));
                   }
                   cout << "Oops! You lost one (+1) Mythril Rapier!" << endl;
               }
               else if (weapons == 4) //axe
               {
                   if (temp_user.getUserWeapons(3) >= 1)
                   {
                       temp_user.setUserWeapons(temp_user.getUserWeapons(0), temp_user.getUserWeapons(1), temp_user.getUserWeapons(2), temp_user.getUserWeapons(3) - 1, temp_user.getUserWeapons(4));
                   }
                   else
                   {
                       temp_user.setUserWeapons(temp_user.getUserWeapons(0), temp_user.getUserWeapons(1), temp_user.getUserWeapons(2), temp_user.getUserWeapons(3), temp_user.getUserWeapons(4));
                   }
                   cout << "Oops! You lost one (+2) Flaming Battle-Axe!" << endl;
               }
               else if (weapons == 5) //longsword
               {
                   if (temp_user.getUserWeapons(4) >= 1)
                   {
                       temp_user.setUserWeapons(temp_user.getUserWeapons(0), temp_user.getUserWeapons(1), temp_user.getUserWeapons(2), temp_user.getUserWeapons(3), temp_user.getUserWeapons(4) - 1);
                   }
                   else
                   {
                       temp_user.setUserWeapons(temp_user.getUserWeapons(0), temp_user.getUserWeapons(1), temp_user.getUserWeapons(2), temp_user.getUserWeapons(3), temp_user.getUserWeapons(4));
                   }
                   cout << "Oops! You lost one (+3) Vorpal Longsword!" << endl;
               }
           }
       }
       else if ((rand() % (80 - 1 + 1) + 1) % 4 < 24) //food posioning 30% chance of player dying
       {
           int full = 0;
           for (int i = 0; i < 5; i++) //checking that players are still full
           {
               if (temp_user.getPlayersFullness(i) > 0)
               {
                   full++;
               }
           }
           int count = 0;
           for (int i = 0; i < 5; i++)
           {
               if (temp_user.getPlayersFullness(i) > 0)
               {
                   count++;
               }
           }
           if (full > 2)
           {
               int choice = (rand() % (count - 1 + 1) + 1);
               if (choice == 1) //player 0 loses 10 points
               {
                   if (temp_user.getPlayersFullness(0) > 10)
                   {
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0) - 10, temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                       if (temp_user.getPlayersFullness(0) == 1)
                       {
                           cout << temp_user.getPlayers(0) << " is on the brink of starvation!" << endl;
                       }
                   }
                   else if (temp_user.getPlayersFullness(0) <= 10)
                   {
                       temp_user.setPlayersFullness(0, temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                       cout << temp_user.getPlayers(0) << " has died!" << endl;
                       full = full - 1;
                       if (full < 2)
                       {
                           cout << "You have died and cannot continue:( " << endl;
                           temp_action.setEndGame(true);
                           return -1;
                       }
                   }
               }
               else if (choice == 2) //player 1 loses 10 points
               {
                   if (temp_user.getPlayersFullness(1) > 10)
                   {
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1) - 10, temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                       if (temp_user.getPlayersFullness(1) == 1)
                       {
                           cout << temp_user.getPlayers(1) << " is on the brink of starvation!" << endl;
                       }
                   }
                   else if (temp_user.getPlayersFullness(1) <= 10)
                   {
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), 0, temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                       cout << temp_user.getPlayers(1) << " has died!" << endl;
                       full = full - 1;
                       if (full < 2)
                       {
                           cout << "You have too little players to continue sadly, you have failed :( " << endl;
                           temp_action.setEndGame(true);
                           return -1;
                       }
                   }
               }
               else if (choice == 3) //player 2 loses 10 points
               {
                   if (temp_user.getPlayersFullness(2) > 10)
                   {
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2) - 10, temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                       if (temp_user.getPlayersFullness(2) == 1)
                       {
                           cout << temp_user.getPlayers(2) << " is on the brink of starvation!" << endl;
                       }
                   }
                   else if (temp_user.getPlayersFullness(2) <= 10)
                   {
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), 0, temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                       cout << temp_user.getPlayers(2) << " has died!" << endl;
                       full = full - 1;
                       if (full < 2)
                       {
                           cout << "You have too little players to continue sadly, you have failed :( " << endl;
                           temp_action.setEndGame(true);
                           return -1;
                       }
                   }
               }
               else if (choice == 4) //player 3 loses 10 points
               {
                   if (temp_user.getPlayersFullness(3) > 10)
                   {
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3) - 10, temp_user.getPlayersFullness(4));
                       if (temp_user.getPlayersFullness(3) == 1)
                       {
                           cout << temp_user.getPlayers(3) << " is on the brink of starvation!" << endl;
                       }
                   }
                   else if (temp_user.getPlayersFullness(3) <= 10)
                   {
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), 0, temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                       cout << temp_user.getPlayers(3) << " has died!" << endl;
                       full = full - 1;
                       if (full < 2)
                       {
                           cout << "You have too little players to continue sadly, you have failed :( " << endl;
                           temp_action.setEndGame(true);
                           return -1;
                       }
                   }
               }
               else if (choice == 5) //player 4 loses 10 points
               {
                   if (temp_user.getPlayersFullness(4) > 10)
                   {
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4) - 10);
                       if (temp_user.getPlayersFullness(4) == 1)
                       {
                           cout << temp_user.getPlayers(4) << " is on the brink of starvation!" << endl;
                       }
                   }
                   else if (temp_user.getPlayersFullness(4) <= 10)
                   {
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), 0);
                       cout << temp_user.getPlayers(4) << " has died!" << endl;
                       full = full - 1;
                       if (full < 2) //there is less than 2 players therefore end game
                       {
                           cout << "You have too little players to continue sadly, you have failed :( " << endl;
                           temp_action.setEndGame(true);
                           return -1;
                       }
                   }
               }
           }
       }
   }
   if (temp_action.getEndGame() == true)
   {
       return -1;
   }
   else
   {
       return 1;
   }
}
int User::investigateChances(User &temp_user, Map &map, Action &temp_action) //pass by value makes sure the values in these variables is updated
{
   int count2 = 0;
   int fight = 0;
   srand(time(0));
   if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false) //if the space isn't explored
   {
       if ((rand() % (100 - 1 + 1) + 1) % 10 == 0) //genrates the probability of finding a key
       {
           temp_user.setUserKey(temp_user.getUserKey() + 1);
           cout << "You have found a key! Good job!" << endl;
       }
       if ((rand() % (20 - 1 + 1) + 1) % 5 == 0)
       {
           if (temp_action.getClearedRooms() == 0)
           {
               cout << "You must clear a room before collecting jewelry" << endl;
           }
           else if (temp_action.getClearedRooms() == 1)
           {
               cout << "You found a ring!" << endl;
               int ring = temp_user.getUserTreasures(0) + 1; //adds one to poisiton 0 which = ring
               temp_user.setUserTreasures(ring, temp_user.getUserTreasures(1), temp_user.getUserTreasures(2), temp_user.getUserTreasures(3), temp_user.getUserTreasures(4));
           }
           else if (temp_action.getClearedRooms() == 2)
           {
               cout << "You found a necklace!" << endl;
               int necklace = temp_user.getUserTreasures(1) + 1; //adds one to necklace
               temp_user.setUserTreasures(temp_user.getUserTreasures(0), necklace, temp_user.getUserTreasures(2), temp_user.getUserTreasures(3), temp_user.getUserTreasures(4));
           }
           else if (temp_action.getClearedRooms() == 3)
           {
               cout << "You found a bracelet!" << endl;
               int bracelet = temp_user.getUserTreasures(2) + 1; //this makes sure the position 2 adds one to bracelet
               temp_user.setUserTreasures(temp_user.getUserTreasures(0), temp_user.getUserTreasures(1), bracelet, temp_user.getUserTreasures(3), temp_user.getUserTreasures(4));
           }
           else if (temp_action.getClearedRooms() == 4)
           {
               cout << "You found a circlet!" << endl;
               int circlet = temp_user.getUserTreasures(3) + 1;
               temp_user.setUserTreasures(temp_user.getUserTreasures(0), temp_user.getUserTreasures(1), temp_user.getUserTreasures(2), circlet, temp_user.getUserTreasures(4));
           }
           else if (temp_action.getClearedRooms() == 5)
           {
               cout << "You found a goblet!" << endl;
               int goblet = temp_user.getUserTreasures(4) + 1;
               temp_user.setUserTreasures(temp_user.getUserTreasures(0), temp_user.getUserTreasures(1), temp_user.getUserTreasures(2), temp_user.getUserTreasures(3), goblet);
           }
       }
       if ((rand() % (20 - 1 + 1) + 1) % 5 == 0)
       {
           if (temp_action.getClearedRooms() < 5) //if get rooms cleared is < 5 they can still fight monsters
           {
               if (temp_user.fightingMonster(map, temp_user, temp_action) == -1)
               {
                   temp_action.setEndGame(true);
                   return -1;
               }
               fight = -1; //prevents status from being printed twice
               if (temp_action.getEndGame() == true)
               {
                   return -1;
               }
               count2 = -1;
           }
       }
       if (count2 != - 1)
       {
           int full = 0;
           for (int i = 0; i < 5; i++)
           {
               if (temp_user.getPlayersFullness(i) > 0)
               {
                   full++;
               }
           }
           if (full > 2)
           {
               if (temp_user.getPlayersFullness(0) != 0) //main player is not dead
               {
                   if ((rand() % (20 - 1 + 1) + 1) % 2 == 0)
                   {
                       int player = temp_user.getPlayersFullness(0) - 1;
                       temp_user.setPlayersFullness(player, temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                       if (temp_user.getPlayersFullness(0) == 0)
                       {
                           cout << "OH NO! " << temp_user.getPlayers(0) << " has died of hunger!" << endl;
                           int count = 0;
                           for (int i = 0; i < 5; i++)
                           {
                               if (temp_user.getPlayersFullness(i) > 0)
                               {
                                   count++;
                               }
                           }
                           cout << "Your party size has reduced to " << count << " members." << endl;
                           cout << "You have too little players to continue sadly, you have failed :( " << endl;
                           temp_action.setEndGame(true);
                           return -1;
                       }
                       else
                       {
                           cout << temp_user.getPlayers(0) << "'s health dropped by one!" << endl;
                           if (temp_user.getPlayersFullness(0) == 1)
                           {
                           cout << "Warning: " << temp_user.getPlayers(0) << " is on the brink of starvation!" << endl;
                           cout << "You should cook and eat some food!" << endl;
                           }
                       }
                   }
               }
               if (temp_user.getPlayersFullness(1) != 0)
               {
                   if ((rand() % (20 - 1 + 1) + 1) % 2 == 0)
                   {
                       int player = temp_user.getPlayersFullness(1) - 1;
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), player, temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                       if (temp_user.getPlayersFullness(1) == 0)
                       {
                           cout << "OH NO! " << temp_user.getPlayers(1) << " has died of hunger!" << endl;
                           int count = 0;
                           for (int i = 0; i < 5; i++)
                           {
                               if (temp_user.getPlayersFullness(i) > 0)
                               {
                                   count++;
                               }
                           }
                           cout << "Your party size has reduced to " << count << " members." << endl;
                           full = full - 1;
                           if (full < 2)
                           {
                               cout << "You have too little players to continue sadly, you have failed :( " << endl;
                               temp_action.setEndGame(true);
                               return -1;
                           }
                       }
                       else
                       {
                           cout << temp_user.getPlayers(1) << "'s health dropped by one!" << endl;
                           if (temp_user.getPlayersFullness(1) == 1)
                           {
                               cout << "Warning: " << temp_user.getPlayers(1) << " is on the brink of starvation!" << endl;
                               cout << "You should cook and eat some food!" << endl;
                           }
                       }
                   }
               }
               if (temp_user.getPlayersFullness(2) != 0)
               {
                   if ((rand() % (20 - 1 + 1) + 1) % 2 == 0)
                   {
                       int player = temp_user.getPlayersFullness(2) - 1;
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), player, temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                       if (temp_user.getPlayersFullness(2) == 0)
                       {
                           cout << "OH NO! " << temp_user.getPlayers(2) << " has died of hunger!" << endl;
                           int count = 0;
                           for (int i = 0; i < 5; i++)
                           {
                               if (temp_user.getPlayersFullness(i) > 0)
                               {
                                   count++;
                               }
                           }
                           cout << "Your party size has reduced to " << count << " members." << endl;
                           full = full - 1;
                           if (full < 2) //checks that there are still more than 2 players
                           {
                               cout << "You have too little players to continue sadly, you have failed :( " << endl;
                               temp_action.setEndGame(true);
                               return -1;
                           }
                       }
                       else
                       {
                           cout << temp_user.getPlayers(2) << "'s health dropped by one!" << endl;
                           if (temp_user.getPlayersFullness(2) == 1)
                       {
                           cout << "Warning: " << temp_user.getPlayers(2) << " is on the brink of starvation!" << endl;
                           cout << "You should cook and eat some food!" << endl;
                       }
                       }
                   }
               }
               if (temp_user.getPlayersFullness(3) != 0)
               {
                   if ((rand() % (20 - 1 + 1) + 1) % 2 == 0)
                   {
                       int player = temp_user.getPlayersFullness(3) - 1;
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), player, temp_user.getPlayersFullness(4));
                       if (temp_user.getPlayersFullness(3) == 0)
                       {
                           cout << "OH NO! " << temp_user.getPlayers(3) << " has died of hunger!" << endl;
                           int count = 0;
                           for (int i = 0; i < 5; i++)
                           {
                               if (temp_user.getPlayersFullness(i) > 0)
                               {
                                   count++;
                               }
                           }
                           cout << "Your party size has reduced to " << count << " members." << endl;
                           full = full - 1;
                           if (full < 2)
                           {
                               cout << "You have too little players to continue sadly, you have failed :( " << endl;
                               temp_action.setEndGame(true);
                               return -1;
                           }
                       }
                       else
                       {
                           cout << temp_user.getPlayers(3) << "'s health dropped by one!" << endl;
                           if (temp_user.getPlayersFullness(3) == 1)
                       {
                           cout << "Warning: " << temp_user.getPlayers(3) << " is on the brink of starvation!" << endl;
                           cout << "You should cook and eat some food!" << endl;
                       }
                       }
                   }
               }
               if (temp_user.getPlayersFullness(4) != 0)
               {
                   if ((rand() % (20 - 1 + 1) + 1) % 2 == 0)
                   {
                       int player = temp_user.getPlayersFullness(4) - 1;
                       temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), player);
                       if (temp_user.getPlayersFullness(4) == 0)
                       {
                           cout << "OH NO! " << temp_user.getPlayers(4) << " has died of hunger!" << endl;
                           int count = 0;
                           for (int i = 0; i < 5; i++)
                           {
                               if (temp_user.getPlayersFullness(i) > 0)
                               {
                                   count++;
                               }
                           }
                           cout << "Your party size has reduced to " << count << " members." << endl;
                           full = full - 1;
                           if (full < 2)
                           {
                               cout << "You have too little players to continue sadly, you have failed :( " << endl;
                               temp_action.setEndGame(true);
                               return -1;
                           }
                       }
                       else
                       {
                           cout << temp_user.getPlayers(4) << "'s health dropped by one!" << endl;
                           if (temp_user.getPlayersFullness(4) == 1)
                           {
                               cout << "Warning: " << temp_user.getPlayers(4) << " is on the brink of starvation!" << endl;
                               cout << "You should cook and eat some food!" << endl;
                           }
                       }
                   }
               }
           }
       }
       if (temp_action.getEndGame() == true)
       {
           return -1;
       }
       map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
   }
   else
   {
       cout << "This space cannot be investigated, please select another option" << endl;
       return 2;
   }
   if (fight != -1) //if the user didn't fight a monster this will display the stauts
   {
       temp_user.displayStatus(temp_user, map, temp_action);
   }
   return 1;
}

//--------------------------------------------------------------------------------------------------
int User::fullnessDrop(User &temp_user, Action &temp_action) //void because doesn’t return anything just drops the fullness- if they choose move (then they start doing the char (w, s, etc. )
{
   srand(time(0));
   int full = 0;
   for (int i = 0; i < 5; i++) //traverses through players and their fullness
   {
       if (temp_user.getPlayersFullness(i) > 0)
       {
           full++;
       }
   }
   if (full > 2) //making sure there are more than two players
   {
       if (temp_user.getPlayersFullness(0) != 0) //each player has a chance of losing fullness that is why there is an if statement
       {
           if ((rand() % (20 - 1 + 1) + 1) % 5 == 0)
           {
               int player = temp_user.getPlayersFullness(0) - 1;
               temp_user.setPlayersFullness(player, temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
               if (temp_user.getPlayersFullness(0) == 0)
               {
                   cout << "OH NO! " << temp_user.getPlayers(0) << " has died of hunger!" << endl;
                   cout << "You have failed the game due to starvation of the main player! " << endl;
                   temp_action.setEndGame(true);
                   return -1;
               }
               else
               {
                   cout << temp_user.getPlayers(0) << "'s health dropped by one!" << endl;
                   if (temp_user.getPlayersFullness(0) == 1)
                   {
                       cout << "Warning: " << temp_user.getPlayers(0) << " is on the brink of starvation!" << endl;
                       cout << "You should cook and eat some food!" << endl;
                   }
               } 
           }
       }
       if (temp_user.getPlayersFullness(1) != 0)
       {
           if ((rand() % (20 - 1 + 1) + 1) % 5 == 0)
           {
               int player = temp_user.getPlayersFullness(1) - 1; //subtracts players fullness
               temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), player, temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
               if (temp_user.getPlayersFullness(1) == 0)
               {
                   cout << "OH NO! " << temp_user.getPlayers(1) << " has died of hunger!" << endl;
                   int count = 0;
                   for (int i = 0; i < 5; i++) //checking how many players are left
                   {
                       if (temp_user.getPlayersFullness(i) > 0)
                       {
                           count++;
                       }
                   }
                   cout << "Your party size has reduced to " << count << " members." << endl;
                   full = full - 1;
                   if (full < 2) //if there are less that two players
                   {
                       cout << "You have too little players to continue sadly, you have failed :( " << endl;
                       temp_action.setEndGame(true); 
                       return -1;
                   }
               }
               else
               {
                   cout << temp_user.getPlayers(1) << "'s health dropped by one!" << endl;
                   if (temp_user.getPlayersFullness(1) == 1)
                   {
                       cout << "Warning: " << temp_user.getPlayers(1) << " is on the brink of starvation!" << endl;
                       cout << "You should cook and eat some food!" << endl;
                   }
               }
           }
       }
       if (temp_user.getPlayersFullness(2) != 0)
       {
           if ((rand() % (20 - 1 + 1) + 1) % 5 == 0)
           {
               int player = temp_user.getPlayersFullness(2) - 1;//subtracts players fullness
               temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), player, temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
               if (temp_user.getPlayersFullness(2) == 0)
               {
                   cout << "OH NO! " << temp_user.getPlayers(2) << " has died of hunger!" << endl;
                   int count = 0;
                   for (int i = 0; i < 5; i++) //checking how many players are left
                   {
                       if (temp_user.getPlayersFullness(i) > 0)
                       {
                           count++;
                       }
                   }
                   cout << "Your party size has reduced to " << count << " members." << endl;
                   full = full - 1;
                   if (full < 2)
                   {
                       cout << "You have too little players to continue sadly, you have failed :( " << endl;
                       temp_action.setEndGame(true);
                       return -1;
                   }
               }
               else
               {
                   cout << temp_user.getPlayers(2) << "'s health dropped by one!" << endl;
                   if (temp_user.getPlayersFullness(2) == 1)
                   {
                       cout << "Warning: " << temp_user.getPlayers(2) << " is on the brink of starvation!" << endl;
                       cout << "You should cook and eat some food!" << endl;
                   }
               }
           }
       }
       if (temp_user.getPlayersFullness(3) != 0)
       {
           if ((rand() % (20 - 1 + 1) + 1) % 5 == 0)
           {
               int player = temp_user.getPlayersFullness(3) - 1;//subtracts players fullness
               temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), player, temp_user.getPlayersFullness(4));
               if (temp_user.getPlayersFullness(3) == 0)
               {
                   cout << "OH NO! " << temp_user.getPlayers(3) << " has died of hunger!" << endl;
                   int count = 0;
                   for (int i = 0; i < 5; i++)//checking how many players are left
                   {
                       if (temp_user.getPlayersFullness(i) > 0)
                       {
                           count++;
                       }
                   }
                   cout << "Your party size has reduced to " << count << " members." << endl;
                   full = full - 1;
                   if (full < 2) //if there are less than 2 players
                   {
                       cout << "You have too little players to continue sadly, you have failed :( " << endl;
                       temp_action.setEndGame(true);
                       return -1;
                   }
               }
               else
               {
                   cout << temp_user.getPlayers(3) << "'s health dropped by one!" << endl;
                   if (temp_user.getPlayersFullness(3) == 1)
                   {
                       cout << "Warning: " << temp_user.getPlayers(3) << " is on the brink of starvation!" << endl;
                       cout << "You should cook and eat some food!" << endl;
                   }
               }
           }
       }
       if (temp_user.getPlayersFullness(4) != 0)
       {
           if ((rand() % (20 - 1 + 1) + 1) % 5 == 0)
           {
               int player = temp_user.getPlayersFullness(4) - 1;//subtracts players fullness
               temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), player);
               if (temp_user.getPlayersFullness(4) == 0)
               {
                   cout << "OH NO! " << temp_user.getPlayers(4) << " has died of hunger!" << endl;
                   int count = 0;
                   for (int i = 0; i < 5; i++) //checking how many players are left
                   {
                       if (temp_user.getPlayersFullness(i) > 0)
                       {
                           count++;
                       }
                   }
                   cout << "Your party size has reduced to " << count << " members." << endl;
                   full = full - 1;
                   if (full < 2) //checking if there are less than two players
                   {
                       cout << "You have too little players to continue sadly, you have failed :( " << endl;
                       temp_action.setEndGame(true);
                       return -1;
                   }
               }
               else
               {
                   cout << temp_user.getPlayers(4) << "'s health dropped by one!" << endl;
                   if (temp_user.getPlayersFullness(4) == 1)
                   {
                       cout << "Warning: " << temp_user.getPlayers(4) << " is on the brink of starvation!" << endl;
                       cout << "You should cook and eat some food!" << endl;
                   }
               }
           }
       }
   }
   else
   {
       temp_action.setEndGame(true);
       return -1;
   }
   return 1;
}
//--------------------------------------------------------------------------------------------------
int User::fightingMonster(Map &map, User &temp_user, Action &temp_action)
{
    ifstream fin;
    string line;
    srand(time(0));
    int count = 0;
    if (temp_action.getClearedRooms() == 0)
    {
        int monster = rand() % (12 - 1 + 1) + 1;
        fin.open("monsters.txt");
        while (!fin.eof()) // continue looping as long as there is data to be processed in the file
        {
            while (count < monster)
            {
                getline(fin, line); //gets the correct monster
                count++;
            }
            break;
        }
        fin.close(); 
    }
    else if (temp_action.getClearedRooms() == 1)
    {
        int monster = rand() % (16 - 13 + 1) + 13;
        fin.open("monsters.txt");
        while (!fin.eof()) // continue looping as long as there is data to be processed in the file
        {
            while (count < monster)
            {
                getline(fin, line); //gets the correct monster
                count++;
            }
            break;
        }
        fin.close();
    }
    else if (temp_action.getClearedRooms() == 2)
    {
        int monster = rand() % (22 - 17 + 1) + 17;
        fin.open("monsters.txt");
        while (!fin.eof()) // continue looping as long as there is data to be processed in the file
        {
            while (count < monster)
            {
                getline(fin, line); //gets the correct monster
                count++;
            } 
            break;
        }
        fin.close();
    }
    else if (temp_action.getClearedRooms() == 3)
    {
        int monster = rand() % (28 - 23 + 1) + 23;
        fin.open("monsters.txt");
        while (!fin.eof()) // continue looping as long as there is data to be processed in the file
        {
            while (count < monster)
            {
                getline(fin, line); //gets the correct monster
                count++;
            } 
            break;
        }
        fin.close();
    }
    else if (temp_action.getClearedRooms() == 4)
    {
        int monster = 29;
        fin.open("monsters.txt");
        while (!fin.eof()) // continue looping as long as there is data to be processed in the file
        {
            while (count < monster)
            {
                getline(fin, line); //gets the correct monster
                count++;
            } 
            break;
        }
        fin.close();
    }
    int location = 0;
    int monsterRating = 0;
    string monsterName;
    for (int i = 0; i < line.length(); i++) //traversing through input string
    {
        if (line[i] == ',') //if input string of i equals separator
        {
            location = i + 1; //plus one because doesn't include the separator
            monsterRating = stoi(line.substr(location, line.length() - location)); //gets monster rating
            monsterName = line.substr(0, location - 1); //gets monster name 
        }
    }
    cout << monsterName << " ahead!!! They look hostile!!!" << endl;
    int userChoice = 0;
    if (temp_user.getUserWeapons(0) + temp_user.getUserWeapons(1) + temp_user.getUserWeapons(2) + temp_user.getUserWeapons(3) + temp_user.getUserWeapons(4) > 0) //see if the user has any weapons
    {
        cout << "Select one:" << endl;
        cout << "(1) Attack" << endl;
        cout << "(2) Surender" << endl;
        cin >> userChoice;
        while (userChoice < 1 || userChoice > 2)
        {
            cout << "Invalid input, please try again" << endl;
            cin >> userChoice;
        }
    }
    else 
    {
        cout << "You don't have any weapons, you must surrender" << endl;
        userChoice = 2;
    }
    if (userChoice == 1)
    {
        cout << "Preparing the attack!!" << endl;
        cout << "Baboom!!!!!" << endl;
        sleep(2);
        int w = 0;
        int numWeapons = temp_user.getUserWeapons(0) + temp_user.getUserWeapons(1) + temp_user.getUserWeapons(2) + temp_user.getUserWeapons(3) + temp_user.getUserWeapons(4);
        int full = 0;
        for (int i = 0; i < 5; i++)
        {
            if (temp_user.getPlayersFullness(i) > 0)
            {
                full++;
            }
        }
        if (numWeapons == full) //if there are the same number of weapons as there is players
        {
            w = numWeapons;
        }
        else if (numWeapons > full) //if there is more weapons than players
        {
            w = full;
        }
        else if (numWeapons < full) //if there is more players than weapons
        {
            w = numWeapons;
        }
        if (temp_user.getUserWeapons(2) >= 1) //if the players hold a +1 rapier
        {
            w = w + 1;
        }
        if (temp_user.getUserWeapons(3) >= 1) //if the players hold a +2 battle-axe
        {
            w = w + 2;
        }
        if (temp_user.getUserWeapons(4) >= 1) //if the players hold a +3 longsword
        {
            w = w + 3;
        }
 
        int d = 0;
        int count2 = 0;
        for (int i = 0; i < 5; i++)
        {
            if (temp_user.getUserWeapons(i) > 0)
            {
                count2++; //sees how many weapons the user has
            }
        }
        if (count2 >= full)
        {
            d = 4;
        }
        int a = temp_user.getUserArmor(); //stores amount of armor the user has in a
        int c = monsterRating; //stores monster rating in c
        int r1 = rand() % (6 - 1 + 1) + 1; //gets random number in between 6 and 1
        int r2 = rand() % (6 - 1 + 1) + 1; //gets random number in between 6 and 1
        int result = 0;
        result = (r1 * w + d) - ((r2 * c) / a); //calculate result using given equation
        if (result > 0) //if they won against the monster
        {
            cout << "Great job! You won!!" << endl;
            cout << "That " << monsterName << " never stood a chance!!" << endl;
            int gold = temp_user.getUserGold() + (10 * c);
            temp_user.setUserGold(gold);
            int ingredients = temp_user.getUserIngredients() + (5 * c);
            if ((rand() % (100 - 1 + 1) + 1) % 10 == 0) //10% chance of getting a key
            {
                temp_user.setUserKey(temp_user.getUserKey() + 1);
                cout << "You have found a key! Good job!" << endl;
            }
            map.removeRoom(map.getPlayerRow(), map.getPlayerCol()); //remove room after beating a monster
            map.exploreSpace(map.getPlayerRow(), map.getPlayerCol()); //explore the space
            temp_action.setMonstersDefeated(temp_action.getMonstersDefeated() + 1); //add one to monsters defeated
            temp_user.displayStatus(temp_user, map, temp_action);
            return 1;
        }
        else //they didnt win against the monster
        {
            cout << "Uh oh...you lost." << endl;
            cout << "Don't stress but remember, your soul may be stuck here forever!!" << endl;
            int full = 0;
            for (int i = 0; i < 5; i++)
            {
                if (temp_user.getPlayersFullness(i) > 0)
                {
                    full++; //gets how many players are not dead
                }
            }
            int gold = temp_user.getUserGold() - temp_user.getUserGold()/4; //divides gold by 4 to get a quarter
            temp_user.setUserGold(gold);
            if (temp_user.getUserIngredients() >= 30) //subtract 30 ingredients
            {
                temp_user.setUserIngredients(temp_user.getUserIngredients() - 30);
            }
            else
            {
                temp_user.setUserIngredients(0); //subtract the rest of their ingredients
            }
            if (count <=  temp_user.getUserArmor()) //if the party has enough armor for everyone
            {
                if (full > 2) //if there are enough players to keep going
                {
                    if ((rand() % (100 - 1 + 1) + 1) % 20 == 0) //5% chance the player will die
                    {
                        temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), 0, temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                        full = full - 1;
                        if (full < 2) //if there are enough players to keep going
                        {
                            cout << "You have too little players to continue sadly, you have failed :( " << endl;
                            temp_action.setEndGame(true); //ends game 
                            return -1; 
                        }
                    }
                    else if ((rand() % (100 - 1 + 1) + 1) % 20 == 0) //5% chance the player will die
                    {
                        temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), 0, temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                        full = full - 1;
                        if (full < 2) //if there are enough players to keep going
                        {
                            cout << "You have too little players to continue sadly, you have failed :( " << endl;
                            temp_action.setEndGame(true); //ends game
                            return -1; 
                        }
                    }
                    else if ((rand() % (100 - 1 + 1) + 1) % 20 == 0) //5% chance the player will die
                    {
                        temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), 0, temp_user.getPlayersFullness(4));
                        full = full - 1;
                        if (full < 2) //if there are enough players to keep going
                        {
                            cout << "You have too little players to continue sadly, you have failed :( " << endl;
                            temp_action.setEndGame(true); //ends game
                            return -1; 
                        }
                    }
                    else if ((rand() % (100 - 1 + 1) + 1) % 20 == 0) //5% chance the player will die
                    {
                        temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), 0);
                        full = full - 1;
                        if (full < 2) //if there are enough players to keep going
                        {
                            cout << "You have too little players to continue sadly, you have failed :( " << endl;
                            temp_action.setEndGame(true); //ends game
                            return -1; 
                        }
                    }
                    if (temp_action.getEndGame() == true)
                    {
                        return -1; //ends game
                    }
                }
                else 
                {
                    temp_action.setEndGame(true);
                    return -1; //ends game
                }
            }
            else if (count > temp_user.getUserArmor()) //if there are more players than armor
            {
                if (full > 2) //if there are enough players
                {
                    count = count - 1;
                    int count3 = temp_user.getUserArmor();
                    count3 = count3 -1;
                    if (count3 > 0) //if there is still armor
                    {
                        if ((rand() % (100 - 1 + 1) + 1) % 20 == 0) //5% chance of dying
                        {
                            temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), 0, temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4)); 
                            cout << temp_user.getPlayers(1) << " has been killed by the monster!!" << endl;
                            full = full - 1;
                            if (full < 2) //if there are enough players
                            {
                                cout << "You have too little players to continue sadly, you have failed :( " << endl;
                                temp_action.setEndGame(true);
                                return -1; //ends game
                            }
                        }
                        count3 = count3 - 1;
                    }
                    else //if there is no more armor left
                    {
                        if ((rand() % (100 - 1 + 1) + 1) % 10 == 0) //10% chance of dying
                        {
                            temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), 0, temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4)); 
                            cout << temp_user.getPlayers(1) << " has been killed by the monster!!" << endl;
                            full = full - 1;
                            if (full < 2)
                            {
                                cout << "You have too little players to continue sadly, you have failed :( " << endl;
                                temp_action.setEndGame(true);
                                return -1; //ends game
                            }
                        }
                    }
                    if (count3 > 0) //if there is still armor
                    {
                        if ((rand() % (100 - 1 + 1) + 1) % 20 == 0) //5% chance of dying
                        {
                            temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), 0, temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4)); 
                            cout << temp_user.getPlayers(2) << " has been killed by the monster!!" << endl;
                            full = full - 1;
                            if (full < 2) //if there are enough players
                            {
                                cout << "You have too little players to continue sadly, you have failed :( " << endl;
                                temp_action.setEndGame(true);
                                return -1; //ends game
                            }
                        }
                        count3 = count3 - 1;
                    }
                    else //if there is no more armor left
                    {
                        if ((rand() % (100 - 1 + 1) + 1) % 10 == 0) //10% chance of dying
                        {
                            temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), 0, temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4)); 
                            cout << temp_user.getPlayers(2) << " has been killed by the monster!!" << endl;
                            full = full - 1;
                            if (full < 2) //if there are enough players
                            {
                                cout << "You have too little players to continue sadly, you have failed :( " << endl;
                                temp_action.setEndGame(true);
                                return -1; //ends game
                            }
                        }
                    }
                    if (count3 > 0) //if there is still armor
                    {
                        if ((rand() % (100 - 1 + 1) + 1) % 20 == 0) //5% chance of dying
                        {
                            temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), 0, temp_user.getPlayersFullness(4)); 
                            cout << temp_user.getPlayers(3) << " has been killed by the monster!!" << endl;
                            full = full - 1;
                            if (full < 2) //if there are enough players
                            {
                                cout << "You have too little players to continue sadly, you have failed :( " << endl;
                                temp_action.setEndGame(true);
                                return -1; //ends game
                            }
                        }
                        count3 = count3 - 1;
                    }
                    else //if there is no more armor left
                    {
                        if ((rand() % (100 - 1 + 1) + 1) % 10 == 0) //10% chance of dying
                        {
                            temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), 0, temp_user.getPlayersFullness(4)); 
                            cout << temp_user.getPlayers(3) << " has been killed by the monster!!" << endl;
                            full = full - 1;
                            if (full < 2) //if there are enough players
                            {
                                cout << "You have too little players to continue sadly, you have failed :( " << endl;
                                temp_action.setEndGame(true);
                                return -1; //ends game
                            }
                        }
                    }
                    if (count2 > 0) //if there is still armor
                    {
                        if ((rand() % (100 - 1 + 1) + 1) % 20 == 0) //5% chance of dying
                        {
                            temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), 0); 
                            cout << temp_user.getPlayers(4) << " has been killed by the monster!!" << endl;
                            full = full - 1;
                            if (full < 2) //if there are enough players
                            {
                                cout << "You have too little players to continue sadly, you have failed :( " << endl;
                                temp_action.setEndGame(true);
                                return -1; //ends game
                            }
                        }
                        count3 = count3 - 1;
                    }
                    else //if there is no more armor left
                    {
                        if ((rand() % (100 - 1 + 1) + 1) % 10 == 0) //10% chance of dying
                        {
                            temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), 0); 
                            cout << temp_user.getPlayers(4) << " has been killed by the monster!!" << endl;
                            full = full - 1;
                            if (full < 2) //if there are enough players
                            {
                                cout << "You have too little players to continue sadly, you have failed :( " << endl;
                                temp_action.setEndGame(true);
                                return -1; //ends game
                            }
                        }
                    }
                }
                else
                {
                    temp_action.setEndGame(true);
                    return -1; //ends game
                }
            }
            return 1;
        }
        temp_user.displayStatus(temp_user, map, temp_action);
    }
    else if (userChoice == 2)
    {
        cout << "You try to run away from the monster but someone gets caught!" << endl;
        int full = 0;
        for (int i = 0; i < 5; i++)
        {
            if (temp_user.getPlayersFullness(i) > 0)
            {
                full++;
            }
        }
        if (full > 2) //if there are enough players
        {
            int check = 0;
            int player = (rand() % (4 - 1 + 1) + 1);
            if (player == 1) //if randNum == 1
            {
                if (temp_user.getPlayersFullness(1) > 0) //checking to see if they are alive
                {
                    temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), 0, temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                    cout << temp_user.getPlayers(1) << " has been killed by the monster!!" << endl;
                    check = -1;
                    full = full - 1;
                    if (full < 2) //if there are enough players
                    {
                        cout << "You have too little players to continue sadly, you have failed :( " << endl;
                        temp_action.setEndGame(true);
                        return -1; //ends game
                    }
                }
                else
                {
                    player = (rand() % (4 - 2 + 1) + 2);
                }
            }
            if (player == 2) //if randNum == 2
            {
                if (temp_user.getPlayersFullness(2) > 0) //checking to see if they are alive
                {
                    temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), 0, temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                    cout << temp_user.getPlayers(2) << " has been killed by the monster!!" << endl;
                    check = -1;
                    full = full - 1;
                    if (full < 2) //if there are enough players
                    {
                        cout << "You have too little players to continue sadly, you have failed :( " << endl;
                        temp_action.setEndGame(true);
                        return -1; //ends game
                    }
                }
                else
                {
                    player = (rand() % (4 - 3 + 1) + 3);
                }
            }
            if (player == 3) //if randNum == 3
            {
                if (temp_user.getPlayersFullness(3) > 0) //checking to see if they are alive
                {
                    temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), 0, temp_user.getPlayersFullness(4));
                    cout << temp_user.getPlayers(3) << " has been killed by the monster!!" << endl;
                    check = -1;
                    full = full - 1;
                    if (full < 2) //if there are enough players
                    {
                        cout << "You have too little players to continue sadly, you have failed :( " << endl;
                        temp_action.setEndGame(true);
                        return -1; //ends game
                    }
                }
                else
                {
                    player = 4;
                }
            }
            if (check != -1) //if someone hasn't died yet
            {
                temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), 0);
                cout << temp_user.getPlayers(4) << " has been killed by the monster!!" << endl;
                full = full - 1;
                if (full < 2) //if there are enough players
                {
                    cout << "You have too little players to continue sadly, you have failed :( " << endl;
                    temp_action.setEndGame(true);
                    return -1; //ends game
                }
            }
        }
        else
        {
            temp_action.setEndGame(true);
            return -1; //ends game
        }
    }
    int full = 0;
    for (int i = 0; i < 5; i++)
    {
        if (temp_user.getPlayersFullness(i) > 0)
        {
            full++;
        }
    }
    if (full > 2) //if you have enough players
    {
        if (temp_user.getPlayersFullness(0) != 0)
        {
            if ((rand() % (20 - 1 + 1) + 1) % 2 == 0)
            {
                int player = temp_user.getPlayersFullness(0) - 1;
                temp_user.setPlayersFullness(player, temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                if (temp_user.getPlayersFullness(0) == 0)
                {
                    cout << "OH NO! " << temp_user.getPlayers(0) << " has died of hunger!" << endl;
                    cout << "The leader has died, you have failed :( " << endl;
                    temp_action.setEndGame(true);
                    return -1; //ends game
                }
                else
                {
                    cout << temp_user.getPlayers(0) << "'s health dropped by one!" << endl;
                    if (temp_user.getPlayersFullness(0) == 1) //if the player is about to die
                    {
                        cout << "Warning: " << temp_user.getPlayers(0) << " is on the brink of starvation!" << endl;
                        cout << "You should cook and eat some food!" << endl;
                    }
                }
            }
        }
        
        if (temp_user.getPlayersFullness(1) != 0)
        {
            if ((rand() % (20 - 1 + 1) + 1) % 2 == 0)
            {
                int player = temp_user.getPlayersFullness(1) - 1;
                temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), player, temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                if (temp_user.getPlayersFullness(1) == 0)
                {
                    cout << "OH NO! " << temp_user.getPlayers(1) << " has died of hunger!" << endl;
                    int count = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        if (temp_user.getPlayersFullness(i) > 0)
                        {
                            count++;
                        }
                    }
                    cout << "Your party size has reduced to " << count << " members." << endl;
                    full = full - 1;
                    if (full < 2) //if there are enough players
                    {
                        cout << "You have too little players to continue sadly, you have failed :( " << endl;
                        temp_action.setEndGame(true);
                        return -1; //ends game
                    }
                }
                else
                {
                    cout << temp_user.getPlayers(1) << "'s health dropped by one!" << endl;
                    if (temp_user.getPlayersFullness(1) == 1) //if the player is about to die
                    {
                        cout << "Warning: " << temp_user.getPlayers(1) << " is on the brink of starvation!" << endl;
                        cout << "You should cook and eat some food!" << endl;
                    }
                }
            }
        }
        if (temp_user.getPlayersFullness(2) != 0)
        {
            if ((rand() % (20 - 1 + 1) + 1) % 2 == 0)
            {
                int player = temp_user.getPlayersFullness(2) - 1;
                temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), player, temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                if (temp_user.getPlayersFullness(2) == 0)
                {
                    cout << "OH NO! " << temp_user.getPlayers(2) << " has died of hunger!" << endl;
                    int count = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        if (temp_user.getPlayersFullness(i) > 0)
                        {
                            count++;
                        }
                    }
                    cout << "Your party size has reduced to " << count << " members." << endl;
                    full = full - 1;
                    if (full < 2) //if there are enough players
                    {
                        cout << "You have too little players to continue sadly, you have failed :( " << endl;
                        temp_action.setEndGame(true);
                        return -1; //ends game
                    }
                }
                else
                {
                    cout << temp_user.getPlayers(2) << "'s health dropped by one!" << endl;
                    if (temp_user.getPlayersFullness(2) == 1) //if the player is about to die
                    {
                        cout << "Warning: " << temp_user.getPlayers(2) << " is on the brink of starvation!" << endl;
                        cout << "You should cook and eat some food!" << endl;
                    }
                }
            }
        }
        if (temp_user.getPlayersFullness(3) != 0)
        {
            if ((rand() % (20 - 1 + 1) + 1) % 2 == 0)
            {
                int player = temp_user.getPlayersFullness(3) - 1;
                temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), player, temp_user.getPlayersFullness(4));
                if (temp_user.getPlayersFullness(3) == 0)
                {
                    cout << "OH NO! " << temp_user.getPlayers(3) << " has died of hunger!" << endl;
                    int count = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        if (temp_user.getPlayersFullness(i) > 0)
                        {
                            count++;
                        }
                    }
                    cout << "Your party size has reduced to " << count << " members." << endl;
                    full = full - 1;
                    if (full < 2) //if there are enough players
                    {
                        cout << "You have too little players to continue sadly, you have failed :( " << endl;
                        temp_action.setEndGame(true);
                        return -1; //ends game
                    }
                }
                else
                {
                    cout << temp_user.getPlayers(3) << "'s health dropped by one!" << endl;
                    if (temp_user.getPlayersFullness(3) == 1) //if the player is about to die
                    {
                        cout << "Warning: " << temp_user.getPlayers(3) << " is on the brink of starvation!" << endl;
                        cout << "You should cook and eat some food!" << endl;
                    }
                }
            }
        }
        if (temp_user.getPlayersFullness(4) != 0)
        {
            if ((rand() % (20 - 1 + 1) + 1) % 2 == 0)
            {
                int player = temp_user.getPlayersFullness(4) - 1;
                temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), player);
                if (temp_user.getPlayersFullness(4) == 0)
                {
                    cout << "OH NO! " << temp_user.getPlayers(4) << " has died of hunger!" << endl;
                    int count = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        if (temp_user.getPlayersFullness(i) > 0)
                        {
                            count++;
                        }
                    }
                    cout << "Your party size has reduced to " << count << " members." << endl;
                    full = full - 1;
                    if (full < 2) //if there are enough players
                    {
                        cout << "You have too little players to continue sadly, you have failed :( " << endl;
                        temp_action.setEndGame(true);
                        return -1; //ends game
                    }
                }
                else
                {
                    cout << temp_user.getPlayers(4) << "'s health dropped by one!" << endl;
                    if (temp_user.getPlayersFullness(4) == 1) //if the player is about to die
                    {
                        cout << "Warning: " << temp_user.getPlayers(4) << " is on the brink of starvation!" << endl;
                        cout << "You should cook and eat some food!" << endl;
                    }
                }
            }
        }
        if (temp_action.getEndGame() == true)
        {
            return -1; //ends game
        }
    }
    temp_user.displayStatus(temp_user, map, temp_action);
    return 1;
}
//--------------------------------------------------------------------------------------------------
int User::normalMenu(Map &map, User &temp_user, Action &temp_action, NPC &npc, Merchant &temp_merchant)
{
    int user_input = 0;
    while (user_input != 5)
    {
        cout << "Select one:" << endl;
        sleep(1);
        cout << "1. Move" << endl;
        sleep(1);
        cout << "2. Investigate" << endl;
        sleep(1);
        cout << "3. Pick a Fight" << endl;
        sleep(1);
        cout << "4. Cook and Eat" << endl;
        sleep(1);
        cout << "5. Give up" << endl;
        cin >> user_input;  
    
        while (user_input < 0 || user_input > 5)
        {
            cout << "Invalid input, please try again" << endl;
            cin >> user_input;
        }
        if (user_input == 1)
        {
            map.displayMap();
            int user_input2;
            cout << "Select one:" << endl;
            sleep(1);
            cout << "1. Move up" << endl;
            sleep(1);
            cout << "2. Move down" << endl;
            sleep(1);
            cout << "3. Move left" << endl;
            sleep(1);
            cout << "4. Move right" << endl;
            cin >> user_input2;
            while (user_input2 < 1 || user_input2 > 4)
            {
                cout << "Invalid input, please try again or select 0 to cancel" << endl;
                cin >> user_input2;
                if (user_input2 == 0)
                {
                    break;
                }
            }
            if (user_input2 == 1) //if user moves up
            {
                map.move('w');
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    if (temp_action.getClearedRooms() == 5)
                    {
                       npc.setSuccess(true); //if user is at the exit and has cleared all of the rooms
                       return -1;
                    }
                }
                temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
                temp_user.fullnessDrop(temp_user, temp_action);
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false)
                {
                    if (temp_action.getClearedRooms() < 5)
                    {
                        if (temp_user.getAngerLevel() < 100)
                        {
                            int anger = temp_user.getAngerLevel() + 1; //anger level will increase if space isnt explored and cleared rooms isnt 5
                            temp_user.setAngerLevel(anger);
                        }
                        if (temp_user.getAngerLevel() == 100)
                        {
                            cout << "The sorcerer's anger got to 100" << endl; //if anger level reaches 100 then fail
                            cout << "You have failed." << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
                temp_user.displayStatus(temp_user, map, temp_action);
                if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    int room = temp_user.roomMenu(temp_user, temp_action, map, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a room location then show room menu and if room menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        continue; //if it is a room location then show room menu and if room menu returns somethign other then -1, return 1
                    }
                }
                if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                    int room = temp_user.npcMenu(temp_action, map, temp_user, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a npc location then show npc menu and if npc menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        continue; //if it is a npc location then show npc menu and if npc menu returns somethign other then -1, return 1
                    }
                }
            }
            else if (user_input2 == 2) //if user moves down
            {
                map.move('s');
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    if (temp_action.getClearedRooms() == 5)
                    {
                       npc.setSuccess(true); //if user is at the exit and has cleared all of the rooms
                       return -1;
                    }               
                }
                temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
                temp_user.fullnessDrop(temp_user, temp_action);
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false)
                {
                    if (temp_action.getClearedRooms() < 5)
                    {
                        if (temp_user.getAngerLevel() < 100)
                        {
                            int anger = temp_user.getAngerLevel() + 1; //anger level will increase if space isnt explored and cleared rooms isnt 5
                            temp_user.setAngerLevel(anger);
                        }
                        if (temp_user.getAngerLevel() == 100)
                        {
                            cout << "The sorcerer's anger got to 100" << endl; //if anger level reaches 100 then fail
                            cout << "You have failed." << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
                temp_user.displayStatus(temp_user, map, temp_action);
                while (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    int room = temp_user.roomMenu(temp_user, temp_action, map, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a room location then show room menu and if room menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        continue; //if it is a room location then show room menu and if room menu returns somethign other then -1, return 1
                    }
                }
                if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                    int room = temp_user.npcMenu(temp_action, map, temp_user, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a npc location then show npc menu and if npc menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        continue; //if it is a npc location then show npc menu and if npc menu returns somethign other then -1, return 1
                    }
                }
            }
            else if (user_input2 == 3) //if user moves left
            {
                map.move('a');
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    if (temp_action.getClearedRooms() == 5)
                    {
                       npc.setSuccess(true); //if user is at the exit and has cleared all of the rooms
                       return -1;
                    }
                }
                temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
                temp_user.fullnessDrop(temp_user, temp_action);
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false)
                {
                    if (temp_action.getClearedRooms() < 5)
                    {
                        if (temp_user.getAngerLevel() < 100)
                        {
                            int anger = temp_user.getAngerLevel() + 1; //anger level will increase if space isnt explored and cleared rooms isnt 5
                            temp_user.setAngerLevel(anger);
                        }
                        if (temp_user.getAngerLevel() == 100)
                        {
                            cout << "The sorcerer's anger got to 100" << endl; //if anger level reaches 100 then fail
                            cout << "You have failed." << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
                temp_user.displayStatus(temp_user, map, temp_action);
                if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    int room = temp_user.roomMenu(temp_user, temp_action, map, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a room location then show room menu and if room menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        continue; //if it is a room location then show room menu and if room menu returns somethign other then -1, return 1
                    }
                }
                if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                    int room = temp_user.npcMenu(temp_action, map, temp_user, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a npc location then show npc menu and if npc menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        continue; //if it is a npc location then show npc menu and if npc menu returns somethign other then -1, return 1
                    }
                }
            }
            else if (user_input2 == 4) //if user moves right
            {
                map.move('d');
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    if (temp_action.getClearedRooms() == 5)
                    {
                       npc.setSuccess(true); //if user is at the exit and has cleared all of the rooms
                       return -1;
                    }
                }
                temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
                temp_user.fullnessDrop(temp_user, temp_action);
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false)
                {
                    if (temp_action.getClearedRooms() < 5)
                    {
                        if (temp_user.getAngerLevel() < 100)
                        {
                            int anger = temp_user.getAngerLevel() + 1; //anger level will increase if space isnt explored and cleared rooms isnt 5
                            temp_user.setAngerLevel(anger);
                        }
                        if (temp_user.getAngerLevel() == 100)
                        {
                            cout << "The sorcerer's anger got to 100" << endl; //if anger level reaches 100 then fail
                            cout << "You have failed." << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
                temp_user.displayStatus(temp_user, map, temp_action);
                if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    int room = temp_user.roomMenu(temp_user, temp_action, map, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a room location then show room menu and if room menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        continue; //if it is a room location then show room menu and if room menu returns somethign other then -1, return 1
                    }
                }
                if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                    int room = temp_user.npcMenu(temp_action, map, temp_user, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a npc location then show npc menu and if npc menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        continue; //if it is a npc location then show npc menu and if npc menu returns somethign other then -1, return 1
                    }
                }
            }
        }
        else if (user_input == 2) //if user wants to investigate
        {
            temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
            int result = temp_user.investigateChances(temp_user, map, temp_action);
            if (result == -1)
            {
                return -1; //if investigate returns -1 the return -1 which ends the game
            }
            else
            {
                continue; 
            }
        }
        else if (user_input == 3)
        {
            if (temp_action.getClearedRooms() < 5) //checking to see if they can still fight monsters
            {
                temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
                if (temp_user.fightingMonster(map, temp_user, temp_action) == -1)
                {
                    return -1; //if fighting returns -1, game should end so return -1
                } 
            }
            else
            {
                cout << "You can't fight anymore monsters" << endl;
            }
            temp_user.displayStatus(temp_user, map, temp_action);
        }
        else if (user_input == 4)
        {
            temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
            temp_user.cooking(temp_user, temp_action);
            temp_user.displayStatus(temp_user, map, temp_action);
        }
        else if (user_input == 5) //if user wants to give up
        {
            temp_action.setEndGame(true);
            return -1;
        }
    }
    return 1;
}
int User::roomMenu(User &temp_user, Action &temp_action, Map &map, NPC &npc, Merchant &temp_merchant)
{
    int userInput = 0;
    cout << "Select one:" << endl;
    sleep(1);
    cout << "1. Move" << endl;
    sleep(1);
    cout << "2. Open the door" << endl;
    sleep(1);
    cout << "3. Give up" << endl;
    cin >> userInput;
 
    while (userInput != 3)
    {
        while (userInput < 1 || userInput > 3)
        {
            cout << "Invalid input, please try again" << endl;
            cin >> userInput;
        }
        if (userInput == 1)
        {
            map.displayMap();
            int user_input2;
            cout << "Select one:" << endl;
            sleep(1);
            cout << "1. Move up" << endl;
            sleep(1);
            cout << "2. Move down" << endl;
            sleep(1);
            cout << "3. Move left" << endl;
            sleep(1);
            cout << "4. Move right" << endl;
            cin >> user_input2;
            while (user_input2 < 1 || user_input2 > 4)
            {
                cout << "Invalid input, please try again or select 0 to cancel" << endl;
                cin >> user_input2;
                if (user_input2 == 0)
                {
                    break;
                }
            }
            if (user_input2 == 1) //user wants to move up
            {
                map.move('w');
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    if (temp_action.getClearedRooms() == 5)
                    {
                       npc.setSuccess(true); //if user is at the exit and has cleared all of the rooms
                       return -1;
                    }
                }
                temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
                temp_user.fullnessDrop(temp_user, temp_action);
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false)
                {
                    if (temp_action.getClearedRooms() < 5)
                    {
                        if (temp_user.getAngerLevel() < 100)
                        {
                            int anger = temp_user.getAngerLevel() + 1; //anger level will increase if space isnt explored and cleared rooms isnt 5
                            temp_user.setAngerLevel(anger);
                        }
                        if (temp_user.getAngerLevel() == 100)
                        {
                            cout << "The sorcerer's anger got to 100" << endl; //if anger level is 100 then fail
                            cout << "You have failed." << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
                temp_user.displayStatus(temp_user, map, temp_action);
                if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                    int room = temp_user.npcMenu(temp_action, map, temp_user, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a npc location then show npc menu and if npc menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        return 1; //if it is a npc location then show npc menu and if npc menu returns somethign other then -1, return 1
                    }
                }
                else
                {
                    return 1; //if it isnt a room
                }
            }
            else if (user_input2 == 2) //if user wants to move down
            {
                map.move('s');
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    if (temp_action.getClearedRooms() == 5)
                    {
                       npc.setSuccess(true); //if user is at the exit and has cleared all of the rooms
                       return -1;
                    }
                }
                temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
                temp_user.fullnessDrop(temp_user, temp_action);
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false)
                {
                    if (temp_action.getClearedRooms() < 5)
                    {
                        if (temp_user.getAngerLevel() < 100)
                        {
                            int anger = temp_user.getAngerLevel() + 1; //anger level will increase if space isnt explored and cleared rooms isnt 5
                            temp_user.setAngerLevel(anger);
                        }
                        if (temp_user.getAngerLevel() == 100)
                        {
                            cout << "The sorcerer's anger got to 100" << endl; //if anger level is 100 then fail
                            cout << "You have failed." << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
                temp_user.displayStatus(temp_user, map, temp_action);
                if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                    int room = temp_user.npcMenu(temp_action, map, temp_user, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a npc location then show npc menu and if npc menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        return 1; //if it is a npc location then show npc menu and if npc menu returns somethign other then -1, return 1
                    }
                }
                else
                {
                    return 1; //if it isnt a room
                }
            }
            else if (user_input2 == 3) //if user wants to move to the left
            {
                map.move('a');
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    if (temp_action.getClearedRooms() == 5)
                    {
                       npc.setSuccess(true); //if user is at the exit and has cleared all of the rooms
                       return -1;
                    }
                }
                temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
                temp_user.fullnessDrop(temp_user, temp_action);
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false)
                {
                    if (temp_action.getClearedRooms() < 5)
                    {
                        if (temp_user.getAngerLevel() < 100)
                        {
                            int anger = temp_user.getAngerLevel() + 1; //anger level will increase if space isnt explored and cleared rooms isnt 5
                            temp_user.setAngerLevel(anger);
                        }
                        if (temp_user.getAngerLevel() == 100)
                        {
                            cout << "The sorcerer's anger got to 100" << endl; //if anger level is 100 then fail
                            cout << "You have failed." << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
                temp_user.displayStatus(temp_user, map, temp_action);
                if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                    int room = temp_user.npcMenu(temp_action, map, temp_user, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a npc location then show npc menu and if npc menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        return 1; //if it is a npc location then show npc menu and if npc menu returns somethign other then -1, return 1
                    }
                }
                else
                {
                    return 1; //if it isnt a room
                }
            }
            else if (user_input2 == 4) //if user wants to move to the right
            {
                map.move('d');
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    if (temp_action.getClearedRooms() == 5)
                    {
                       npc.setSuccess(true); //if user is at the exit and has cleared all of the rooms
                       return -1;
                    }
                }
                temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
                temp_user.fullnessDrop(temp_user, temp_action);
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false)
                {
                    if (temp_action.getClearedRooms() < 5)
                    {
                        if (temp_user.getAngerLevel() < 100)
                        {
                            int anger = temp_user.getAngerLevel() + 1; //anger level will increase if space isnt explored and cleared rooms isnt 5
                            temp_user.setAngerLevel(anger);
                        }
                        if (temp_user.getAngerLevel() == 100)
                        {
                            cout << "The sorcerer's anger got to 100" << endl; //if anger level is 100 then fail
                            cout << "You have failed." << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
                temp_user.displayStatus(temp_user, map, temp_action);
                if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                    int room = temp_user.npcMenu(temp_action, map, temp_user, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a npc location then show npc menu and if npc menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        return 1; //if it is a npc location then show npc menu and if npc menu returns somethign other then -1, return 1
                    }  
                }
                else
                {
                    return 1; //if it isnt a room
                } 
            }
        }
        else if (userInput == 2)
        {
            temp_action.setTurnsElapsed(temp_action.getTurnsElapsed() + 1);
            if (temp_user.getUserKey() > 0)
            {
                if (temp_user.fightingMonster(map, temp_user, temp_action) == -1)
                {
                    return -1;
                }
                temp_action.setClearedRooms(temp_action.getClearedRooms() + 1);
                //misfortune
                srand(time(0));
                if ((rand() % (80 - 1 + 1) + 1) % 4 < 32) //40% chance
                {
                    if  ((rand() % (80 - 1 + 1) + 1) % 4 < 24) //30% chance
                    {
                        int count = 0;
                        for (int i = 0; i < 5; i++)
                        {
                            if (temp_user.getPlayersFullness(i) > 0)
                            {
                                count++; //gets how many players are still alive
                            }
                        }
                        count = count - 1;
                        int choice = (rand() % (count - 1 + 1) + 1); //get a rand number in between the players that are alive
                        int full = 0;
                        for (int i = 0; i < 5; i++)
                        {
                            if (temp_user.getPlayersFullness(i) > 0)
                            {
                                full++;
                            }
                        }
                        if (choice == 1) //if rand gets 1
                        {
                            cout << "OH NO! Your teammate " << temp_user.getPlayers(1) << " is trapped in the previous room and is unable to get through. You must continue without them." << endl;
                            temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), 0, temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                            cout << "Your party size has reduced to " << count << " members. " << endl;
                            full = full - 1;
                            if (full < 2) //checks if there are still enough players to continue
                            {
                                cout << "You have too little players to continue sadly, you have failed :( " << endl;
                                temp_action.setEndGame(true);
                                return -1;
                            }
                        }
                        else if (choice == 2) //if rand gets 2
                        {
                            cout << "OH NO! Your teammate " << temp_user.getPlayers(2) << " is trapped in the previous room and is unable to get through. You must continue without them." << endl;
                            temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), 0, temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                            cout << "Your party size has reduced to " << count << " members. " << endl;
                            full = full - 1;
                            if (full < 2) //checks if there are still enough players to continue
                            {
                                cout << "You have too little players to continue sadly, you have failed :( " << endl;
                                temp_action.setEndGame(true);
                                return -1;
                            }
                        }
                        else if (choice == 3) //if rand gets 3
                        {
                            cout << "OH NO! Your teammate " << temp_user.getPlayers(3) << " is trapped in the previous room and is unable to get through. You must continue without them." << endl;
                            temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), 0, temp_user.getPlayersFullness(4));
                            cout << "Your party size has reduced to " << count << " members. " << endl;
                            full = full - 1;
                            if (full < 2) //checks if there are still enough players to continue
                            {
                                cout << "You have too little players to continue sadly, you have failed :( " << endl;
                                temp_action.setEndGame(true);
                                return -1;
                            }
                        }
                        else if (choice == 4) //if rand gets 4
                        {
                            cout << "OH NO! Your teammate " << temp_user.getPlayers(4) << " is trapped in the previous room and is unable to get through. You must continue without them." << endl;
                            temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), 0);
                            cout << "Your party size has reduced to " << count << " members. " << endl;
                            full = full - 1;
                            if (full < 2) //checks if there are still enough players to continue
                            {
                                cout << "You have too little players to continue sadly, you have failed :( " << endl;
                                temp_action.setEndGame(true);
                                return -1;
                            }
                        }
                        if (count < 2) //checks if there are still enough players to continue
                        {
                            cout << "You have too little players to continue sadly, you have failed :( " << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
            }
            else //user doesn't have any keys 
            {
                bool puzzle = npc.rpsPuzzle();
                if (puzzle == true) //if user completed the puzzle successfully
                {
                    cout << "Congrats, you have passed the puzzle" << endl;
                    int fight = temp_user.fightingMonster(map, temp_user, temp_action);
                    if (fight == -1)
                    {
                        return -1;
                    }
                    else 
                    {
                        return 1;
                    }
                }
                else if (puzzle == false) //if user got puzzle wrong
                {
                    cout << "You have lost one party member." << endl;
                    int count2 = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        if (temp_user.getPlayersFullness(i) > 0)
                        {
                            count2++;
                        } 
                    }
                    if (count2 >= 2)
                    {
                        int check = 0;
                        count2 = count2 - 1;
                        int randNum = (rand() % (count2 - 1 + 1) + 1);
                        cout << temp_user.getPlayers(randNum) << " has died." << endl;
                        for (int i = 0; i < 4; i++)
                        {
                            if (randNum == 1) //next few lines check if the player is already dead, if so generate a new randNum or break if player already died
                            {
                                if (check != -1)
                                {
                                    if (temp_user.getPlayersFullness(1) > 0)
                                    {
                                        temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), 0, temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                                        check = -1;
                                    }
                                    else
                                    {
                                        randNum = 0;
                                        while (randNum == 1)
                                        {
                                            randNum = (rand() % (count2 - 1 + 1) + 1);
                                        } 
                                    } 
                                } 
                                else
                                {
                                    break;
                                }
                            }
                            if (randNum == 2) //next few lines check if the player is already dead, if so generate a new randNum or break if player already died
                            {
                                if (check != -1)
                                {
                                    if (temp_user.getPlayersFullness(2) > 0)
                                    {
                                        temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), 0, temp_user.getPlayersFullness(3), temp_user.getPlayersFullness(4));
                                        check = -1;
                                    }  
                                    else
                                    {
                                        randNum = 0;
                                        while (randNum == 2)
                                        {
                                            randNum = (rand() % (count2 - 1 + 1) + 1);
                                        } 
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }
                            if (randNum == 3) //next few lines check if the player is already dead, if so generate a new randNum or break if player already died
                            {
                                if (check != 1)
                                {
                                    if (temp_user.getPlayersFullness(3) > 0)
                                    {
                                        temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), 0, temp_user.getPlayersFullness(4));
                                        check = -1;
                                    }
                                    else
                                    {
                                        randNum = 0;
                                        while (randNum == 3)
                                        {
                                            randNum = (rand() % (count2 - 1 + 1) + 1);
                                        } 
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }
                            if (randNum == 4) //next few lines check if the player is already dead, if so generate a new randNum or break if player already died
                            {
                                if (check != 1)
                                {
                                    if (temp_user.getPlayersFullness(4) > 0)
                                    {
                                        temp_user.setPlayersFullness(temp_user.getPlayersFullness(0), temp_user.getPlayersFullness(1), temp_user.getPlayersFullness(2), temp_user.getPlayersFullness(3), 0);
                                        check = -1;
                                    }
                                    else
                                    {
                                        randNum = 0;
                                        while (randNum == 4)
                                        {
                                            randNum = (rand() % (count2 - 1 + 1) + 1);
                                        } 
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        if (count2 == 1)
                        {
                            cout << "You have too little players to continue sadly, you have failed :( " << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                        temp_user.displayStatus(temp_user, map, temp_action);
                    }
                    else
                    {
                        cout << "You have too little players to continue sadly, you have failed :( " << endl;
                        temp_action.setEndGame(true);
                        return -1;
                    }
                    if (count2 == 1)
                    {
                        cout << "You have too little players to continue sadly, you have failed :( " << endl;
                        temp_action.setEndGame(true);
                        return -1;
                    }
                    return 1;
                }
            }
        }
    }
    if (userInput == 3)
    {
        temp_action.setEndGame(true);
        return -1;
    }
    return 1;
}
//--------------------------------------------------------------------------------------------------
int User::npcMenu(Action &temp_action, Map &map, User &temp_user, NPC &npc, Merchant &temp_merchant)
{
    int userInput = 0;
    while (userInput != 3)
    {
        cout << "Select one:" << endl;
        sleep(1);
        cout << "1. Move" << endl;
        sleep(1);
        cout << "2. Speak to NPC" << endl;
        sleep(1);
        cout << "3. Give up" << endl;
        cin >> userInput;
        while (userInput < 1 || userInput > 3)
        {
            cout << "Invalid input, please try again" << endl;
            cin >> userInput;
        }
        if (userInput == 1)
        {
            map.displayMap();
            int user_input2;
            cout << "Select one:" << endl;
            sleep(1);
            cout << "1. Move up" << endl;
            sleep(1);
            cout << "2. Move down" << endl;
            sleep(1);
            cout << "3. Move left" << endl;
            sleep(1);
            cout << "4. Move right" << endl;
            cin >> user_input2;
            while (user_input2 < 1 || user_input2 > 4)
            {
                cout << "Invalid input, please try again or select 0 to cancel" << endl;
                cin >> user_input2;
                if (user_input2 == 0)
                {
                    break;
                }
            }
            if (user_input2 == 1) //if user choses to move up
            {
                map.move('w');
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    if (temp_action.getClearedRooms() == 5)
                    {
                       npc.setSuccess(true); //if user is at the exit and has cleared all of the rooms
                       return -1;
                    }
                }
                temp_user.fullnessDrop(temp_user, temp_action);
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false) 
                {
                    if (temp_action.getClearedRooms() < 5) 
                    {
                        if (temp_user.getAngerLevel() < 100)
                        {
                            int anger = temp_user.getAngerLevel() + 1; //anger level will increase if space isnt explored and cleared rooms isnt 5
                            temp_user.setAngerLevel(anger);
                        }
                        if (temp_user.getAngerLevel() == 100) //if anger level is at 100 then fail
                        {
                            cout << "The sorcerer's anger got to 100" << endl;
                            cout << "You have failed." << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
                temp_user.displayStatus(temp_user, map, temp_action);
                if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    int room = temp_user.roomMenu(temp_user, temp_action, map, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a room location then show room menu and if room menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        return 1; //if it is a room location then show room menu and if room menu returns somethign other then -1, return 1
                    }
                }
                else
                {
                    return 1; //if it isnt a room
                }
            }
            else if (user_input2 == 2) //if user choses to move down
            {
                map.move('s');
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    if (temp_action.getClearedRooms() == 5)
                    {
                       npc.setSuccess(true); //if user is at the exit and has cleared all of the rooms
                       return -1;
                    }
                }
                temp_user.fullnessDrop(temp_user, temp_action);
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false)
                {
                    if (temp_action.getClearedRooms() < 5)
                    {
                        if (temp_user.getAngerLevel() < 100)
                        {
                            int anger = temp_user.getAngerLevel() + 1;//anger level will increase if space isnt explored and cleared rooms isnt 5
                            temp_user.setAngerLevel(anger);
                        }
                        if (temp_user.getAngerLevel() == 100)
                        {
                            cout << "The sorcerer's anger got to 100" << endl; //if anger level is 100 then fail
                            cout << "You have failed." << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
                temp_user.displayStatus(temp_user, map, temp_action);
                if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    int room = temp_user.roomMenu(temp_user, temp_action, map, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a room location then show room menu and if room menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        return 1; //if it is a room location then show room menu and if room menu returns somethign other then -1, return 1
                    }
                }
                else
                {
                    return 1; //if it isnt a room
                }
            }
            else if (user_input2 == 3) //if user choses to move left
            {
                map.move('a');
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    if (temp_action.getClearedRooms() == 5)
                    {
                       npc.setSuccess(true); //if user is at the exit and has cleared all of the rooms
                       return -1;
                    }
                }
                temp_user.fullnessDrop(temp_user, temp_action);
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false)
                {
                    if (temp_action.getClearedRooms() < 5)
                    {
                        if (temp_user.getAngerLevel() < 100)
                        {
                            int anger = temp_user.getAngerLevel() + 1; //anger level will increase if space isnt explored and cleared rooms isnt 5
                            temp_user.setAngerLevel(anger);
                        }
                        if (temp_user.getAngerLevel() == 100)
                        {
                            cout << "The sorcerer's anger got to 100" << endl; //if anger level is 100 then fail
                            cout << "You have failed." << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
                temp_user.displayStatus(temp_user, map, temp_action);
                if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    int room = temp_user.roomMenu(temp_user, temp_action, map, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a room location then show room menu and if room menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        return 1; //if it is a room location then show room menu and if room menu returns somethign other then -1, return 1
                    }
                }
                else
                {
                    return 1; //if it isnt a room
                }
            }
            else if (user_input2 == 4) //if user choses to move right
            {
                map.move('d');
                if (map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    if (temp_action.getClearedRooms() == 5)
                    {
                       npc.setSuccess(true); //if user is at the exit and has cleared all of the rooms
                       return -1;
                    }
                }
                temp_user.fullnessDrop(temp_user, temp_action);
                if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()) == false)
                {
                    if (temp_action.getClearedRooms() < 5)
                    {
                        if (temp_user.getAngerLevel() < 100)
                        {
                            int anger = temp_user.getAngerLevel() + 1; //anger level will increase if space isnt explored and cleared rooms isnt 5
                            temp_user.setAngerLevel(anger);
                        }
                        if (temp_user.getAngerLevel() == 100)
                        {
                            cout << "The sorcerer's anger got to 100" << endl; //if anger level is 100 then fail
                            cout << "You have failed." << endl;
                            temp_action.setEndGame(true);
                            return -1;
                        }
                    }
                }
                temp_user.displayStatus(temp_user, map, temp_action);
                if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) == true)
                {
                    int room = temp_user.roomMenu(temp_user, temp_action, map, npc, temp_merchant);
                    if (room == -1)
                    {
                        return -1; //if it is a room location then show room menu and if room menu returns -1, then return -1 which will end the game 
                    }
                    else
                    {
                        return 1; //if it is a room location then show room menu and if room menu returns somethign other then -1, return 1
                    }
                }
                else
                {
                    return 1; //if it isnt a room
                }
            }
        }
        else if (userInput == 2)
        {
            if (temp_action.getClearedRooms() < 5)
            {
                map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
                cout << "Ready to solve a puzzle?!" << endl;
                if (npc.npcPuzzle(npc) == true) //if they got the riddle correct
                {
                    int userOption = 0;
                    cout << "Select one:" << endl;
                    cout << "(1) Enter the menu to and buy/sell supplies" << endl;
                    cout << "(2) Don't enter menu and continue on" << endl;
                    cin >> userOption;
                    while (userOption != 1 && userOption != 2)
                    {
                        cout << "Invalid input, please enter either 1 or 2" << endl;
                        cin >> userOption;
                    }
                    if (userOption == 1)
                    {
                       temp_user.displayMenu(temp_user, temp_merchant, temp_action); 
                       return 1;
                    }
                    else if (userOption == 2)
                    {
                        return 1;
                    }
                }
                else //if the user got the riddle wrong
                {
                    if (temp_user.fightingMonster(map, temp_user, temp_action) == -1)
                    {
                        return -1; //if fighting monster returns -1, return -1 which will end the game
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
            else //if space is already explored
            {
                cout << "You cannot do this task anymore." << endl;
            }
            temp_user.displayStatus(temp_user, map, temp_action);
        }
        else if (userInput == 3) //if user wants to give up
        {
            return -1;
        }
    }
    return 1;
}
int User::displayMenu(User &temp_user, Merchant &temp_merchant, Action &temp_action)
{
   int user_input = 0;
   while (user_input != 6)
   {
       cout << "+-------------+" << endl;
       cout << "| INVENTORY   |" << endl;
       cout << "+-------------+" << endl;
       sleep(1);
       cout << "| Gold        | " << temp_user.getUserGold() << endl;
       sleep(1);
       cout << "| Ingredients | " << temp_user.getUserIngredients() << " kg" << endl;
       sleep(1);
       cout << "| Cookware    | P: " << temp_user.getUserCookware(0) << " | F: " << temp_user.getUserCookware(1) << " | C: " << temp_user.getUserCookware(2)<< endl;
       sleep(1);
       cout << "| Weapons     | C: " << temp_user.getUserWeapons(0) << " | S: " << temp_user.getUserWeapons(1) << " | R: " << temp_user.getUserWeapons(2) << " | B: " << temp_user.getUserWeapons(3) << " | L: " << temp_user.getUserWeapons(4) << endl;
       sleep(1);
       cout << "| Armor       | " << temp_user.getUserArmor() << endl;
       sleep(1);
       cout << "| Treasures   | R: " << temp_user.getUserTreasures(0) << " | N: " << temp_user.getUserTreasures(1) << " | B: " << temp_user.getUserTreasures(2) << " | C: " << temp_user.getUserTreasures(3) << " | G: " << temp_user.getUserTreasures(4)<< endl;
       sleep(1);
       cout << endl;
       cout << "Choose one of the following:" << endl;
       sleep(1);
       cout << " 1. Ingredients: To make food, you have to cook raw ingredients." << endl;
       sleep(1);
       cout << " 2. Cookware: You will need something to cook those ingredients." << endl;
       sleep(1);
       cout << " 3. Weapons: It's dangerous to go alone, take this!" << endl;
       sleep(1);
       cout << " 4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
       sleep(1);
       cout << " 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
       sleep(1);
       cout << " 6. Leave: Make sure you get everything you need, I'm leaving after this sale." << endl;
       sleep(1);
       cin >> user_input;
       while (user_input < 1 || user_input > 6)
       {
           cout << "Invalid input, please try again" << endl;
           cin >> user_input;
       }
       if (user_input == 1)
       {
           int user_ingredients = 0;
           cout << "I recommend you purchase at least 10 kg of ingredients per person" << endl;
           cout << "How many kg of ingredients do you need? (Enter a positive mulitple of 5, or 0 to cancel)" << endl;
           cin >> user_ingredients;
           while (user_ingredients % 5 != 0)
           {
               cout << "Input must be a multiple of 5, please try again" << endl;
               cin >> user_ingredients;
           }
           if (user_ingredients > 0)
           {
               while (temp_merchant.merchantPriceIngredients(temp_action.getClearedRooms(), user_ingredients) > temp_user.getUserGold()) //if the user doesnt have enough gold
               {
                   cout << "Not enough gold, please choose a different quantity or 0 to cancel" << endl;
                   cout << "The price is " << temp_merchant.merchantPriceIngredients(temp_action.getClearedRooms(), user_ingredients) << endl;
                   cout << "You have " << temp_user.getUserGold() << "gold." << endl;
                   cin >> user_ingredients;
                   if (user_ingredients == 0)
                   {
                       cout << "No problem, is there anything else I can get you?" << endl;
                       sleep(2);
                       break;
                   }
                   while (user_ingredients % 5 != 0)
                   {
                       cout << "Input must be a multiple of 5, please try again" << endl;
                       cin >> user_ingredients;
                   }
               }
               if (temp_merchant.merchantPriceIngredients(temp_action.getClearedRooms(), user_ingredients) <= temp_user.getUserGold())
               {
                   char user;
                   cout << "You want to buy " << user_ingredients << " kg of ingredients for " << temp_merchant.merchantPriceIngredients(temp_action.getClearedRooms(), user_ingredients) << " Gold? (y/n)" << endl;
                   cin >> user;
                   while (user != 'y' && user != 'n')
                   {
                       cout << "Please enter either y or n" << endl;
                       cin >> user_ingredients;
                   }
                   if (user == 'y')
                   {
                       int gold = temp_user.getUserGold() - temp_merchant.merchantPriceIngredients(temp_action.getClearedRooms(), user_ingredients);
                       temp_user.setUserGold(gold);
                       int ingredients2 = user_ingredients + temp_user.getUserIngredients();
                       temp_user.setUserIngredients(ingredients2);
                       temp_merchant.setIngredients(temp_merchant.getIngredients() + user_ingredients);
                       cout << "Thank you for your patronage! What else can I get for you?" << endl;
                       sleep(2);
                   }
                   else
                   {
                       cout << "No problem, is there anything else I can get you?" << endl;
                       sleep(2);
                   } 
               }
           }
           else
           {
               cout << "No problem, is there anything else I can get you?" << endl;
               sleep(2);
           }
       }
       else if (user_input == 2)
       {
           int cookware = 0;
           cout << "I have a several types of cookware, which one would you like?" << endl;
           cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
           cout << "Choose one of the following:" << endl;
           cout << " 1. (25%) Ceramic Pot [" << temp_merchant.merchantPriceCookware(temp_action.getClearedRooms(), 1) << " gold]" << endl;
           cout << " 2. (10%) Frying Pan[" << temp_merchant.merchantPriceCookware(temp_action.getClearedRooms(), 2) << " gold]" << endl;
           cout << " 3. ( 2%) Cauldron[" << temp_merchant.merchantPriceCookware(temp_action.getClearedRooms(), 3) << " gold]" << endl;
           cout << " 4. Cancel" << endl;
           cin >> cookware;
           while (cookware > 4 || cookware < 1)
           {
               cout << "Invalid input, please try again" << endl;
               cin >> cookware;
           }
           if (cookware == 1)
           {
               int num = 0;
               cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
               cin >> num;
               while (num < 0)
               {
                   cout << "Invalid input, please try again" << endl;
                   cin >> num;
               }
               if (num > 0)
               {
                   double price = temp_merchant.merchantPriceCookware(temp_action.getClearedRooms(), 1) * num;
                   while (price > temp_user.getUserGold())
                   {
                       cout << "Not enough gold, please choose a different quantity or 0 to cancel" << endl;
                       cout << "The price is " << temp_merchant.merchantPriceCookware(temp_action.getClearedRooms(), 1) << endl;
                       cout << "You have " << temp_user.getUserGold() << "gold." << endl;
                       cin >> num;
                       while (num < 0)
                       {
                           cout << "Invalid input, please try again" << endl;
                           cin >> num;
                       }
                       if (num == 0)
                       {
                           cout << "No problem, is there anything else I can get you?" << endl;
                           sleep(2);
                           break;
                       }
                       else
                       {
                         price = temp_merchant.merchantPriceCookware(temp_action.getClearedRooms(), 1) * num; 
                       }
                   }
                   if (price <= temp_user.getUserGold())
                   {
                       char user;
                       cout << "You want to buy " << num << " pot(s) for " << price << " Gold? (y/n)" << endl;
                       cin >> user;
                       while (user != 'y' && user != 'n')
                       {
                           cout << "Invalid input, please try again" << endl;
                           cin >> user;
                       }
                       if (user == 'y')
                       {
                           int gold = temp_user.getUserGold() - price;
                           temp_user.setUserGold(gold);
                           int cookware = temp_user.getUserCookware(0) + num;
                           temp_user.setUserCookware(cookware, temp_user.getUserCookware(1), temp_user.getUserCookware(2));
                           cout << "Thank you for your patronage! What else can I get for you?" << endl;
                           temp_merchant.setMerchantPot(temp_merchant.getMerchantPot() + num);
                           sleep(2);
                       }
                       else if (user == 'n')
                       {
                           cout << "No problem, is there anything else I can get you?" << endl;
                           sleep(2);
                       }
                   }
               }
               else if (num == 0)
               {
                   cout << "No problem, is there anything else I can get you?" << endl;
                   sleep(2);
               }
           }
           else if (cookware == 2)
           {
               int num = 0;
               cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
               cin >> num;
               while (num < 0)
               {
                   cout << "Invalid input, please try again" << endl;
                   cin >> num;
               }
               if (num > 0)
               {
                   double price = temp_merchant.merchantPriceCookware(temp_action.getClearedRooms(), 2) * num;
                   while (price > temp_user.getUserGold())
                   {
                       cout << "Not enough gold, please choose a different quantity or 0 to cancel" << endl;
                       cout << "The price is " << temp_merchant.merchantPriceCookware(temp_action.getClearedRooms(), 2) << endl;
                       cout << "You have " << temp_user.getUserGold() << "gold." << endl;
                       cin >> num;
                       while (num < 0)
                       {
                           cout << "Invalid input, please try again" << endl;
                           cin >> num;
                       }
                       if (num == 0)
                       {
                           cout << "No problem, is there anything else I can get you?" << endl;
                           sleep(2);
                           break;
                       }
                       else
                       {
                         price = temp_merchant.merchantPriceCookware(temp_action.getClearedRooms(), 2) * num; 
                       }
                   }
                   if (price <= temp_user.getUserGold())
                   {
                       char user;
                       cout << "You want to buy " << num << " pan(s) for " << price << " Gold? (y/n)" << endl;
                       cin >> user;
                       if (user == 'y')
                       {
                           int gold = temp_user.getUserGold() - price;
                           temp_user.setUserGold(gold);
                           int cookware = temp_user.getUserCookware(1) + num;
                           temp_user.setUserCookware(temp_user.getUserCookware(0), cookware, temp_user.getUserCookware(2));
                           cout << "Thank you for your patronage! What else can I get for you?" << endl;
                           temp_merchant.setMerchantPan(temp_merchant.getMerchantPan() + num);
                           sleep(2);
                       }
                       else if (user == 'n')
                       {
                           cout << "No problem, is there anything else I can get you?" << endl;
                           sleep(2);
                       }
                       else
                       {
                           cout << "Invalid input, please try again" << endl;
                           sleep(2);
                       }
                   }
               }
               else if (num == 0)
               {
                   cout << "No problem, is there anything else I can get you?" << endl;
                   sleep(2);
               }
               else
               {
                   cout << "Invalid input, please try again" << endl;
               }
           }
           else if (cookware == 3)
           {
               int num = 0;
               cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
               cin >> num;
               if (num > 0)
               {
                   double price = temp_merchant.merchantPriceCookware(temp_action.getClearedRooms(), 3) * num;
                   while (price > temp_user.getUserGold())
                   {
                       cout << "Not enough gold, please choose a different quantity or 0 to cancel" << endl;
                       cout << "The price is " << temp_merchant.merchantPriceCookware(temp_action.getClearedRooms(), 3) << endl;
                       cout << "You have " << temp_user.getUserGold() << "gold." << endl;
                       cin >> num;
                       if (num == 0)
                       {
                           cout << "No problem, is there anything else I can get you?" << endl;
                           sleep(2);
                           break;
                       }
                       else
                       {
                         price = temp_merchant.merchantPriceCookware(temp_action.getClearedRooms(), 3) * num; 
                       }
                   }
                   if (price <= temp_user.getUserGold())
                   {
                       char user;
                       cout << "You want to buy " << num << " cauldron(s) for " << price << " Gold? (y/n)" << endl;
                       cin >> user;
                       if (user == 'y')
                       {
                           int gold = temp_user.getUserGold() - price;
                           temp_user.setUserGold(gold);
                           int cookware = temp_user.getUserCookware(2) + num;
                           temp_user.setUserCookware(temp_user.getUserCookware(0), temp_user.getUserCookware(1), cookware);
                           cout << "Thank you for your patronage! What else can I get for you?" << endl;
                           temp_merchant.setMerchantCauldron(temp_merchant.getMerchantCauldron() + num);
                           sleep(2);
                       }
                       else if (user == 'n')
                       {
                           cout << "No problem, is there anything else I can get you?" << endl;
                           sleep(2);
                       }
                       else
                       {
                           cout << "Invalid input, please try again" << endl;
                           sleep(2);
                       }
                   }
               }
               else if (num == 0)
               {
                   cout << "No problem, is there anything else I can get you?" << endl;
                   sleep(2);
               }
               else
               {
                   cout << "Invalid input, please try again" << endl;
               }
           }
           else if (cookware == 4)
           {
               cout << "No problem, is there anything else I can get you?" << endl;
               sleep(2);
           }
       }
       else if (user_input == 3)
       {
           int weapons = 0;
           cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
           cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;
           cout << endl;
           cout << "Choose one of the following:" << endl;
           cout << " 1. Stone Club [" << temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 1) << " gold]" << endl;
           cout << " 2. Iron Spear[" << temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 2) << " gold]" << endl;
           cout << " 3. (+1) Mythril Rapier[" << temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 3) << " gold]" << endl;
           cout << " 4. (+2) Flaming Battle-Axe[" << temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 4) << " gold]" << endl;
           cout << " 5. (+3) Vorpal Longsword[" << temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 5) << " gold]" << endl;
           cout << " 6. Cancel" << endl;
           cin >> weapons;
           if (weapons == 1)
           {
               int num = 0;
               cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
               cin >> num;
               if (num > 0)
               {
                   double price = temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 1) * num;
                   while (price > temp_user.getUserGold())
                   {
                       cout << "Not enough gold, please choose a different quantity or 0 to cancel" << endl;
                       cout << "The price is " << temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 1) << endl;
                       cout << "You have " << temp_user.getUserGold() << "gold." << endl;
                       cin >> num;
                       if (num == 0)
                       {
                           cout << "No problem, is there anything else I can get you?" << endl;
                           sleep(2);
                           break;
                       }
                       else
                       {
                         price = temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 1) * num; 
                       }
                   }
                   if (price <= temp_user.getUserGold())
                   {
                       if (temp_user.getUserWeapons(0) + temp_user.getUserWeapons(1) + temp_user.getUserWeapons(2) + temp_user.getUserWeapons(3) + temp_user.getUserWeapons(4) + num < 6)
                       {
                           char user;
                           cout << "You want to buy " << num << " stone club(s) for " << price << " Gold? (y/n)" << endl;
                           cin >> user;
                           if (user == 'y')
                           {
                               int gold = temp_user.getUserGold() - price;
                               temp_user.setUserGold(gold);
                               int weapons = temp_user.getUserWeapons(0) + num;
                               temp_user.setUserWeapons(weapons, temp_user.getUserWeapons(1), temp_user.getUserWeapons(2), temp_user.getUserWeapons(3), temp_user.getUserWeapons(4));
                               cout << "Thank you for your patronage! What else can I get for you?" << endl;
                               temp_merchant.setMerchantClub(temp_merchant.getMerchantClub() + num);
                               sleep(2);
                           }
                           else if (user == 'n')
                           {
                               cout << "No problem, is there anything else I can get you?" << endl;
                               sleep(2);
                           }
                           else
                           {
                               cout << "Invalid input, please try again" << endl;
                               sleep(2);
                           } 
                       }
                       else
                       {
                           cout << "Not enough room for more weapons, maximum is 5" << endl;
                           cout << "You have " << temp_user.getUserWeapons(0) + temp_user.getUserWeapons(1) + temp_user.getUserWeapons(2) + temp_user.getUserWeapons(3) + temp_user.getUserWeapons(4) << endl;
                       }
                   }
               }
               else if (num == 0)
               {
                   cout << "No problem, is there anything else I can get you?" << endl;
                   sleep(2);
               }
               else
               {
                   cout << "Invalid input, please try again" << endl;
               }
           }
           else if (weapons == 2)
           {
               int num = 0;
               cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
               cin >> num;
               if (num > 0)
               {
                   double price = temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 2) * num;
                   while (price > temp_user.getUserGold())
                   {
                       cout << "Not enough gold, please choose a different quantity or 0 to cancel" << endl;
                       cout << "The price is " << temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 2) << endl;
                       cout << "You have " << temp_user.getUserGold() << "gold." << endl;
                       cin >> num;
                       if (num == 0)
                       {
                           cout << "No problem, is there anything else I can get you?" << endl;
                           sleep(2);
                           break;
                       }
                       else
                       {
                         price = temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 2) * num; 
                       }
                   }
                   if (price <= temp_user.getUserGold())
                   {
                       if (temp_user.getUserWeapons(0) + temp_user.getUserWeapons(1) + temp_user.getUserWeapons(2) + temp_user.getUserWeapons(3) + temp_user.getUserWeapons(4) + num < 6)
                       {
                           char user;
                           cout << "You want to buy " << num << " iron spear(s) for " << price << " Gold? (y/n)" << endl;
                           cin >> user;
                           if (user == 'y')
                           {
                               int gold = temp_user.getUserGold() - price;
                               temp_user.setUserGold(gold);
                               int weapons = temp_user.getUserWeapons(1) + num;
                               temp_user.setUserWeapons(temp_user.getUserWeapons(0), weapons, temp_user.getUserWeapons(2), temp_user.getUserWeapons(3), temp_user.getUserWeapons(4));
                               cout << "Thank you for your patronage! What else can I get for you?" << endl;
                               temp_merchant.setMerchantSpear(temp_merchant.getMerchantSpear() + num);
                               sleep(2);
                           }
                           else if (user == 'n')
                           {
                               cout << "No problem, is there anything else I can get you?" << endl;
                               sleep(2);
                           }
                           else
                           {
                               cout << "Invalid input, please try again" << endl;
                               sleep(2);
                           }
                       }
                       else
                       {
                           cout << "Not enough room for more weapons, maximum is 5" << endl;
                           cout << "You have " << temp_user.getUserWeapons(0) + temp_user.getUserWeapons(1) + temp_user.getUserWeapons(2) + temp_user.getUserWeapons(3) + temp_user.getUserWeapons(4) << endl;
                       }
                   }
               }
               else if (num == 0)
               {
                   cout << "No problem, is there anything else I can get you?" << endl;
                   sleep(2);
               }
               else
               {
                   cout << "Invalid input, please try again" << endl;
               }
           }
           else if (weapons == 3)
           {
               int num = 0;
               cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
               cin >> num;
               if (num > 0)
               {
                   double price = temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 3) * num;
                   while (price > temp_user.getUserGold())
                   {
                       cout << "Not enough gold, please choose a different quantity or 0 to cancel" << endl;
                       cout << "The price is " << temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 3) << endl;
                       cout << "You have " << temp_user.getUserGold() << "gold." << endl;
                       cin >> num;
                       if (num == 0)
                       {
                           cout << "No problem, is there anything else I can get you?" << endl;
                           sleep(2);
                           break;
                       }
                       else
                       {
                         price = temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 3) * num; 
                       }
                   }
                   if (price <= temp_user.getUserGold())
                   {
                       if (temp_user.getUserWeapons(0) + temp_user.getUserWeapons(1) + temp_user.getUserWeapons(2) + temp_user.getUserWeapons(3) + temp_user.getUserWeapons(4) + num < 6)
                       {
                           char user;
                           cout << "You want to buy " << num << " (+1) mythril rapier(s) for " << price << " Gold? (y/n)" << endl;
                           cin >> user;
                           if (user == 'y')
                           {
                               int gold = temp_user.getUserGold() - price;
                               temp_user.setUserGold(gold);
                               int weapons = temp_user.getUserWeapons(2) + num;
                               temp_user.setUserWeapons(temp_user.getUserWeapons(0), temp_user.getUserWeapons(1), weapons, temp_user.getUserWeapons(3), temp_user.getUserWeapons(4));
                               cout << "Thank you for your patronage! What else can I get for you?" << endl;
                               temp_merchant.setMerchantRapier(temp_merchant.getMerchantRapier() + num);
                               sleep(2);
                           }
                           else if (user == 'n')
                           {
                               cout << "No problem, is there anything else I can get you?" << endl;
                               sleep(2);
                           }
                           else
                           {
                               cout << "Invalid input, please try again" << endl;
                               sleep(2);
                           }
                       }
                       else
                       {
                           cout << "Not enough room for more weapons, maximum is 5" << endl;
                           cout << "You have " << temp_user.getUserWeapons(0) + temp_user.getUserWeapons(1) + temp_user.getUserWeapons(2) + temp_user.getUserWeapons(3) + temp_user.getUserWeapons(4) << endl;
                       }
                   }
               }
               else if (num == 0)
               {
                   cout << "No problem, is there anything else I can get you?" << endl;
                   sleep(2);
               }
               else
               {
                   cout << "Invalid input, please try again" << endl;
               }
           }
           else if (weapons == 4)
           {
               int num = 0;
               cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
               cin >> num;
               if (num > 0)
               {
                   double price = temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 4) * num;
                   while (price > temp_user.getUserGold())
                   {
                       cout << "Not enough gold, please choose a different quantity or 0 to cancel" << endl;
                       cout << "The price is " << temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 4) << endl;
                       cout << "You have " << temp_user.getUserGold() << "gold." << endl;
                       cin >> num;
                       if (num == 0)
                       {
                           cout << "No problem, is there anything else I can get you?" << endl;
                           sleep(2);
                           break;
                       }
                       else
                       {
                         price = temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 4) * num; 
                       }
                   }
                   if (price <= temp_user.getUserGold())
                   {
                       if (temp_user.getUserWeapons(0) + temp_user.getUserWeapons(1) + temp_user.getUserWeapons(2) + temp_user.getUserWeapons(3) + temp_user.getUserWeapons(4) + num < 6)
                       {
                           char user;
                           cout << "You want to buy " << num << " (+2) flaming battle-axe(s) for " << price << " Gold? (y/n)" << endl;
                           cin >> user;
                           if (user == 'y')
                           {
                               int gold = temp_user.getUserGold() - price;
                               temp_user.setUserGold(gold);
                               int weapons = temp_user.getUserWeapons(3) + num;
                               temp_user.setUserWeapons(temp_user.getUserWeapons(0), temp_user.getUserWeapons(1), temp_user.getUserWeapons(2), weapons, temp_user.getUserWeapons(4));
                               cout << "Thank you for your patronage! What else can I get for you?" << endl;
                               temp_merchant.setMerchantAxe(temp_merchant.getMerchantAxe() + num);
                               sleep(2);
                           }
                           else if (user == 'n')
                           {
                               cout << "No problem, is there anything else I can get you?" << endl;
                               sleep(2);
                           }
                           else
                           {
                               cout << "Invalid input, please try again" << endl;
                               sleep(2);
                           }
                       }
                       else
                       {
                           cout << "Not enough room for more weapons, maximum is 5" << endl;
                           cout << "You have " << temp_user.getUserWeapons(0) + temp_user.getUserWeapons(1) + temp_user.getUserWeapons(2) + temp_user.getUserWeapons(3) + temp_user.getUserWeapons(4) << endl;
                       }
                   }
               }
               else if (num == 0)
               {
                   cout << "No problem, is there anything else I can get you?" << endl;
                   sleep(2);
               }
               else
               {
                   cout << "Invalid input, please try again" << endl;
               }
           }
           else if (weapons == 5)
           {
               int num = 0;
               cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
               cin >> num;
               if (num > 0)
               {
                   double price = temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 5) * num;
                   while (price > temp_user.getUserGold())
                   {
                       cout << "Not enough gold, please choose a different quantity or 0 to cancel" << endl;
                       cout << "The price is " << temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 5) << endl;
                       cout << "You have " << temp_user.getUserGold() << "gold." << endl;
                       cin >> num;
                       if (num == 0)
                       {
                           cout << "No problem, is there anything else I can get you?" << endl;
                           sleep(2);
                           break;
                       }
                       else
                       {
                         price = temp_merchant.merchantPriceWeapons(temp_action.getClearedRooms(), 5) * num; 
                       }
                   }
                   if (price <= temp_user.getUserGold())
                   {
                       if (temp_user.getUserWeapons(0) + temp_user.getUserWeapons(1) + temp_user.getUserWeapons(2) + temp_user.getUserWeapons(3) + temp_user.getUserWeapons(4) + num < 6)
                       {
                           char user;
                           cout << "You want to buy " << num << " (+3) vorpal longsword(s) for " << price << " Gold? (y/n)" << endl;
                           cin >> user;
                           if (user == 'y')
                           {
                               int gold = temp_user.getUserGold() - price;
                               temp_user.setUserGold(gold);
                               int weapons = temp_user.getUserWeapons(4) + num;
                               temp_user.setUserWeapons(temp_user.getUserWeapons(0), temp_user.getUserWeapons(1), temp_user.getUserWeapons(2), temp_user.getUserWeapons(3), weapons);
                               cout << "Thank you for your patronage! What else can I get for you?" << endl;
                               temp_merchant.setMerchantLongsword(temp_merchant.getMerchantLongsword() + num);
                               sleep(2);
                           }
                           else if (user == 'n')
                           {
                               cout << "No problem, is there anything else I can get you?" << endl;
                               sleep(2);
                           }
                           else
                           {
                               cout << "Invalid input, please try again" << endl;
                               sleep(2);
                           }
                       }
                       else
                       {
                           cout << "Not enough room for more weapons, maximum is 5" << endl;
                           cout << "You have " << temp_user.getUserWeapons(0) + temp_user.getUserWeapons(1) + temp_user.getUserWeapons(2) + temp_user.getUserWeapons(3) + temp_user.getUserWeapons(4) << endl;
                       }
                   }
               }
               else if (num == 0)
               {
                   cout << "No problem, is there anything else I can get you?" << endl;
                   sleep(2);
               }
               else
               {
                   cout << "Invalid input, please try again" << endl;
               }
           }
           else if (weapons == 6)
           {
               cout << "No problem, is there anything else I can get you?" << endl;
               sleep(2);
           }
           else
           {
               cout << "Invalid input, please try again" << endl;
           }
       }
       else if (user_input == 4)
       {
           int num = 0;
           cout << "Equip your team with 1 armor per person and it will maximize your chances of survival during an attack." << endl;
           cout << "How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel)" << endl;
           cin >> num;
           if (num > 0)
           {
               while (temp_merchant.merchantPriceArmor(temp_action.getClearedRooms(), num) > temp_user.getUserGold())
               {
                   cout << "Not enough gold, please choose a different quantity or 0 to cancel" << endl;
                   cout << "The price is " << temp_merchant.merchantPriceArmor(temp_action.getClearedRooms(), num) << endl;
                   cout << "You have " << temp_user.getUserGold() << "gold." << endl;
                   cin >> num;
                   if (num == 0)
                   {
                       cout << "No problem, is there anything else I can get you?" << endl;
                       sleep(2);
                       break;
                   }
               }
               if (temp_merchant.merchantPriceArmor(temp_action.getClearedRooms(), num) <= temp_user.getUserGold())
               {
                   if (temp_user.getUserArmor() + num < 6)
                   {
                       char user;
                       cout << "You want to buy " << num << " suit(s) for " << temp_merchant.merchantPriceArmor(temp_action.getClearedRooms(), num) << " Gold? (y/n)" << endl;
                       cin >> user;
                       if (user == 'y')
                       {
                           int gold = temp_user.getUserGold() - temp_merchant.merchantPriceArmor(temp_action.getClearedRooms(), num);
                           temp_user.setUserGold(gold);
                           temp_user.setUserArmor(temp_user.getUserArmor() + num);
                           temp_merchant.setArmor(temp_merchant.getArmor() + num);
                           cout << "Thank you for your patronage! What else can I get for you?" << endl;
                           sleep(2);
                       }
                       else if (user == 'n')
                       {
                           cout << "No problem, is there anything else I can get you?" << endl;
                           sleep(2);
                       } 
                       else
                       {
                           cout << "Invalid input, please try again" << endl;
                           sleep(2);
                       } 
                   }
                   else
                   {
                       cout << "Not enough room for more armor, there is a maximum of 5" << endl;
                       cout << "You have " << temp_user.getUserArmor() << endl;
                   }
               }
           }
           else if (num == 0)
           {
               cout << "No problem, is there anything else I can get you?" << endl;
               sleep(2);
           }
           else
           {
               cout << "Invalid input, please try again" << endl;
           }
       }
       else if (user_input == 5)
       {
           int treasures = 0;
           cout << "What would you like to sell?" << endl;
           cout << endl;
           cout << "Choose one of the following:" << endl;
           cout << " 1. Ring [" << temp_merchant.merchantPriceTreasures(temp_action.getClearedRooms(), 1) << " gold]" << endl;
           cout << " 2. Necklace [" << temp_merchant.merchantPriceTreasures(temp_action.getClearedRooms(), 2) << " gold]" << endl;
           cout << " 3. Bracelet [" << temp_merchant.merchantPriceTreasures(temp_action.getClearedRooms(), 3) << " gold]" << endl;
           cout << " 4. Circlet [" << temp_merchant.merchantPriceTreasures(temp_action.getClearedRooms(), 4) << " gold]" << endl;
           cout << " 5. Goblet [" << temp_merchant.merchantPriceTreasures(temp_action.getClearedRooms(), 5) << " gold]" << endl;
           cout << " 6. Cancel" << endl;
           cin >> treasures;
           if (treasures == 1)
           {
               if (temp_action.getClearedRooms() >= 1)
               {
                   int num = 0;
                   cout << "How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                   cin >> num;
                   if (num > 0)
                   {
                       if (num <= temp_user.getUserTreasures(0))
                       {
                           double price = temp_merchant.merchantPriceTreasures(temp_action.getClearedRooms(), 1) * num;
                           char user;
                           cout << "You want to sell " << num << " ring(s) for " << price << " Gold? (y/n)" << endl;
                           cin >> user;
                           if (user == 'y')
                           {
                               int gold = temp_user.getUserGold() + price; //adds the gold then ring was worth
                               temp_user.setUserGold(gold);
                               int treasures = num - temp_user.getUserTreasures(0);
                               temp_user.setUserTreasures(treasures, temp_user.getUserTreasures(1), temp_user.getUserTreasures(2), temp_user.getUserTreasures(3), temp_user.getUserTreasures(4));
                               temp_merchant.setMerchantRing(temp_merchant.getMerchantRing() + num);
                               cout << "Very pretty!" << endl;
                               sleep(2);
                           }
                           else if (user == 'n')
                           {
                               cout << "No problem, is there anything else I can get you?" << endl;
                               sleep(2);
                           }
                           else
                           {
                               cout << "Invalid input, please try again" << endl;
                           } 
                       }
                       else
                       {
                           cout << "You don't have that many rings" << endl;
                       }
                   }
                   else if (num == 0)
                   {
                       cout << "No problem, is there anything else I can get you?" << endl;
                       sleep(2);
                   }
                   else
                   {
                       cout << "Invalid input, please try again" << endl;
                   }
               }
               else
               {
                   cout << "You must clear more rooms" << endl;
               }
           }
           else if (treasures == 2)
           {
               if (temp_action.getClearedRooms() >= 2)
               {
                   int num = 0;
                   cout << "How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                   cin >> num;
                   if (num > 0)
                   {
                       if (num <= temp_user.getUserTreasures(1))
                       {
                           double price = temp_merchant.merchantPriceTreasures(temp_action.getClearedRooms(), 2) * num;
                           char user;
                           cout << "You want to sell " << num << " necklace(s) for " << price << " Gold? (y/n)" << endl;
                           cin >> user;
                           if (user == 'y')
                           {
                               int gold = temp_user.getUserGold() + price; //adds the gold then necklace was worth
                               temp_user.setUserGold(gold);
                               int treasures = num - temp_user.getUserTreasures(1);
                               temp_user.setUserTreasures(temp_user.getUserTreasures(0), treasures, temp_user.getUserTreasures(2), temp_user.getUserTreasures(3), temp_user.getUserTreasures(4));
                               temp_merchant.setMerchantNecklace(temp_merchant.getMerchantNecklace() + num);
                               cout << "Very pretty!" << endl;
                               sleep(2);
                           }
                           else if (user == 'n')
                           {
                               cout << "No problem, is there anything else I can get you?" << endl;
                               sleep(2);
                           }
                           else
                           {
                               cout << "Invalid input, please try again" << endl;
                           }
                       }
                       else
                       {
                           cout << "You don't have that many necklaces" << endl;
                       }
                   }
                   else if (num == 0)
                   {
                       cout << "No problem, is there anything else I can get you?" << endl;
                       sleep(2);
                   }
                   else
                   {
                       cout << "Invalid input, please try again" << endl;
                   }
               }
               else
               {
                   cout << "You must clear more rooms" << endl;
               }
           }
           else if (treasures == 3)
           {
               if (temp_action.getClearedRooms() >= 3)
               {
                   int num = 0;
                   cout << "How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                   cin >> num;
                   if (num > 0)
                   {
                       if (num <= temp_user.getUserTreasures(1))
                       {
                           double price = temp_merchant.merchantPriceTreasures(temp_action.getClearedRooms(), 3) * num;
                           char user;
                           cout << "You want to sell " << num << " bracelet(s) for " << price << " Gold? (y/n)" << endl;
                           cin >> user;
                           if (user == 'y')
                           {
                               int gold = temp_user.getUserGold() + price; //adds the gold then bracelet was worth
                               temp_user.setUserGold(gold);
                               int treasures = num - temp_user.getUserTreasures(2);
                               temp_user.setUserTreasures(temp_user.getUserTreasures(0), temp_user.getUserTreasures(1), treasures, temp_user.getUserTreasures(3), temp_user.getUserTreasures(4));
                               temp_merchant.setMerchantBracelet(temp_merchant.getMerchantBracelet() + num);
                               cout << "Very pretty!" << endl;
                               sleep(2);
                           }
                           else if (user == 'n')
                           {
                               cout << "No problem, is there anything else I can get you?" << endl;
                               sleep(2);
                           }
                           else
                           {
                               cout << "Invalid input, please try again" << endl;
                           }
                       }
                       else
                       {
                           cout << "You don't have that many bracelets" << endl;
                       }
                   }
                   else if (num == 0)
                   {
                       cout << "No problem, is there anything else I can get you?" << endl;
                       sleep(2);
                   }
                   else
                   {
                       cout << "Invalid input, please try again" << endl;
                   }
               }
               else
               {
                   cout << "You must clear more rooms" << endl;
               }
           }
           else if (treasures == 4)
           {
               if (temp_action.getClearedRooms() >= 4)
               {
                   int num = 0;
                   cout << "How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                   cin >> num;
                   if (num > 0)
                   {
                       if (num <= temp_user.getUserTreasures(1))
                       {
                           double price = temp_merchant.merchantPriceTreasures(temp_action.getClearedRooms(), 4) * num;
                           char user;
                           cout << "You want to sell " << num << " circlet(s) for " << price << " Gold? (y/n)" << endl;
                           cin >> user;
                           if (user == 'y')
                           {
                               int gold = temp_user.getUserGold() + price; //adds the gold then circlet was worth
                               temp_user.setUserGold(gold);
                               int treasures = num - temp_user.getUserTreasures(3);
                               temp_user.setUserTreasures(temp_user.getUserTreasures(0), temp_user.getUserTreasures(1), temp_user.getUserTreasures(2), treasures, temp_user.getUserTreasures(4));
                               temp_merchant.setMerchantCirclet(temp_merchant.getMerchantCirclet() + num);
                               cout << "Very pretty!" << endl;
                               sleep(2);
                           }
                           else if (user == 'n')
                           {
                               cout << "No problem, is there anything else I can get you?" << endl;
                               sleep(2);
                           }
                           else
                           {
                               cout << "Invalid input, please try again" << endl;
                           }
                       }
                       else
                       {
                           cout << "You don't have that many circlets" << endl;
                       }
                   }
                   else if (num == 0)
                   {
                       cout << "No problem, is there anything else I can get you?" << endl;
                       sleep(2);
                   }
                   else
                   {
                       cout << "Invalid input, please try again" << endl;
                   }
               }
               else
               {
                   cout << "You must clear more rooms" << endl;
               }
           }
           else if (treasures == 5)
           {
               if (temp_action.getClearedRooms() == 5)
               {
                   int num = 0;
                   cout << "How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                   cin >> num;
                   if (num > 0)
                   {
                       if (num <= temp_user.getUserTreasures(1))
                       {
                           double price = temp_merchant.merchantPriceTreasures(temp_action.getClearedRooms(), 5) * num;
                           char user;
                           cout << "You want to sell " << num << " goblet(s) for " << price << " Gold? (y/n)" << endl;
                           cin >> user;
                           if (user == 'y')
                           {
                               int gold = temp_user.getUserGold() + price; //adds the gold then goblet was worth
                               temp_user.setUserGold(gold);
                               int treasures = num - temp_user.getUserTreasures(4);
                               temp_user.setUserTreasures(temp_user.getUserTreasures(0), temp_user.getUserTreasures(1), temp_user.getUserTreasures(2), temp_user.getUserTreasures(3), treasures);
                               temp_merchant.setMerchantGoblet(temp_merchant.getMerchantGoblet() + num);
                               cout << "Very pretty!" << endl;
                               sleep(2);
                           }
                           else if (user == 'n')
                           {
                               cout << "No problem, is there anything else I can get you?" << endl;
                               sleep(2);
                           }
                           else
                           {
                               cout << "Invalid input, please try again" << endl;
                           }
                       }
                       else
                       {
                           cout << "You don't have that many goblets" << endl;
                       }
                   }
                   else if (num == 0)
                   {
                       cout << "No problem, is there anything else I can get you?" << endl;
                       sleep(2);
                   }
                   else
                   {
                       cout << "Invalid input, please try again" << endl;
                   }
               }
               else
               {
                   cout << "You must clear more rooms" << endl;
               }
           }
           else if (treasures == 6)
           {
               cout << "No problem, is there anything else I can get you?" << endl;
               sleep(2);
           }
           else
           {
               cout << "Invalid input, please try again" << endl;
           }
       }
   }
   if (user_input == 6)
   {
       cout << "Good luck out there!" << endl;
       return 1;
   }
   return 1;
}