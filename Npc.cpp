// CSCI 1300 Fall 2022
// Authors: Mariana Vadas-Arendt and Daria Ruchala
// Project 3
#include "Npc.h"
#include "unistd.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

NPC:: NPC(bool success_)
{
  success = success_;
}
NPC:: NPC()
{
  //here I would just set the success to false
  success = false;
}
bool NPC:: getSuccess()
{
  return success; //it is originally set to false already
}
void NPC:: setSuccess(bool success_)
{
  success = success_; 
}
bool NPC::npcPuzzle(NPC &npc)
{
   ifstream fin;
   string line;
   fin.open("riddles.txt");
   while (!fin.eof()) // continue looping as long as there is data to be processed in the file
   {
       int userRiddle = 0;
       int count = 0;
       string riddleAnswer= "";
       string inputAnswer = "";
       //split function to seperate ~ this
       cout << "Choose a number of your choice between (1-20)!" << endl;
       cin >> userRiddle; // this will detwermine which riddle they get
 
       while (count < userRiddle) //this will get the correct line
       {
           getline(fin, line);
           count++;
       }
       fin.close();
       int location = 0;
       for (int i = 0; i < line.length(); i++) //traversing through line string
       {
           if (line[i] == '~') //if line string of i equals separator
           {
               location = i + 1; //plus one because doesn't include the separator
               riddleAnswer = line.substr(location, line.length() - location);
               line = line.substr(0, location - 2);
           }
       }
       cout << line << endl; //cout the first part of the split function this will be the actual riddle
       cin >> inputAnswer;
       int check = 0;
       for (int i= 0; i < inputAnswer.length()+1; i++) //traverses through inputAnswer string
       {
           if(inputAnswer[i] == riddleAnswer[i]) //checking char by char if they equal eachother, if they dont then set check to -1
           {
               continue;
           }
           else
           {
               check = -1;
           }
       }
 
       if(check == 0)//if the users answer is the same as the string after the split they win
       {
           cout << "Impeccable! I will now sell to you. " << endl;
           return true;
       }
       else
       {
           cout << "Wrong answer" << endl;
           return false;
       }
   }
   return false;
}
//Rock Paper Scissors Door Function !
bool NPC::rpsPuzzle()
{
   int count = 0;
   while (count < 3) //gives user three tries
   {
       int userChoice = 0;
       cout << "Choose your move! " << endl;
       cout << "-----------------" << endl;
       cout << "(1) for Boulder" << endl;
       cout << "(2) for Parchment" << endl;
       cout << "(3) for Shears" << endl;
       cin >> userChoice;
      
       while (userChoice != 1 && userChoice != 2 && userChoice != 3)
       {
           cout << "Invalid input, please try again" << endl;
           cin >> userChoice;
       }
       srand(time(0));
       int computerChoice = (rand() % (3 - 1 + 1) + 1); //getting rand number between 3 and 1
      
       if (userChoice == 1 && computerChoice == 2)
       {
           cout << "Computer Wins! Parchment covers Boulder."<< endl;
           cout << "You have " << 2 - count << " more chance(s)." << endl;
       }
       else if (userChoice == 2 && computerChoice == 3)
       {
           cout << "Computer Wins! Shears cut Parchment."<< endl;
           cout << "You have " << 2 - count << " more chance(s)." << endl;
       }
       else if (userChoice == 3 && computerChoice == 1)
       {
           cout << "Computer Wins! Boulder smashes Shears."<< endl;
           cout << "You have " << 2 - count << " more chance(s)." << endl;
       }
       else if (userChoice == 1 && computerChoice == 3)
       {
           cout << "You Win! Boulder smashes Shears."<< endl;
           return true;
       }
       else if (userChoice == 2 && computerChoice == 1)
       {
           cout << "You Win! Parchment covers Boulder."<< endl;
           return true;
       }
       else if (userChoice == 3 && computerChoice == 2)
       {
           cout << "You Win! Shears cut Parchment."<< endl;
           return true;
       }
       else
       {
           cout << "Tie :( Play again and win the Game." << endl;
           cout << "You have " << 2 - count << " more chance(s)." << endl;
       }
       count++;
       if (3 - count == 0)
       {
            break;
       }
   }
   return false;
}