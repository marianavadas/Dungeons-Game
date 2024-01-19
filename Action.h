// CSCI 1300 Fall 2022
// Authors: Mariana Vadas-Arendt and Daria Ruchala
// Project 3

#ifndef ACTION_H
#define ACTION_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Action
{
  private:
      int monstersDefeated; //stores how many monsters have been defeated 
      int turnsElapsed; //stores how many turns have been taken
      bool endGame; //is used to check if game should end
      int clearedRooms; //stores the number of rooms the user has cleared

   public:
      Action();
      Action (int monstersDefeated_, int turnsElapsed_, int clearedRooms_, bool endGame_);

      void setEndGame(bool endGame_);
      bool getEndGame();

      int getMonstersDefeated();
      void setMonstersDefeated(int monstersDefeated_);

      int getTurnsElapsed();
      void setTurnsElapsed(int turnsElapsed_);

      int getClearedRooms();
      void setClearedRooms(int numRooms);
};
#endif