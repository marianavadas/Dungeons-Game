// CSCI 1300 Fall 2022
// Authors: Mariana Vadas-Arendt and Daria Ruchala
// Project 3

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Player
{
    private:
        string name; //stores the name of the player
    public:
        Player();

        void setName(string name_);
        string getName();
};
#endif