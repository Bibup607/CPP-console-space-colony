#include "SpaceColony.h"
#include "StartGame.h"
#include <ctime>

TechStudy techStudy;

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


    if (spaceColony.getTrade()) {
        std::cout << " 7. Межпланетная торговля (10 иссл. -> 20 эн.)" << std::endl;
    }

    std::cout << " 0. Выход из игры"           << std::endl;
    std::cout << "→  ";
    std::cin >> action;

    int maxAction = spaceColony.getTrade() ? 7 : 6;
    while (action < 0 || action > maxAction) {
        std::cout << "Введите корректное число: " << std::endl;
        std::cin >> action;
    }

    if (action == 0) {
        std::cout << "Выход из системы... До встречи, капитан!" << std::endl;
        spaceColony.stopGame();
    }
    else if (action == 1) {
        magaz.applyTurnBonuses();

        if (spaceColony.getPropaganda()) {
            int bonus = spaceColony.getLVL() * 5;
            spaceColony.addE(bonus);
            spaceColony.addF(bonus);
            spaceColony.addW(bonus);
            std::cout << "[БУСТ] Пропаганда: воодушевленные люди добыли больше ресурсов!" << std::endl;
        }
        
        int foodConsumption = spaceColony.getPeople() / 5;
        if (spaceColony.getRationing()) {
            foodConsumption /= 2;
            spaceColony.addM(-2);
        }
        spaceColony.addF(-foodConsumption);
        spaceColony.addW(-(spaceColony.getPeople() / 5));

        if (spaceColony.getAudioDiaries()) {
            spaceColony.addM(magaz.countLab * 2);
        }

        gMotion.randMotion();
        trUp.researchPoints();
        spaceColony.gameOver();
    }
    else if (action == 2) info.infoB();
    else if (action == 3) trUp.tree();
    else if (action == 4) {
        if (motion - lastFeastMotion < 10) {
            std::cout << "[ОТКАЗ] Устраивать пир можно только раз в 10 ходов!" << std::endl;
            std::cout << "Осталось подождать: " << 10 - (motion - lastFeastMotion) << " ходов." << std::endl;
        }
        else if (spaceColony.getFood() >= 100 && spaceColony.getWater() >= 50) {
            spaceColony.addF(-100);
            spaceColony.addW(-50);
            moodSys.upMood(30);

            lastFeastMotion = motion; // запоминаем тек ход

            std::cout << "Пир прошел успешно! Настроение +30." << std::endl;
        }
        else {
            std::cout << "Для пира нужно 100 еды и 50 воды!" << std::endl;
        }
    }
    else if (action == 5) magaz.magazine();
    else if (action == 6) param.parametrs();
    else if (action == 7 && spaceColony.getTrade()) {
        if (spaceColony.getResearch() >= 10) {
            spaceColony.addR(-10);
            spaceColony.addE(20);
            std::cout << "Сделка совершена: 10 очков исследований обменяны на 20 энергии." << std::endl;
        } else {
            std::cout << "Недостаточно очков исследований для торговли!" << std::endl;
        }
    }
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
