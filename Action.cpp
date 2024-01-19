// CSCI 1300 Fall 2022
// Authors: Mariana Vadas-Arendt and Daria Ruchala
// Project 3
 
#include "Action.h"
#include "unistd.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace std;
 
Action:: Action()
{
    monstersDefeated = 0;
    turnsElapsed = 0;
    endGame =  false;
    clearedRooms = 0;
}
 
Action::Action (int monstersDefeated_, int turnsElapsed_, int clearedRooms_, bool endGame_)
{
    monstersDefeated = monstersDefeated_;
    turnsElapsed = turnsElapsed_;
    clearedRooms = clearedRooms_;
    endGame = endGame_;
}
int Action::getMonstersDefeated()
{
    return monstersDefeated;
}
void Action::setMonstersDefeated(int monstersDefeated_)
{
    monstersDefeated = monstersDefeated_;
}
int Action::getTurnsElapsed()
{
    return turnsElapsed;
}
void Action::setTurnsElapsed(int turnsElapsed_)
{
    turnsElapsed = turnsElapsed_;
}
void Action::setClearedRooms(int numRooms)
{
    clearedRooms = numRooms;
}
int Action::getClearedRooms()
{
    return clearedRooms;
}
void Action::setEndGame(bool endGame_)
{
    endGame = endGame_;
}
bool Action::getEndGame()
{
    return endGame;
}