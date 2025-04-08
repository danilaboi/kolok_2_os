# 🎮 GameSettingsManager

**GameSettingsManager** — это консольное C++ приложение, демонстрирующее реализацию паттерна **Singleton** на основе **ортогональных стратегий**, как описано в книге *Андрей Александреску — Modern C++ Design*.

Проект позволяет управлять игровыми настройками через интерактивное меню, сохраняя глобальное, потокобезопасное и настраиваемое поведение.

---

## 📌 Возможности

- Хранение и изменение параметров:
  - Разрешение экрана (`resolution`)
  - Режим отображения (`fullscreen`)
  - Громкость (`volume`)
- Проверка ввода:
  - Громкость от 0 до 100
  - Разрешение вводится как ширина и высота
  - Только `true`/`false` для `fullscreen`
- Гибкая архитектура:
  - Используются стратегии `CreateStatic`, `DefaultLifetime`, `MultiThreaded`
  - Поведение Singleton задаётся шаблонами

---

## 📦 Установка и запуск

### ⚙️ Требования:
- Visual Studio 2019/2022
- Установленный `Desktop development with C++`
- Поддержка `C++17`

### 🚀 Инструкция:

1. Клонируй или скачай проект в виде папки:
- GameSettingsManager/ ├── include/ ├── src/ ├── CMakeLists.txt

2. Открой папку как проект в Visual Studio:
- `File > Open > Folder...` → выбери корневую папку проекта

3. Visual Studio предложит использовать CMake — подтверди

4. В `src/main.cpp` нажми правой кнопкой мыши → **Set as Startup Item**

5. Построй и запусти проект:
- `Ctrl + Shift + B` — сборка
- `Ctrl + F5` — запуск без отладчика

---

## 🧠 Как работает программа

При запуске ты попадаешь в меню:
=== Game Settings Manager ===

1. Показать все настройки

2. Изменить настройку

3. Сбросить на значения по умолчанию

4. Выход

Все понятно что делать из меню :)

© 2025 Шуляк Д.К. Все права защищены.

