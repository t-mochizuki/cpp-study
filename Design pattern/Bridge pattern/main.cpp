// g++ -std=c++14 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include "ConcreteImplementorA.h"
#include "ConcreteImplementorB.h"
#include "RefinedAbstraction.h"

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
        design::ConcreteImplementorA impA;
        design::ConcreteImplementorB impB;

        design::RefinedAbstraction abstractionA(impA);
        abstractionA.operation();

        design::RefinedAbstraction abstractionB(impB);
        abstractionB.operation();
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Program p;
        p.solve();
    }
#else
    Program p;
    p.solve();
#endif

    return 0;
}
