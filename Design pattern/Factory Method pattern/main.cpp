// g++ -std=c++14 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <vector>
#include "ConcreteCreator.h"

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

public:

    Program() {
    }

    void solve() {
        design::ConcreteCreator creator = design::ConcreteCreator();
        creator.operation();
    }
};

int main() {

    Program p;
    p.solve();

    return 0;
}
