// g++ -std=c++14 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <vector>
#include "Singleton.h"

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

design::Singleton* design::Singleton::instance;

class Program {
private:

public:

    Program() {
        auto config1 = design::Singleton::getInstance();
        auto config2 = design::Singleton::getInstance();
        assert(config1 == config2);
        delete config1;
    }

    void solve() {
    }
};

int main() {

    Program p;
    p.solve();

    return 0;
}
