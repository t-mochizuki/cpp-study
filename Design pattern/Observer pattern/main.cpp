// g++ -std=c++14 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include "ConcreteSubject.h"
#include "ConcreteObserver.h"

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;

using namespace design;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

public:

    Program() {
    }

    void solve() {
        ConcreteSubject subject("a new record");
        auto foo = ConcreteObserver(subject);
        auto bar = ConcreteObserver(subject);

        subject.addObserver(foo);
        subject.addObserver(bar);

        subject.notifyObserver();
    }
};

int main() {

    Program p;
    p.solve();

    return 0;
}
