#ifndef CONCRETE_OBSERVER
#define CONCRETE_OBSERVER 1

#include "ConcreteSubject.h"
#include "Observer.h"

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class ConcreteObserver : public Observer {
private:

    ConcreteSubject& subject;

public:

    ConcreteObserver(ConcreteSubject& subject): subject(subject) {}

    ~ConcreteObserver() {
        cout << "Delete a concrete observer" << endl;
    }

    void update() override {
        cout << "Observer to observe " << subject.getName() << " subject" << endl;
    }
};

}

#endif // CONCRETE_OBSERVER
