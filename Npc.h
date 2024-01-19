// CSCI 1300 Fall 2022
// Authors: Mariana Vadas-Arendt and Daria Ruchala
// Project 3

#ifndef NPC_H
#define NPC_H
#include <iostream>
#include <string>
#include <fstream>
#include "Merchant.h"
 
using namespace std;
class NPC
{
   private:
          bool success; //if player has successfully won the game
      
   public:
          NPC();
          NPC(bool success);
   
          bool getSuccess();
          void setSuccess(bool success_);

          bool npcPuzzle(NPC &npc);
          bool rpsPuzzle();
};
#endif