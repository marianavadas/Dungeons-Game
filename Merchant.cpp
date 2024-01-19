// CSCI 1300 Fall 2022
// Authors: Mariana Vadas-Arendt and Daria Ruchala
// Project 3

#include "Merchant.h"
#include <iostream>
#include <unistd.h>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

Merchant::Merchant()
{
    pot = 0;
    pan = 0;
    cauldron = 0;
    club = 0;
    spear = 0;
    rapier = 0;
    axe = 0;
    longsword = 0;
    ring = 0;
    necklace = 0;
    bracelet = 0;
    circlet = 0;
    goblet = 0;
    ingredients = 0;
    armor = 0;
}
void Merchant::setIngredients(int ingredients_)
{
    ingredients = ingredients_;
}
int Merchant::getIngredients()
{
    return ingredients;
}
void Merchant::setArmor(int armor_)
{
    armor =  armor_;
}
int Merchant::getArmor()
{
    return armor;
}
void Merchant::setMerchantPot(int pot_)
{
    pot = pot_;
}
void Merchant::setMerchantPan(int pan_)
{
    pan = pan_;
}
void Merchant::setMerchantCauldron(int cauldron_)
{
    cauldron = cauldron_;
}
int Merchant::getMerchantPot()
{
    return pot;
}
int Merchant::getMerchantPan()
{
    return pan;
}
int Merchant::getMerchantCauldron()
{
    return cauldron;
}
void Merchant::setMerchantClub(int club_)
{
    club = club_;
}
void Merchant::setMerchantSpear(int spear_)
{
    spear = spear_;
}
void Merchant::setMerchantRapier(int rapier_)
{
    rapier = rapier_;
}
void Merchant::setMerchantAxe(int axe_)
{
    axe = axe_;
}
void Merchant::setMerchantLongsword(int longsword_)
{
    longsword = longsword_;
}
int Merchant::getMerchantClub()
{
    return club;
}
int Merchant::getMerchantSpear()
{
    return spear;
}
int Merchant::getMerchantRapier()
{
    return rapier;
}
int Merchant::getMerchantAxe()
{
    return axe;
}
int Merchant::getMerchantLongsword()
{
    return longsword;
}
void Merchant::setMerchantRing(int ring_)
{
    ring = ring_;
}
void Merchant::setMerchantNecklace(int necklace_)
{
    necklace = necklace_;
}
void Merchant::setMerchantBracelet(int bracelet_)
{
    bracelet = bracelet_;
}
void Merchant::setMerchantCirclet(int circlet_)
{
    circlet = circlet_;
}
void Merchant::setMerchantGoblet(int goblet_)
{
    goblet = goblet_;
}
int Merchant::getMerchantRing()
{
    return ring;
}
int Merchant::getMerchantNecklace()
{
    return necklace;
}
int Merchant::getMerchantBracelet()
{
    return bracelet;
}
int Merchant::getMerchantCirclet()
{
    return circlet;
}
int Merchant::getMerchantGoblet()
{
    return goblet;
}

double Merchant::merchantPriceCookware(int room, int type_)
{
    if (room == 0)
    {
        if (type_ == 1) //pot
        {
            return 2;
        }
        else if (type_ == 2) //pan
        {
            return 10;
        }
        else if (type_ == 3) //cauldron
        {
            return 20;
        }
    }
    else if (room == 1)
    {
        if (type_ == 1)
        {
            return 3;
        }
        else if (type_ == 2)
        {
            return 13;
        }
        else if (type_ == 3)
        {
            return 25;
        }
    }
    else if (room == 2)
    {
        if (type_ == 1)
        {
            return 3;
        }
        else if (type_ == 2)
        {
            return 15;
        }
        else if (type_ == 3)
        {
            return 30;
        }
    }
    else if (room == 3)
    {
        if (type_ == 1)
        {
            return 4;
        }
        else if (type_ == 2)
        {
            return 18;
        }
        else if (type_ == 3)
        {
            return 35;
        }
    }
    else if (room == 4)
    {
        if (type_ == 1)
        {
            return 4;
        }
        else if (type_ == 2)
        {
            return 20;
        }
        else if (type_ == 3)
        {
            return 40;
        }
    }
    else if (room == 5)
    {
        if (type_ == 1)
        {
            return 5;
        }
        else if (type_ == 2)
        {
            return 25;
        }
        else if (type_ == 3)
        {
            return 50;
        }
    }
    return 0;
}
double Merchant::merchantPriceWeapons(int room, int type_)
{
    if (room == 0)
    {
        if (type_ == 1) //club
        {
            return 2;
        }
        else if (type_ == 2) //spear
        {
            return 2;
        }
        else if (type_ == 3) //rapier
        {
            return 5;
        }
        else if (type_ == 4) //axe
        {
            return 15;
        }
        else if (type_ == 5) //longsword
        {
            return 50;
        }
    }
    else if (room == 1)
    {
        if (type_ == 1) //club
        {
            return 2;
        }
        else if (type_ == 2) //spear
        {
            return 3;
        }
        else if (type_ == 3) //rapier
        {
            return 7;
        }
        else if (type_ == 4) //axe
        {
            return 19;
        }
        else if (type_ == 5) //longsword
        {
            return 63;
        }
    }
    else if (room == 2)
    {
        if (type_ == 1) //club
        {
            return 3;
        }
        else if (type_ == 2) //spear
        {
            return 3;
        }
        else if (type_ == 3) //rapier
        {
            return 8;
        }
        else if (type_ == 4) //axe
        {
            return 23;
        }
        else if (type_ == 5) //longsword
        {
            return 75;
        }
    }
    else if (room == 3)
    {
        if (type_ == 1) //club
        {
            return 3;
        }
        else if (type_ == 2) //spear
        {
            return 4;
        }
        else if (type_ == 3) //rapier
        {
            return 9;
        }
        else if (type_ == 4) //axe
        {
            return 26;
        }
        else if (type_ == 5) //longsword
        {
            return 88;
        }
    }
    else if (room == 4)
    {
        if (type_ == 1) //club
        {
            return 4;
        }
        else if (type_ == 2) //spear
        {
            return 4;
        }
        else if (type_ == 3) //rapier
        {
            return 10;
        }
        else if (type_ == 4) //axe
        {
            return 30;
        }
        else if (type_ == 5) //longsword
        {
            return 100;
        }
    }
    else if (room == 5)
    {
        if (type_ == 1) //club
        {
            return 5;
        }
        else if (type_ == 2) //spear
        {
            return 5;
        }
        else if (type_ == 3) //rapier
        {
            return 13;
        }
        else if (type_ == 4) //axe
        {
            return 38;
        }
        else if (type_ == 5) //longsword
        {
            return 125;
        }
    }
    return 0;
}
double Merchant::merchantPriceTreasures(int room, int type_)
{
    if (room == 0)
    {
        cout << "You must clear a room before selling jewelry" << endl;
    }
    else if (room == 1)
    {
        if (type_ == 1) //ring
        {
            return 10;
        }
    }
    else if (room == 2)
    {
        if (type_ == 1) //ring
        {
            return 10;
        }
        else if (type_ == 2) //necklace
        {
            return 20;
        }
    }
    else if (room == 3)
    {
        if (type_ == 1) //ring
        {
            return 10;
        }
        else if (type_ == 2) //necklace
        {
            return 20;
        }
        else if (type_ == 3) //bracelet
        {
            return 30;
        }
    }
    else if (room == 4)
    {
        if (type_ == 1) //ring
        {
            return 10;
        }
        else if (type_ == 2) //necklace
        {
            return 20;
        }
        else if (type_ == 3) //bracelet
        {
            return 30;
        }
        else if (type_ == 4) //circlet
        {
            return 40;
        }
    }
    else if (room == 5)
    {
        if (type_ == 1) //ring
        {
            return 10;
        }
        else if (type_ == 2) //necklace
        {
            return 20;
        }
        else if (type_ == 3) //bracelet
        {
            return 30;
        }
        else if (type_ == 4) //circlet
        {
            return 40;
        }
        else if (type_ == 5) //goblet
        {
            return 50;
        }
    }
    return 0;
}
double Merchant::merchantPriceIngredients(int room, int kg)
{
    if (room == 0)
    {
        return kg;
    }
    else if (room == 1)
    {
        return 1 * kg;
    }
    else if (room == 2)
    {
        return 2 * kg;
    }
    else if (room == 3)
    {
        return 2 * kg;
    }
    else if (room == 4)
    {
        return 2 * kg;
    }
    else if (room == 5)
    {
        return 2 * kg;
    }
    return 0;
}
double Merchant::merchantPriceArmor(int room, int num)
{
    if (room == 0)
    {
        return 5 * num;
    }
    else if (room == 1)
    {
        return 7 * num;
    }
    else if (room == 2)
    {
        return 8 * num;
    }
    else if (room == 3)
    {
        return 8 * num;
    }
    else if (room == 4)
    {
        return 10 * num;
    }
    else if (room == 5)
    {
        return 13 * num;
    }
    return 0;
}