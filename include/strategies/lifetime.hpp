#pragma once
#include <cstdlib>
#include <stdexcept>

template <typename T>
struct DefaultLifetime {
    static void ScheduleDestruction(T* obj, void (*pFun)()) {
        atexit(pFun);
    }

    static void OnDeadReference() {
        throw std::runtime_error("Dead Reference Detected");
    }
};
