#include <iostream>
#include <numeric>
#include <vector>
#include "checker.h"

using namespace std;

void func1(int n) {
    vector<int> x(n);
    iota(x.begin(), x.end(), 0);

    int temp = 0;
    for (int i : x) {
        temp = i;
    }
    cout << temp << endl;
}

void func2(int n) {
    vector<int> x(n);
    iota(x.begin(), x.end(), 0);

    int temp = 0;
    for (int i : x) {
        for (int j : x) {
            temp += i + j;
        }
    }
    cout << temp << endl;
}

void func3(int n) {
    //vector<int> x(n);
    //iota(x.begin(), x.end(), 0);

    int temp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; i < n; ++i) {
            for (int k = 0; i < n; ++i) {
                temp += (i + j + k);
            }
        }
    }
    cout << temp << endl;
}

int main(int argc, char **argv) {
    ComplexityChecker c;

    void (*f)(int) = &func1;
    c.checkComplexity(f, 10000000, 10);

    void (*f2)(int) = &func2;
    c.checkComplexity(f2, 1000, 10);

    void (*f3)(int) = &func3;
    c.checkComplexity(f2, 5000, 10);

}
