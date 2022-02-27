#ifndef CONCRETECOMPONENT
#define CONCRETECOMPONENT 1

#include "Component.h"

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class ConcreteComponent : public Component {
private:

public:

    ConcreteComponent() {}
    virtual ~ConcreteComponent() {
        cout << "~ConcreteComponent" << endl;
    }

    void operate() override {
        cout << "ConcreteComponent::operate" << endl;
    };
};

} // namespace design

#endif // CONCRETECOMPONENT
