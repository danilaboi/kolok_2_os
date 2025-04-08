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
    std::cout << "1. �������� ��� ���������\n";
    std::cout << "2. �������� ���������\n";
    std::cout << "3. �������� �� �������� �� ���������\n";
    std::cout << "0. �����\n";
    std::cout << "�������� �����: ";
}

void updateSetting() {
    auto& settings = GlobalGameSettings::Instance();
    std::string key;
    std::cout << "�������� ��������� ��� ��������� (resolution/fullscreen/volume): ";
    std::cin >> key;

    if (key == "volume") {
        int vol;
        std::cout << "������� �������� ��������� (0�100): ";
        std::cin >> vol;
        if (vol < 0 || vol > 100) {
            std::cout << "[������] ��������� ������ ���� �� 0 �� 100\n";
        }
        else {
            settings.set("volume", std::to_string(vol));
            std::cout << "[OK] ��������� ���������\n";
        }
    }
    else if (key == "resolution") {
        int width, height;
        std::cout << "������� ������ (��������, 1920): ";
        std::cin >> width;
        std::cout << "������� ������ (��������, 1080): ";
        std::cin >> height;

        if (width <= 0 || height <= 0) {
            std::cout << "[������] ������ � ������ ������ ���� �������������� �������\n";
        }
        else {
            settings.set("resolution", std::to_string(width) + "x" + std::to_string(height));
            std::cout << "[OK] ���������� ���������\n";
        }
    }
    else if (key == "fullscreen") {
        std::string value;
        std::cout << "������� �������� (true/false): ";
        std::cin >> value;

        std::transform(value.begin(), value.end(), value.begin(), ::tolower);

        if (value == "true" || value == "false") {
            settings.set("fullscreen", value);
            std::cout << "[OK] ������������� ����� �������\n";
        }
        else {
            std::cout << "[������] ��������� ������ �������� true ��� false\n";
        }
    }
    else {
        std::cout << "[������] ����������� ���������\n";
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
            std::cout << "�����...\n";
            break;
        default:
            std::cout << "�������� �����. ���������� �����.\n";
        }
    }

    return 0;
}