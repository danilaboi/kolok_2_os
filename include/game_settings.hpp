#pragma once
#include <string>
#include <unordered_map>
#include <iostream>

class GameSettings {
public:
    void set(const std::string& key, const std::string& value) {
        settings[key] = value;
    }

    std::string get(const std::string& key) const {
        auto it = settings.find(key);
        return it != settings.end() ? it->second : "";
    }

    void loadDefaults() {
        settings["resolution"] = "1920x1080";
        settings["fullscreen"] = "true";
        settings["volume"] = "75";
        std::cout << "[GameSettings] Defaults loaded\n";
    }

    void printAll() const {
        std::cout << "[GameSettings] Current values:\n";
        for (const auto& [k, v] : settings) {
            std::cout << "  " << k << ": " << v << "\n";
        }
    }

private:
    std::unordered_map<std::string, std::string> settings;
};
