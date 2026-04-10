#ifndef ___SPACECOLONY_H
#define ___SPACECOLONY_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct myBuilding {
    std::string name;
    int level;
};

class SpaceColony {
private:
    int energy = 300;
    int oxygen = 100;
    int people = 50;
    int water = 100;
    int food = 100;
    int research = 0;
    int lvl = 1;
    int mood = 70;
    int const MAX_MOOD = 100;
    std::string name = "Без имени";
    bool isAlive = true;
    bool isWin = false;
    std::vector<myBuilding> buildings;

public:
    int getEnergy() { return energy; }
    int getResearch() { return research; }
    bool getIsAlive() { return isAlive && !isWin; }
    bool getIsWin() { return isWin; }
    std::string getName() { return name; }
    int getFood() { return food; }
    int getWater() { return water; }
    int getOxygen() { return oxygen; }
    int getPeople() { return people; }
    int getMood() { return mood; }
    int getLVL() { return lvl; }

    void addE(int v) { energy += v; }
    void addF(int v) { food += v; }
    void addW(int v) { water += v; }
    void addO(int v) { oxygen += v; }
    void addP(int v) { people += v; }
    void addR(int v) { research += v; }
    void addM(int v) { mood += v; if (mood > MAX_MOOD) mood = MAX_MOOD; }
    void addN(std::string v) { name = v; }

    const std::vector<myBuilding>& getBuildings() { return buildings; }

    void addBuilding(std::string Nameb) {
        buildings.push_back({ Nameb, 1 });
    }

    void winGame();
    void gameOver();
    void saveGame();
    void loadGame();
    void deleteSave();
    void stopGame() { isAlive = false; }
};

extern SpaceColony spaceColony; // Глобальный объект для всех файлов


#endif //___SPACECOLONY_H