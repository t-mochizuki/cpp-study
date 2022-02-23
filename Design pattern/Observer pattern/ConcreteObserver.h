#ifndef CONCRETE_OBSERVER
#define CONCRETE_OBSERVER 1

#include "subject.h"
#include "observer.h"

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class ConcreteObserver : public Observer {
private:

    string name;

public:

    ConcreteObserver(string name): name(name) {}

    ~ConcreteObserver() {
        cout << "Delete a concrete observer" << endl;
    }

    void update(Subject* subject) override {
        cout << "Observer to observe " << subject->getName() << " subject" << endl;
    }
};

}

#endif // CONCRETE_OBSERVER
