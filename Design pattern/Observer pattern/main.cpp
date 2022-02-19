// g++ -std=c++14 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Observer {
private:

public:

    Observer() {}
    virtual ~Observer() {}

    virtual void update() {
        cout << "Observer" << endl;
    };
};

class ConcreteObserver : public Observer {
private:

    string name;

public:

    ConcreteObserver(string name): name(name) {}

    void update() override {
        cout << "name: " << name << endl;
    }
};

class Subject {
private:

    vector<Observer*> observers;

public:

    Subject() {
    }

    virtual ~Subject() {}

    void addObserver(Observer* o) {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) {
        // todo
    }

    void notifyObserver() {
        for (auto o : observers) {
            o->update();
        }
    }
};

class Program {
private:

public:

    Program() {
    }

    void solve() {
        Subject s;
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
