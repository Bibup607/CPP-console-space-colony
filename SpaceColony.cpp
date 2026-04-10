#include "SpaceColony.h"

void SpaceColony::winGame() {
    std::cout << "\n====================================================" << std::endl;
    std::cout << "          ПОЗДРАВЛЯЕМ! МИССИЯ ВЫПОЛНЕНА!            " << std::endl;
    std::cout << "====================================================" << std::endl;
    std::cout << "Вы построили Космическую Ракету и успешно покинули" << std::endl;
    std::cout << "эту планету. Ваши колонисты спасены и летят домой!" << std::endl;
    std::cout << "====================================================" << std::endl;
    isWin = true;
}

void SpaceColony::gameOver() {
    if (people <= 0 || water < 0 || food < 0 || energy < 0 || oxygen < 0) {
        std::cout << "\nИГРА ОКОНЧЕНА. Ресурсы исчерпаны или все погибли." << std::endl;
        isAlive = false;
    }
}

void SpaceColony::saveGame() {
    std::ofstream file("save.txt");
    if (file.is_open()) {
        file << energy << " " << oxygen << " " << people << " " << water << " "
             << food << " " << research << " " << lvl << " " << mood << " " << name;
        file.close();
        std::cout << "--- Игра сохранена! ---" << std::endl;
    }
}

void SpaceColony::loadGame() {
    std::ifstream file("save.txt");
    if (file.is_open()) {
        file >> energy >> oxygen >> people >> water >> food >> research >> lvl >> mood >> name;
        file.close();
        std::cout << "--- Сохранение загружено! ---" << std::endl;
    } else {
        std::cout << "Файл сохранения не найден!" << std::endl;
    }
}

void SpaceColony::deleteSave() {
    std::ofstream file("save.txt", std::ios::trunc);
    file.close();
    std::cout << "Файл сохранения очищен!" << std::endl;
}