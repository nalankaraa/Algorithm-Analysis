#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;

public:
    void start()
    {
        startTime = std::chrono::high_resolution_clock::now();
    }

    void stop()
    {
        endTime = std::chrono::high_resolution_clock::now();
    }

    double elapsedMilliseconds() const
    {
        return std::chrono::duration<double, std::milli>(endTime - startTime).count();
    }

    double elapsedMicroseconds() const
    {
        return std::chrono::duration<double, std::micro>(endTime - startTime).count();
    }
};

#endif
