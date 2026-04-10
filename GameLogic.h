#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "SpaceColony.h"

class gameMotion {
public:
    void randMotion();
};

class treeUp {
public:
    bool magazv2 = false;
    bool magazv3 = false;
    bool magazv4 = false;
    void researchPoints();
    void tree();
};

class Magazin {
public:
    bool isBuy1 = true, isBuy2 = true, isBuy3 = true, isBuy4 = true, isBuy5 = true;
    bool isBuy6 = true, isBuy7 = true, isBuy8 = true, isBuy9 = true, isBuy10 = true;
    bool isBuy11 = true, isBuy12 = true, isBuy13 = true, isBuy14 = true, isBuy15 = true;
    bool isBuy16 = true, isBuy17 = true, isBuy18 = true;
    
    bool magazv2 = false, magazv3 = false, magazv4 = false;
    int countHousing = 0, countHydro = 0, countSolar = 0, countOxy = 0;

    void magz();
    void magazine();
    void applyTurnBonuses();
};

class Parametrs {
public:
    void parametrs();
};

class infoBuild {
public:
    void infoB();
};

class mooDs {
public:
    void upMood(int currentMood);
};

#endif