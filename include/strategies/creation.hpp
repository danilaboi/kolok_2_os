#pragma once

template <typename T>
struct CreateUsingNew {
    static T* Create() { return new T; }
    static void Destroy(T* p) { delete p; }
};

template <typename T>
struct CreateStatic {
    static T* Create() {
        static T instance;
        return &instance;
    }
    static void Destroy(T*) {}
};
