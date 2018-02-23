#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <limits.h>
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

    for (int i = 0 ; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < n; j++) {
            temp += x[j];
        }
        x[i] = temp;
    }
}

void func3(int n) {
    vector<int> x(n);
    iota(x.begin(), x.end(), 0);

    for (int i = 0 ; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                temp += x[j] + x[k];
            }
        }
        x[i] = temp;
    }
}

void func4(int n) {
    int temp = 0;
    while (n > 1) {
        temp += n % 6;
        n /= 2;
    }
    cout << temp << endl;
}

void testFunc1();
void testFunc2();
void testFunc3();
void testFunc4();

int main(int argc, char **argv) {

    testFunc4();

}

void testFunc1() {
    ComplexityChecker c;
    cerr << "func1:\n";
    c.checkComplexity(func1, 10000000, 5);
    cerr << endl;
}

void testFunc2() {
    ComplexityChecker c;
    cerr << "func2:\n";
    c.checkComplexity(func2, 1000, 10);
    cerr << endl;
}

void testFunc3() {
    ComplexityChecker c;
    cerr << "func3:\n";
    c.checkComplexity(func3, 200, 10);
    cerr << endl;
}

void testFunc4() {
    ComplexityChecker c;
    cerr << "func4:\n";
    c.checkComplexity(func4, (INT_MAX - 10) / 2, 10);
    cerr << endl;
}
