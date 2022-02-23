// g++ -std=c++14 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <vector>
#include "Factory1.h"
#include "Factory2.h"

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

using namespace design;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

public:

    Program() {
    }

    void solve() {
        Factory1 f1;
        AbstractProductA* pa1 = f1.createProductA();
        delete pa1;
        AbstractProductB* pb1 = f1.createProductB();
        delete pb1;

        Factory2 f2;
        AbstractProductA* pa2 = f2.createProductA();
        delete pa2;
        AbstractProductB* pb2 = f2.createProductB();
        delete pb2;
    }
};

int main() {

    Program p;
    p.solve();

    return 0;
}
