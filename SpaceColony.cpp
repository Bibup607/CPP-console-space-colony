#include "SpaceColony.h"

void SpaceColony::gameRules() {
    std::cout << "\n====================================================" << std::endl;
    std::cout << "          ПРОТОКОЛ КОЛОНИЗАЦИИ: " << name << std::endl;
    std::cout << "====================================================" << std::endl;
    std::cout << "Вы — Искусственный Интеллект, управляющий станцией на" << std::endl;
    std::cout << "удаленной планете. Ваша конечная цель: выжить и" << std::endl;
    std::cout << "построить Космическую Ракету для возвращения домой." << std::endl;

    std::cout << "\n[ МЕХАНИКА ВЫЖИВАНИЯ ]" << std::endl;
    std::cout << "• ХОД: Каждый ход (кнопка 1) запускает симуляцию дня." << std::endl;
    std::cout << "• ПОТРЕБЛЕНИЕ: Люди автоматически едят и пьют каждый ход." << std::endl;
    std::cout << "  Расход зависит от численности населения." << std::endl;
    std::cout << "• КИСЛОРОД: Станция постоянно тратит запас кислорода." << std::endl;
    std::cout << "• СМЕРТЬ: Если любой ресурс упадет ниже 0 — игра окончена." << std::endl;

    std::cout << "\n[ ЭКОНОМИКА И МАГАЗИН ]" << std::endl;
    std::cout << "• ПРОИЗВОДСТВО: Энергия, еда и исследования начисляются" << std::endl;
    std::cout << "  автоматически от построенных зданий в начале хода." << std::endl;
    std::cout << "• ТИРЫ (УРОВНИ): Магазин открывает новые технологии (тиры)" << std::endl;
    std::cout << "  только после полной застройки текущего уровня." << std::endl;
    std::cout << "• СОБЫТИЯ: Каждый ход могут произойти метеориты или" << std::endl;
    std::cout << "  найдены припасы. Будьте готовы к потерям персонала." << std::endl;

    std::cout << "\n[ ВАШИ СТАРТОВЫЕ ДАННЫЕ ]" << std::endl;
    std::cout << "• Энергия: " << energy << " | Люди: " << people << std::endl;
    std::cout << "• Припасы: Вода " << water << " / Еда " << food << std::endl;
    std::cout << "• Инфраструктура: Уровень " << lvl << " (Начальный сектор)" << std::endl;
    std::cout << "• Цель: Собрать ракету ,чтобы улететь с этой планеты." << std::endl;
    std::cout << "====================================================\n" << std::endl;
}

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

void SpaceColony::riotSystem() {
    if (mood < 20) {
        std::cout << "\n!!! ВНИМАНИЕ !!!\n";
        std::cout << "Из‑за низкого настроения начался БУНТ!" << std::endl;
        int lose = 5 + rand() % 11;
        energy -= lose;
        food -= lose;
        water -= lose;
        oxygen -= lose;
        people -= (1 + rand()%4);
        std::cout << "Вы потеряли ресурсы и людей в результате беспорядков!" << std::endl;
    }
}
