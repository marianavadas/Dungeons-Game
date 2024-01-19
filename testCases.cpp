// CSCI 1300 Fall 2022
// Authors: Mariana Vadas-Arendt and Daria Ruchala
// Project 3

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace std;

int main()
{
    int num = 0;
    cout << "enter a integer" << endl;
    cin >> num;
    if (cin.fail())
    {
        cout << "enter a integer" << endl;
    }
    cin >> num;
}