#include "SpaceColony.h"
#include "StartGame.h"
#include <ctime>

// Определение глобального объекта
SpaceColony spaceColony;

void startGame::mainMenu() {
    std::cout << "\n--- " << spaceColony.getName() << " | Ход: " << motion << " ---\n";
    std::cout << "Энергия: " << spaceColony.getEnergy() << " | Еда: " << spaceColony.getFood() << " | Люди: " << spaceColony.getPeople() << "\n";
    std::cout << "1. След. ход | 2. Инфо | 3. Древо | 4. Пир | 5. Магазин | 6. Настройки | 0. Выход\n-> ";
    int action; std::cin >> action;

    if (action == 1) {
        motion++;
        magaz.applyTurnBonuses();
        spaceColony.addF(-(spaceColony.getPeople() / 5));
        spaceColony.addW(-(spaceColony.getPeople() / 5));
        gMotion.randMotion();
        trUp.researchPoints();
        spaceColony.gameOver();
    }
    else if (action == 2) info.infoB();
    else if (action == 3) trUp.tree();
    else if (action == 4) moodSys.upMood(spaceColony.getMood());
    else if (action == 5) magaz.magazine();
    else if (action == 6) param.parametrs();
    else if (action == 0) spaceColony.stopGame();
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(static_cast<unsigned>(time(NULL)));
    
    startGame game;
    while (spaceColony.getIsAlive()) {
        game.mainMenu();
    }
    return 0;
}