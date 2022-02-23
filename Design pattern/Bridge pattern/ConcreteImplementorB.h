#ifndef CONCRETE_IMPLEMENTOR_B
#define CONCRETE_IMPLEMENTOR_B 1

#include "Implementor.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ConcreteImplementorB : public Implementor {
private:

public:

    ConcreteImplementorB() {}
    virtual ~ConcreteImplementorB() {}

    void operation() override {
        cout << "ConcreteImplementorB" << endl;
    }
};

} // namespace design

#endif // CONCRETE_IMPLEMENTOR_B
