#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "SpaceColony.h"
#include <iostream>
#include <vector>
#include <string>


inline SpaceColony spaceColony;

class TechStudy {
private:
    int extraTime = 0;
public:
    void addTech(int time) { extraTime += time; }
    int getExtraTime() { return extraTime; }
};
extern TechStudy techStudy;

class gameMotion {
public:
    void randMotion();
    int rand_people1 = 0, rand_people2 = 0, rand_people3 = 0, rand_breakdown = 0, rand_event, arr_event;
};

class treeUp {
public:
    bool magazv2 = false, magazv3 = false, magazv4 = false;
    bool isTech1 = true, isTech2 = true, isTech3 = true, isTech4 = true, isTech5 = true;
    bool isTech6 = true, isTech7 = true, isTech8 = true, isTech9 = true, isTech10 = true;

    bool hasProtocol = false, hasRationing = false, hasAudioDiaries = false;
    bool hasFeast = false, hasSports = false, hasNightShift = false;
    bool hasVR = false, hasAutoMed = false, hasTrading = false, hasPropaganda = false;

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
    int countSolar1 = 0, countLab1 = 0, countLab = 0;

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
