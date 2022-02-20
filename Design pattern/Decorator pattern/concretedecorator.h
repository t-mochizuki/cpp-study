#ifndef CONCRETEDECORATOR
#define CONCRETEDECORATOR 1

#include "decorator.h"

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class ConcreteDecorator : public Decorator {
private:

    Component* component;

public:

    ConcreteDecorator(Component& component): component(&component) {}
    virtual ~ConcreteDecorator() {
        cout << "~ConcreteDecorator" << endl;
    }

    void operate() override;
};

} // namespace design

#endif // CONCRETEDECORATOR
