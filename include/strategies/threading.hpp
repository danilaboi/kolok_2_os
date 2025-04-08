#pragma once
#include <mutex>

struct SingleThreaded {
    struct Lock {
        Lock() {}
    };
};

struct MultiThreaded {
    static std::mutex& GetMutex() {
        static std::mutex mtx;
        return mtx;
    }

    struct Lock {
        Lock() { GetMutex().lock(); }
        ~Lock() { GetMutex().unlock(); }
    };
};
