// g++ -std=c++14 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "observer.cpp"
#include "subject.cpp"

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class ConcreteObserver : public design::Observer {
private:

    string name;

public:

    ConcreteObserver(string name): name(name) {}

    void update(design::Subject* s) override {
        cout << "Subject: " << s << endl;
        cout << "name: " << name << endl;
    }
};

class Program {
private:

public:

    Program() {
    }

    void solve() {
        design::Subject s;
        auto foo = new ConcreteObserver("foo");
        auto bar = new ConcreteObserver("bar");

        s.addObserver(foo);
        s.addObserver(bar);

        s.notifyObserver();
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
