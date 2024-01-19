// CSCI 1300 Fall 2022
// Authors: Mariana Vadas-Arendt and Daria Ruchala
// Project 3

#ifndef MERCHANT_H
#define MERCHANT_H
#include <string>
#include "Map.h"
// #include "User.h"
// #include "Action.h"

using namespace std;

class Merchant
{
    private:
        int pot; //stores amount of pots user has bought
        int pan; //stores amount of pans user has bought
        int cauldron; //stores amount of cauldrons user has bought
        int club; //stores amount of clubs user has bought
        int spear; //stores amount of spears user has bought
        int rapier; //stores amount of rapiers user has bought
        int axe; //stores amount of axes user has bought
        int longsword; //stores amount of longswords user has bought
        int ring; //stores amount of rings user has bought
        int necklace; //stores amount of necklaces user has bought
        int bracelet; //stores amount of bracelets user has bought
        int circlet; //stores amount of circlets user has bought
        int goblet; //stores amount of goblets user has bought
        int ingredients; //stores amount of ingredients user has bought
        int armor; //stores amount of armor user has bought

    public:
        Merchant();

        void setIngredients(int ingredients_);
        int getIngredients();

        void setArmor(int armor_);
        int getArmor();

        void setMerchantPot(int pot_);
        void setMerchantPan(int pan_);
        void setMerchantCauldron(int cauldron_);
        int getMerchantPot();
        int getMerchantPan();
        int getMerchantCauldron();

        void setMerchantClub(int club_);
        void setMerchantSpear(int spear_);
        void setMerchantRapier(int rapier_);
        void setMerchantAxe(int axe_);
        void setMerchantLongsword(int longsword_);
        int getMerchantClub();
        int getMerchantSpear();
        int getMerchantRapier();
        int getMerchantAxe();
        int getMerchantLongsword();

        void setMerchantRing(int ring_);
        void setMerchantNecklace(int necklace_);
        void setMerchantBracelet(int bracelet_);
        void setMerchantCirclet(int circlet_);
        void setMerchantGoblet(int goblet_);
        int getMerchantRing();
        int getMerchantNecklace();
        int getMerchantBracelet();
        int getMerchantCirclet();
        int getMerchantGoblet();

        double merchantPriceCookware(int room, int type_);
        double merchantPriceWeapons(int room, int type_);
        double merchantPriceTreasures(int room, int type_);
        double merchantPriceIngredients(int room, int kg);
        double merchantPriceArmor(int room, int num);
};
#endif