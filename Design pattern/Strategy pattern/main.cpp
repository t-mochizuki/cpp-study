// g++ -std=c++14 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include "Context.h"
#include "ConcreteStrategy.h"

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
        Context context;
        ConcreteStrategy foo("foo");
        ConcreteStrategy bar("bar");
        context.interface(foo);
        context.interface(bar);
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
