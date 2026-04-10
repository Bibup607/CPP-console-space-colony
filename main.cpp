#include "SpaceColony.h"
#include "StartGame.h"
#include <ctime>

// Определение глобального объекта
SpaceColony spaceColony;

void startGame::mainMenu() {
    int action;
    std::cout << "======= Колония: " << spaceColony.getName()
    << " | Уровень: " << spaceColony.getLVL() << " | Ход: " << motion
    << " =======" << std::endl;
    std::cout << "-------- Ресурсы --------" << std::endl;
    std::cout << "Еда:         "  << spaceColony.getFood()   << std::endl;
    std::cout << "Вода:        "  << spaceColony.getWater()  << std::endl;
    std::cout << "Воздух:      "  << spaceColony.getOxygen() << std::endl;
    std::cout << "Энергия:     "  << spaceColony.getEnergy() << std::endl;
    std::cout << "Население:   "  << spaceColony.getPeople() << std::endl;
    std::cout << "Настроение:  "  << spaceColony.getMood() << std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout << "\n============== Ваши постройки ==============" << std::endl;
    if (spaceColony.getBuildings().empty()) {
        std::cout << "У вас пока ничего не построено." << std::endl;
    }
    else {
        for (const auto& b : spaceColony.getBuildings()) {
            std::cout << "• " << b.name << std::endl;
        }
    }

            std::cout << " \n=== Ваши действия === "   << std::endl;
            std::cout << " 1. Следующий ход"           << std::endl;
            std::cout << " 2. Подробная информация: "  << std::endl;
            std::cout << " 3. Древо улучшений"         << std::endl;
            std::cout << " 4. Устроить пир   "         << std::endl;
            std::cout << " 5. Магазин "                << std::endl;
            std::cout << " 6. Настройки "              << std::endl;
            std::cout << " 0. Выход из игры"           << std::endl;
            std::cout << "→  ";
            std::cin >> action;

            while (action < 0 || action > 6) {
                std::cout << "Введите число 0-6: " << std::endl;
                std::cin >> action;
            }
    if (action == 0) {
        std::cout << "Выход из системы... До встречи, капитан!" << std::endl;
        spaceColony.stopGame();;
    }

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
