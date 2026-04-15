#include "GameLogic.h"
#include <ctime>

void gameMotion::randMotion() {
    std::vector<int> arr_event = {1, 5, 1, 5, 1, 2, 1, 5, 1, 1, 2, 5, 3, 1, 1, 5, 4, 4, 1,};
    rand_event = arr_event[rand() % arr_event.size()];
                if (rand_event == 1) {
                    spaceColony.addE(10);
                    spaceColony.addF(10);
                    spaceColony.addW(10);
                    spaceColony.addO(10);
                    spaceColony.addP(5);
                    spaceColony.addR(5);
                    std::cout << "За этот ход ничего не произошло\n" << std::endl;
                }
                else if (rand_event == 2) {
                    rand_people1 = 1 + rand() % 20;
                    spaceColony.addP(-rand_people1);
                    std::cout << " Метеориты!! У вас погибло: "<< rand_people1 << " человек :(" << std::endl;
                    std::cout << "Повреждена Солнечная батарея! -20 энергии\n" << std::endl;
                    spaceColony.addF(10);
                    spaceColony.addW(10);
                    spaceColony.addO(10);
                    spaceColony.addE(-20);
                    spaceColony.addR(5);
                    spaceColony.addM(-3);
                }
                else if (rand_event == 3) {
                    rand_people2 = 1 + rand() % 9;
                    spaceColony.addP(-rand_people2);
                    std::cout << "Болезнь!!! У вас погибло: "<< rand_people2 << " человек :(\n" << std::endl;
                    spaceColony.addE(10);
                    spaceColony.addF(10);
                    spaceColony.addW(10);
                    spaceColony.addO(10);
                    spaceColony.addR(5);
                    spaceColony.addM(-3);
                }
                else if (rand_event == 4) {

                    rand_people3 = rand() % 8 + 1;
                    rand_breakdown = rand_people3;

                    if (rand_breakdown == 1) {
                        std::cout << "Повреждена научная лаборатория! Вы потеряли 5 очков исследования" << std::endl;
                        std::cout << "Время изучения технологии + 3 хода\n" << std::endl;
                        techStudy.addTech(3);
                        spaceColony.addF(10);
                        spaceColony.addW(10);
                        spaceColony.addO(10);
                        spaceColony.addP(5);
                        spaceColony.addE(-20);
                        spaceColony.addR(-5);
                        spaceColony.addM(-3);
                    }
                    else if (rand_breakdown == 2) {
                        std::cout << "Поврежден жилой модуль!" << std::endl;
                        rand_people2 = 1 + rand() % 8;
                        spaceColony.addP(-rand_people2);
                        spaceColony.addE(10);
                        spaceColony.addF(10);
                        spaceColony.addW(10);
                        spaceColony.addR(5);
                        spaceColony.addM(-3);
                        std::cout << "У вас погибло: "<< rand_people2 << " человек :(" << std::endl;
                        std::cout << "Произошла утечка кислорода! Вы потеряли 25 кислорода\n" << std::endl;
                        spaceColony.addO(-25);
                    }
                    else if (rand_breakdown == 3) {
                        std::cout << "Повреждена Солнечная батарея! -40 энергии\n" << std::endl;
                        spaceColony.addE(-40);
                        spaceColony.addF(10);
                        spaceColony.addW(10);
                        spaceColony.addO(10);
                        spaceColony.addP(5);
                        spaceColony.addM(-3);
                    }
                    else if (rand_breakdown == 4) {
                        std::cout << "Повреждена гидропонная лаборатория! - 30 еды/воды\n" << std::endl;
                        spaceColony.addF(-30);
                        spaceColony.addW(-30);
                        spaceColony.addE(10);
                        spaceColony.addO(10);
                        spaceColony.addP(5);
                        spaceColony.addR(5);
                        spaceColony.addM(-3);
                    }
                } else if (rand_event == 5) {
                    rand_people3 = rand() % 4 + 1;
                    spaceColony.addP(rand_people3);
                    std::cout << "Были найдены колонисты в криокапсулах! + "
                              << rand_people3 << " человек!\n" << std::endl;
                }
            }

void Magazin::magz() {
    if (!isBuy1 && !isBuy2 && !isBuy3 && !isBuy4) magazv2 = true;
    if (magazv2 && !isBuy5 && !isBuy6 && !isBuy7 && !isBuy8 && !isBuy9) magazv3 = true;
    if (magazv3 && !isBuy10 && !isBuy11 && !isBuy12 && !isBuy13 && !isBuy14) magazv4 = true;
}

void Magazin::applyTurnBonuses() {
    spaceColony.addE(countSolar * 10);
    spaceColony.addF(countHydro * 5);
    spaceColony.addO(countOxy * 5);
}

void Magazin::magazine() {
    int action;
    magz();
    std::cout << "\n=== МАГАЗИН ===\n";
    std::cout << "Чтобы открывать новые уровни, нужно "
                     "купить все постройки с прошлого " << std::endl;

        std::cout << "Уровень I (Открыто)" << std::endl;
        std::cout << "1. Жилой модуль                  — 40 э | +10 населению (единоразово)\n";
        std::cout << "2. Гидропонная лаборатория       — 60 э | Еда+22, Вода+6\n";
        std::cout << "3. Солнечная батарея             — 50 э | Энергия+20\n";
        std::cout << "4. Исследовательская лаборатория — 55 э | Иссл.+6\n\n";


        if (magazv2 == false) std::cout << "Уровень II (Закрыто)" << std::endl;
        else std::cout << "Уровень II (Открыто)" << std::endl;
        std::cout << "5. Кислородный переработчик      — 80 э | Кисл.+12\n";
        std::cout << "6. Купол отдыха                  — 120э | +1 население\n";
        std::cout << "7. Переработчик отходов          — 65 э | +7 к еде\n";
        std::cout << "8. Жилой модуль II               — 90 э | +4 населению\n";
        std::cout << "9. Солнечная батарея II          — 85 э | +10 к энергии\n\n";

        if (magazv3 == false) std::cout << "Уровень III (Закрыто)" << std::endl;
        else std::cout << "Уровень III (Открыто)" << std::endl;
        std::cout << "10. Горнодобывающий пост         — 110 э | +10 к энергии\n";
        std::cout << "11. Медицинский отсек            — 155 э | +1 к населению\n";
        std::cout << "12. Чертеж ракеты                — 420 э | ........ \n";
        std::cout << "13. Биокупол                     — 130 э | Еда+10/Вода+5\n";
        std::cout << "14. Центральная лаборатория      — 125 э | Иссл.+30\n\n";

        if (magazv4 == false) std::cout << "Уровень IV (Закрыто)" << std::endl;
        else std::cout << "Уровень III (Открыто)" << std::endl;
        std::cout << "15. Ядерный реактор              — 250 э | Энергия +70\n";
        std::cout << "16. Генетическая лаборатория     — 220 э | +5 к населению.\n";
        std::cout << "17. Космический док              — 300 э | +3 колониста/15 ходов\n";
        std::cout << "18. Космическая ракета           — 888 э | ........\n\n";

        std::cout << "0. Назад\n";
        std::cout << "Напишите 0-18" << std::endl;
        std::cin >> action;
    std::cin >> action;

    while (action < 0 || action > 18) {
        std::cout << "Введите число 0-18: " << std::endl;
        std::cin >> action;
    }

    if (action == 1) {
        if (!isBuy1) {
            std::cout << "[-] Ошибка: Жилой модуль уже построен!" << std::endl;
        } else if (spaceColony.getEnergy() >= 40) {
            spaceColony.addE(-40); spaceColony.addP(10); countHousing++;
            spaceColony.addBuilding("Жилой модуль"); isBuy1 = false;
            std::cout << "[+] Успешно: Построен Жилой модуль" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 2) {
        if (!isBuy2) {
            std::cout << "[-] Ошибка: Гидропонная лаборатория уже построена!" << std::endl;
        } else if (spaceColony.getEnergy() >= 60) {
            spaceColony.addE(-60); spaceColony.addF(22); spaceColony.addW(6); countHydro++;
            spaceColony.addBuilding("Гидропонная лаборатория"); isBuy2 = false;
            std::cout << "[+] Успешно: Построена Гидропонная лаборатория" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 3) {
        if (!isBuy3) {
            std::cout << "[-] Ошибка: Солнечная батарея уже установлена!" << std::endl;
        } else if (spaceColony.getEnergy() >= 50) {
            spaceColony.addE(-50); spaceColony.addE(20); countSolar1++;
            spaceColony.addBuilding("Солнечная батарея"); isBuy3 = false;
            std::cout << "[+] Успешно: Установлена Солнечная батарея" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 4) {
        if (!isBuy4) {
            std::cout << "[-] Ошибка: Лаборатория уже построена!" << std::endl;
        } else if (spaceColony.getEnergy() >= 55) {
            spaceColony.addE(-55);
            countLab1++; // Добавляем к счетчику лабораторий для бонуса за ход
            spaceColony.addBuilding("Исследовательская лаборатория");
            isBuy4 = false;
            std::cout << "[+] Успешно: Построена лаборатория (Иссл. +6 за ход)" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }

    else if (action == 5 && magazv2) {
        if (!isBuy5) {
            std::cout << "[-] Ошибка: Склад ресурсов уже построен!" << std::endl;
        } else if (spaceColony.getEnergy() >= 100) {
            spaceColony.addE(-100); spaceColony.addBuilding("Склад ресурсов"); isBuy5 = false;
            std::cout << "[+] Успешно: Построен Склад ресурсов" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 6 && magazv2) {
        if (!isBuy6) {
            std::cout << "[-] Ошибка: Очиститель воды уже работает!" << std::endl;
        } else if (spaceColony.getEnergy() >= 120) {
            spaceColony.addE(-120); spaceColony.addW(30); isBuy6 = false;
            std::cout << "[+] Успешно: Установлен Очиститель воды" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 7 && magazv2) {
        if (!isBuy7) {
            std::cout << "[-] Ошибка: Медпункт уже открыт!" << std::endl;
        } else if (spaceColony.getEnergy() >= 150) {
            spaceColony.addE(-150); spaceColony.addM(20); isBuy7 = false;
            std::cout << "[+] Успешно: Открыт Медпункт" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 8 && magazv2) {
        if (!isBuy8) {
            std::cout << "[-] Ошибка: Казармы уже построены!" << std::endl;
        } else if (spaceColony.getEnergy() >= 130) {
            spaceColony.addE(-130); spaceColony.addP(15); isBuy8 = false;
            std::cout << "[+] Успешно: Построены Казармы" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 9 && magazv2) {
        if (!isBuy9) {
            std::cout << "[-] Ошибка: Радар уже установлен!" << std::endl;
        } else if (spaceColony.getEnergy() >= 110) {
            spaceColony.addE(-110); isBuy9 = false;
            std::cout << "[+] Успешно: Установлен Радар" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }

    else if (action == 10 && magazv3) {
        if (!isBuy10) {
            std::cout << "[-] Ошибка: Научный центр уже существует!" << std::endl;
        } else if (spaceColony.getEnergy() >= 200) {
            spaceColony.addE(-200); spaceColony.addR(50); isBuy10 = false;
            std::cout << "[+] Успешно: Открыт Научный центр" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 11 && magazv3) {
        if (!isBuy11) {
            std::cout << "[-] Ошибка: Фабрика уже работает!" << std::endl;
        } else if (spaceColony.getEnergy() >= 250) {
            spaceColony.addE(-250); isBuy11 = false;
            std::cout << "[+] Успешно: Запущена Фабрика" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 12 && magazv3) {
        if (!isBuy12) {
            std::cout << "[-] Ошибка: Чертежи ракеты уже получены!" << std::endl;
        } else if (spaceColony.getEnergy() >= 300) {
            spaceColony.addE(-300); isBuy12 = false;
            std::cout << "[+] Успешно: Получены Чертежи ракеты" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 13 && magazv3) {
        if (!isBuy13) {
            std::cout << "[-] Ошибка: Ядерный реактор уже запущен!" << std::endl;
        } else if (spaceColony.getEnergy() >= 400) {
            spaceColony.addE(-400); spaceColony.addE(100); isBuy13 = false;
            std::cout << "[+] Успешно: Запущен Ядерный реактор" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 14 && magazv3) {
        if (!isBuy14) {
            std::cout << "[-] Ошибка: Центр управления уже готов!" << std::endl;
        } else if (spaceColony.getEnergy() >= 350) {
            spaceColony.addE(-350); isBuy14 = false;
            std::cout << "[+] Успешно: Построен Центр управления" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }

    else if (action == 15 && magazv4) {
        if (!isBuy15) {
            std::cout << "[-] Ошибка: Ионный двигатель уже готов!" << std::endl;
        } else if (spaceColony.getEnergy() >= 500) {
            spaceColony.addE(-500); isBuy15 = false;
            std::cout << "[+] Успешно: Собран Ионный двигатель" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 16 && magazv4) {
        if (!isBuy16) {
            std::cout << "[-] Ошибка: Корпус ракеты уже готов!" << std::endl;
        } else if (spaceColony.getEnergy() >= 450) {
            spaceColony.addE(-450); isBuy16 = false;
            std::cout << "[+] Успешно: Собран Корпус ракеты" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 17 && magazv4) {
        if (!isBuy17) {
            std::cout << "[-] Ошибка: Система навигации уже установлена!" << std::endl;
        } else if (spaceColony.getEnergy() >= 400) {
            spaceColony.addE(-400); isBuy17 = false;
            std::cout << "[+] Успешно: Установлена Система навигации" << std::endl;
        } else {
            std::cout << "[-] Недостаточно энергии!" << std::endl;
        }
    }
    else if (action == 18 && magazv4) {
        if (spaceColony.getEnergy() >= 888) {
            spaceColony.addE(-888);
            spaceColony.addBuilding("Космическая ракета");
            spaceColony.winGame(); // Вызов финальной заставки
        } else {
            std::cout << "[-] Для постройки ракеты нужно 888 энергии!" << std::endl;
        }
    }
    else if (action == 0) {
        return;
    }
    else {
        std::cout << "[-] Товар недоступен или неверный ввод!" << std::endl;
    }

}


void Parametrs::parametrs() {
    int action;
    std::string name;

    std::cout << "==== Настройки ====" << std::endl;
    std::cout << "1. Изменить имя. " << std::endl;
    std::cout << "2. Сохранить игру" << std::endl;
    std::cout << "3. Загрузить игру" << std::endl;
    std::cout << "4. Удалить сохранение" << std::endl;
    std::cout << "0. Назад" << std::endl;
    std::cin >> action;

    while (action < 0 || action > 4) {
        std::cout << "Введите число 0-4: " << std::endl;
        std::cin >> action;
    }

    if (action == 1) {
        std::cout << "Напишите имя вашей колоны: ";
        std::cin >> name;
        spaceColony.addN(name);
    }
    else if (action == 2) spaceColony.saveGame();
    else if (action == 3) spaceColony.loadGame();
    else if (action == 4) spaceColony.deleteSave();
}


void infoBuild::infoB() {
    int action;
        std::cout << "\n=== КНИГА ЗНАНИЙ: РУКОВОДСТВО КОЛОНИСТА ===\n\n";

        std::cout << "УРОВЕНЬ I" << std::endl;
        std::cout << "1. Жилой модуль\n";
        std::cout << "   Стоимость: 40 э\n";
        std::cout << "   Эффект: +10 к лимиту населения\n";
        std::cout << "   Описание: Базовый отсек с жилыми каютами. Позволяет разместить больше людей.\n\n";

        std::cout << "2. Гидропонная лаборатория\n";
        std::cout << "   Стоимость: 60 э\n";
        std::cout << "   Эффект: +22 еды, +6 воды за ход\n";
        std::cout << "   Описание: Система выращивания растений без почвы. Обеспечивает колонию провизией.\n\n";

        std::cout << "3. Солнечная батарея\n";
        std::cout << "   Стоимость: 50 э\n";
        std::cout << "   Эффект: +20 энергии за ход\n";
        std::cout << "   Описание: Конвертирует солнечный свет в электричество для работы систем жизнеобеспечения.\n\n";

        std::cout << "4. Исследовательская лаборатория\n";
        std::cout << "   Стоимость: 55 э\n";
        std::cout << "   Эффект: +6 очков исследований за ход\n";
        std::cout << "   Описание: Научный центр для анализа данных и открытия новых уровней магазина.\n\n";

        std::cout << "УРОВЕНЬ II" << std::endl;
        std::cout << "5. Кислородный переработчик\n";
        std::cout << "   Стоимость: 80 э\n";
        std::cout << "   Эффект: +12 к уровню кислорода\n";
        std::cout << "   Описание: Очищает и восстанавливает атмосферу внутри купола.\n\n";

        std::cout << "6. Купол отдыха\n";
        std::cout << "   Стоимость: 120 э\n";
        std::cout << "   Эффект: +1 к текущему населению\n";
        std::cout << "   Описание: Место для досуга, привлекающее новых жителей своим комфортом.\n\n";

        std::cout << "7. Переработчик отходов\n";
        std::cout << "   Стоимость: 65 э\n";
        std::cout << "   Эффект: +7 к производству еды\n";
        std::cout << "   Описание: Замкнутый цикл переработки, позволяющий получать питательную смесь из отходов.\n\n";

        std::cout << "8. Жилой модуль II\n";
        std::cout << "   Стоимость: 90 э\n";
        std::cout << "   Эффект: +4 к лимиту населения\n";
        std::cout << "   Описание: Улучшенные каюты повышенной плотности для расширения колонии.\n\n";

        std::cout << "9. Солнечная батарея II\n";
        std::cout << "   Стоимость: 85 э\n";
        std::cout << "   Эффект: +10 к выработке энергии\n";
        std::cout << "   Описание: Панели с улучшенным покрытием для работы при слабом освещении.\n\n";

        std::cout << "УРОВЕНЬ III" << std::endl;
        std::cout << "10. Горнодобывающий пост\n";
        std::cout << "    Стоимость: 110 э\n";
            std::cout << "    Эффект: +10 к энергии\n";
        std::cout << "    Описание: Глубинное бурение для добычи геотермального тепла или изотопов.\n\n";

        std::cout << "11. Медицинский отсек\n";
        std::cout << "    Стоимость: 155 э\n";
        std::cout << "    Эффект: +1 к текущему населению\n";
        std::cout << "    Описание: Автоматизированный госпиталь, спасающий жизни колонистов.\n\n";

        std::cout << "12. Чертеж ракеты\n";
        std::cout << "    Стоимость: 420 э\n";
        std::cout << "    Эффект: Необходим для финальной постройки\n";
        std::cout << "    Описание: Уникальная технология, без которой невозможно покинуть планету.\n\n";

        std::cout << "13. Биокупол\n";
        std::cout << "    Стоимость: 130 э\n";
        std::cout << "    Эффект: +10 еды, +5 воды\n";
        std::cout << "    Описание: Гигантская оранжерея с собственной экосистемой.\n\n";

        std::cout << "14. Центральная лаборатория\n";
        std::cout << "    Стоимость: 125 э\n";
        std::cout << "    Эффект: +30 очков исследований\n";
        std::cout << "    Описание: Главный компьютерный центр для глобальных расчетов.\n\n";

        std::cout << "УРОВЕНЬ IV" << std::endl;
        std::cout << "15. Ядерный реактор\n";
        std::cout << "    Стоимость: 250 э\n";
        std::cout << "    Эффект: +70 к энергии\n";
        std::cout << "    Описание: Самый мощный источник питания, работающий на ядерном распаде.\n\n";

        std::cout << "16. Генетическая лаборатория\n";
        std::cout << "    Стоимость: 220 э\n";
        std::cout << "    Эффект: +5 к текущему населению\n";
        std::cout << "    Описание: Клонирование и биологическое ускорение роста популяции.\n\n";

        std::cout << "17. Космический док\n";
        std::cout << "    Стоимость: 300 э\n";
        std::cout << "    Эффект: +3 колониста каждые 15 ходов\n";
        std::cout << "    Описание: Орбитальный лифт, доставляющий переселенцев с Земли.\n\n";

        std::cout << "18. Космическая ракета\n";
        std::cout << "    Стоимость: 888 э\n";
        std::cout << "    Эффект: Завершение миссии\n";
        std::cout << "    Описание: Ваш билет домой. Постройка ракеты означает успешный финал игры.\n\n";
        std::cout << "0. Назад: " << std::endl;
        std::cin >> action;

        while (action < 0 || action > 18) {
            std::cout << "Введите число 0-18: " << std::endl;
            std::cin >> action;
        }
    }
void mooDs::upMood(int amount) {
    if (spaceColony.getMood() > 100) {
        spaceColony.setMood(100);
    }
    if (spaceColony.getMood() >= 100) {
        std::cout << "Настроение на максимуме!" << std::endl;
    }
    else if (spaceColony.getMood() < 100) {
        spaceColony.addM(10); // Прибавляем 10
    }
}
void treeUp::researchPoints() { spaceColony.addR(10); }
void treeUp::tree() {
    int choice;
    std::cout << "\n====================================================" << std::endl;
    std::cout << "          ДРЕВО ТЕХНОЛОГИЙ И УЛУЧШЕНИЙ            " << std::endl;
    std::cout << "          Доступно исследований: " << spaceColony.getResearch() << std::endl;
    std::cout << "====================================================" << std::endl;

    // --- УРОВЕНЬ I (Базовый) ---
    std::cout << "--- УРОВЕНЬ I (Базовый) ---" << std::endl;
    std::cout << "1. Протокол «Общий сбор»        — [30 иссл.]" << std::endl;
    std::cout << "   Эффект: +5 к настроению сразу | Потребление еды +20%" << std::endl;
    std::cout << "2. Система рационирования       — [45 иссл.]" << std::endl;
    std::cout << "   Эффект: Еда -50% | Настроение -2 каждый ход" << std::endl;
    std::cout << "3. Персональные аудио-дневники  — [50 иссл.]" << std::endl;
    std::cout << "   Эффект: Лаборатории дают +2 к настроению (Пассивно)" << std::endl;

    // --- УРОВЕНЬ II ---
    std::cout << "\n";
    if (magazv2 == false) std::cout << "--- УРОВЕНЬ II (Закрыто) ---" << std::endl;
    else std::cout << "--- УРОВЕНЬ II (Открыто) ---" << std::endl;

    std::cout << "4. Организация Пира             — [80 иссл.]" << std::endl;
    std::cout << "   Эффект: Разблокирует функцию 'Пир' в меню" << std::endl;
    std::cout << "5. Спортивные трансляции        — [100 иссл.]" << std::endl;
    std::cout << "   Эффект: Жилой модуль дает +2 к настроению" << std::endl;
    std::cout << "6. Ночная смена                 — [120 иссл.]" << std::endl;
    std::cout << "   Эффект: Ресурсы +50% | Шанс поломки +15%" << std::endl;

    // --- УРОВЕНЬ III ---
    std::cout << "\n";
    if (magazv3 == false) std::cout << "--- УРОВЕНЬ III (Закрыто) ---" << std::endl;
    else std::cout << "--- УРОВЕНЬ III (Открыто) ---" << std::endl;

    std::cout << "7. Виртуальная реальность       — [200 иссл.]" << std::endl;
    std::cout << "   Эффект: Настроение не падает ниже 40 единиц" << std::endl;
    std::cout << "8. Автоматизированная медицина  — [250 иссл.]" << std::endl;
    std::cout << "   Эффект: Защита населения от гибели в событиях" << std::endl;

    // --- УРОВЕНЬ IV ---
    std::cout << "\n";
    if (magazv4 == false) std::cout << "--- УРОВЕНЬ IV (Закрыто) ---" << std::endl;
    else std::cout << "--- УРОВЕНЬ IV (Открыто) ---" << std::endl;

    std::cout << "9. Межпланетная торговля        — [400 иссл.]" << std::endl;
    std::cout << "   Эффект: Разблокирует обмен Исследований на Энергию" << std::endl;
    std::cout << "10. Пропаганда «Путь домой»     — [600 иссл.]" << std::endl;
    std::cout << "    Эффект: Ускорение добычи ресурсов" << std::endl;

    std::cout << "\n0. Вернуться в меню" << std::endl;
    std::cout << "Выберите номер технологии для изучения: ";
    std::cin >> choice;

    if (choice == 0) return;

    // Логика покупки
    if (choice == 1 && spaceColony.getResearch() >= 30) {
        spaceColony.addR(-30);
        spaceColony.addM(5);
        std::cout << "[УСПЕХ] Протокол активирован!" << std::endl;
    }
    else if (choice == 2 && spaceColony.getResearch() >= 45) {
        spaceColony.addR(-45);
        spaceColony.setRationing(true);
        std::cout << "[УСПЕХ] Система рационирования введена в эксплуатацию." << std::endl;
    }
    else if (choice == 3 && spaceColony.getResearch() >= 50) {
        spaceColony.addR(-50);
        spaceColony.setAudioDiaries(true);
        std::cout << "[УСПЕХ] Теперь колонисты делятся мыслями через аудио-дневники." << std::endl;
    }
    else if (choice == 4 && magazv2 && spaceColony.getResearch() >= 80) {
        spaceColony.addR(-80);
        // Этот флаг разблокирует кнопку 4 в главном меню
        std::cout << "[УСПЕХ] Теперь вы можете устраивать праздники через главное меню!" << std::endl;
    }
    else if (choice == 7 && magazv3 && spaceColony.getResearch() >= 200) {
        spaceColony.addR(-200);
        spaceColony.setVR(true);
        std::cout << "[УСПЕХ] Установлены серверы виртуальной реальности." << std::endl;
    }
    else if (choice == 8 && magazv3 && spaceColony.getResearch() >= 250) {
        spaceColony.addR(-250);
        spaceColony.setAutoMed(true);
        std::cout << "[УСПЕХ] Медицинские нано-боты запущены в систему вентиляции." << std::endl;
    }
    else if (choice == 9 && magazv4 && spaceColony.getResearch() >= 400) {
        spaceColony.addR(-400);
        spaceColony.setTrade(true);
        std::cout << "[УСПЕХ] Установлена связь с торговыми флотами (Пункт 7 в меню)." << std::endl;
    }
    else if (choice == 10 && magazv4 && spaceColony.getResearch() >= 600) {
        spaceColony.addR(-600);
        spaceColony.setPropaganda(true);
        std::cout << "[УСПЕХ] Пропаганда запущена: вера в возвращение домой увеличила производительность труда на 30%!" << std::endl;
    }
    else {
        std::cout << "[ОШИБКА] Недостаточно исследований или уровень (Tier) еще заблокирован!" << std::endl;
    }
}

#include "SpaceColony.h"
#include "GameLogic.h"


class startGame {
    gameMotion gMotion;
    Magazin magaz;
    treeUp trUp;
    mooDs moodSys;
    Parametrs param;
    infoBuild info;
    int motion = 0;

public:
    void mainMenu() {
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
        int action; std::cin >> action;

        if (action == 1) {
            motion++;
            magaz.applyTurnBonuses();
            spaceColony.addF(-(spaceColony.getPeople() / 5));
            gMotion.randMotion();
            trUp.researchPoints();
            spaceColony.gameOver();
        }
        else if (action == 2) magaz.magazine();
        else if (action == 3) param.parametrs();
        else if (action == 0) spaceColony.stopGame();
    }
};
