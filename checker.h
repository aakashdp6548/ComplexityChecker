#ifndef CHECKER_H
#define CHECKER_H

#include <iostream>
#include <cassert>
#include <chrono>
#include <algorithm>
#include <cmath>

// general program function -> test function, void return type and 1 integer parameter -> checker function

class Timer {
    std::chrono::time_point<std::chrono::system_clock> cur;
    std::chrono::duration<double> elap;
public:
    Timer() : cur(), elap(std::chrono::duration<double>::zero()) { }
    void start() {
        cur = std::chrono::system_clock::now();
    }

    void stop() {
        elap += std::chrono::system_clock::now() - cur;
    }

    void reset() {
        elap = std::chrono::duration<double>::zero();
    }

    double seconds() {
        return elap.count();
    }
};

class ComplexityChecker {
public:

    // requires: function pointer to void function with one integer argument
    double runTrial(void (*func)(int), int n) {
        Timer timer;
        timer.start();
        func(n);
        timer.stop();
        return timer.seconds();
    }

    // requires: function pointer to void function with one integer argument
    void checkComplexity(void (*func)(int), int size, int trials) {

        double averageRatio = findAverageRatio(func, size, trials);

        // determine what complexity this average ratio corresponds to, within error
        calcComplexity(averageRatio);
    }

private:

    double findAverageRatio(void (*func)(int), int size, int trials) {
        Timer timer;

        double ratioSum = 0;
        // run numTrials times to get an average ratio
        for (int i = 0; i < trials; ++i) {
            // get time for N
            double time1 = runTrial(func, size);
            // get time for 2N
            double time2 = runTrial(func, 2 * size);
            //std::cerr << time1 << " " << time2 << std::endl;

            ratioSum += time2 / time1;
        }
        // calculate average
        return ratioSum / trials;
    }

    void calcComplexity(double averageRatio) {
        std::vector<std::pair<int, std::string>> values = {
            {1, "O(1)"}, {2, "O(n)"}, {4, "O(n^2)"}, {8, "O(n^3)"}
        };
        auto it = std::find_if(values.begin(), values.end(),
            [averageRatio](std::pair<int, std::string> p) {
                double epsilon = static_cast<double>(p.first) / 10;
                return (fabs(p.first - averageRatio) < epsilon);
            }
        );
        if (it == values.end()) {
            std::cerr << "The complexity could not be found. Maybe try with a larger input size?\n";
        }
        else {
            std::cerr << "The complexity is " << (*it).second << ".\n";
        }
        std::cerr << "(The average ratio was " << averageRatio << ".)\n";
    }
};






#endif
