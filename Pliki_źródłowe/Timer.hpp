#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

class Timer {
    std::chrono::high_resolution_clock::time_point start;
public:
    void rozpocznij() { start = std::chrono::high_resolution_clock::now(); }
    long long zakoncz() {
        auto koniec = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(koniec - start).count();
    }
};

#endif
