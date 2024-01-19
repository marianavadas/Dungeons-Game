// CSCI 1300 Fall 2022
// Authors: Mariana Vadas-Arendt and Daria Ruchala
// Project 3
#include "Player.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Player::Player()
{
    name = "";
}
void Player::setName(string name_)
{
    name = name_;
}
string Player::getName()
{
    return name;
}