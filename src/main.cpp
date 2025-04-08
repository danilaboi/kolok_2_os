#include <iostream>
#include <string>
#include <cctype> 
#include <algorithm>
#include <Windows.h>
#include "game_settings.hpp"
#include "singleton_holder.hpp"
#include "strategies/creation.hpp"
#include "strategies/lifetime.hpp"
#include "strategies/threading.hpp"
using GlobalGameSettings = SingletonHolder<
    GameSettings,
    CreateStatic<GameSettings>,
    DefaultLifetime<GameSettings>,
    MultiThreaded
>;

void printMenu() {
    std::cout << "\n=== Game Settings Manager ===\n";
    std::cout << "1. Показать все настройки\n";
    std::cout << "2. Изменить настройку\n";
    std::cout << "3. Сбросить на значения по умолчанию\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите опцию: ";
}

void updateSetting() {
    auto& settings = GlobalGameSettings::Instance();
    std::string key;
    std::cout << "Выберите настройку для изменения (resolution/fullscreen/volume): ";
    std::cin >> key;

    if (key == "volume") {
        int vol;
        std::cout << "Введите значение громкости (0–100): ";
        std::cin >> vol;
        if (vol < 0 || vol > 100) {
            std::cout << "[Ошибка] Громкость должна быть от 0 до 100\n";
        }
        else {
            settings.set("volume", std::to_string(vol));
            std::cout << "[OK] Громкость обновлена\n";
        }
    }
    else if (key == "resolution") {
        int width, height;
        std::cout << "Введите ширину (например, 1920): ";
        std::cin >> width;
        std::cout << "Введите высоту (например, 1080): ";
        std::cin >> height;

        if (width <= 0 || height <= 0) {
            std::cout << "[Ошибка] Ширина и высота должны быть положительными числами\n";
        }
        else {
            settings.set("resolution", std::to_string(width) + "x" + std::to_string(height));
            std::cout << "[OK] Разрешение обновлено\n";
        }
    }
    else if (key == "fullscreen") {
        std::string value;
        std::cout << "Введите значение (true/false): ";
        std::cin >> value;

        std::transform(value.begin(), value.end(), value.begin(), ::tolower);

        if (value == "true" || value == "false") {
            settings.set("fullscreen", value);
            std::cout << "[OK] Полноэкранный режим обновлён\n";
        }
        else {
            std::cout << "[Ошибка] Допустимы только значения true или false\n";
        }
    }
    else {
        std::cout << "[Ошибка] Неизвестная настройка\n";
    }
}

int main() {
    std::locale::global(std::locale("Russian"));
    std::wcout.imbue(std::locale("Russian"));
    auto& settings = GlobalGameSettings::Instance();
    settings.loadDefaults();

    int choice = -1;
    while (choice != 0) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            settings.printAll();
            break;
        case 2:
            updateSetting();
            break;
        case 3:
            settings.loadDefaults();
            break;
        case 0:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}