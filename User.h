// CSCI 1300 Fall 2022
// Authors: Mariana Vadas-Arendt and Daria Ruchala
// Project 3

#ifndef USER_H
#define USER_H
#include <string>
#include <cmath>
#include "Action.h"
#include "Npc.h"
#include "Map.h"
#include "Merchant.h"
#include "Player.h"

using namespace std;

class User
{
    private:
        int fullness[5]; //stores health for each player
        Player playerobj[5]; //stores player names
        int key; //stores number of keys player has
        int angerLevel; //stores anger of the sorcerer
        double gold; //stores the amount of gold the user has
        int ingredients; //the amount of ingredients the user has 
        int armor; //the amount of armor the user has
        int cookware[3]; //stores the cookware the user currently has
        int weapons[5]; //stores the weapons the user currently has 
        int treasures[5]; //stores the treasures the user currently has 

    public:
        User();
        User(int fullness_[], string players_[], int key_, int angerLevel_, double gold_, int ingredients_, int armor_, int cookware_[], int weapons_[], int treasures_[]);

        string getPlayers(int type);
        void setPlayers(string player, string companion1, string companion2, string companion3, string companion4);

        int getPlayersFullness(int type);
        void setPlayersFullness(int player, int companion1, int companion2, int companion3, int companion4);

        int getUserKey();
        void setUserKey(int key_);

        int getAngerLevel();
        void setAngerLevel(int angerLevel_);

        double getUserGold();
        void setUserGold(double gold_);

        int getUserIngredients();
        void setUserIngredients(int ingredients_);

        int getUserArmor();
        void setUserArmor(int armor_);

        int getUserCookware(int type);
        void setUserCookware(int pot, int pan, int cauldron);

        int getUserWeapons(int type);
        void setUserWeapons(int club, int spear, int rapier, int axe, int longsword);

        int getUserTreasures(int type);
        void setUserTreasures(int ring, int necklace, int bracelet, int circlet, int goblet);

        bool potBreak();
        bool panBreak();
        bool cauldronBreak();

        //& is used for pass by reference to change values throughout the code without losing values
        int displayStatus(User &temp_user, Map &map, Action &temp_action); //line 211
        int cooking(User &temp_user, Action &temp_action); //line 290
        int misfortunes(User &temp_user, Action &temp_action); //line 740
        int investigateChances(User &temp_user, Map &map, Action &temp_action); //line 1041
        int fullnessDrop(User &temp_user, Action &temp_action); //line 1284
        int roomMenu(User &temp_user, Action &temp_action, Map &map, NPC &npc, Merchant &temp_merchant); //line 2486
        int fightingMonster(Map &map, User &temp_user, Action &temp_action); //line 1515
        int normalMenu(Map &map, User &temp_user, Action &temp_action, NPC &npc, Merchant &temp_merchant); //line 2180
        int npcMenu(Action &temp_action, Map &map, User &temp_user, NPC &npc, Merchant &temp_merchant); //line 3054
        int displayMenu(User &temp_user, Merchant &temp_merchant, Action &temp_action); //line 3334
};
#endif