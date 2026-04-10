#ifndef STARTGAME_H
#define STARTGAME_H

#include "GameLogic.h"

class startGame {
private:
    int motion = 0;
    gameMotion gMotion;
    Magazin magaz;
    treeUp trUp;
    mooDs moodSys;
    Parametrs param;
    infoBuild info;

public:
    void mainMenu();
};

#endif