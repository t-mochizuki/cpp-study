#ifndef CONCRETE_CREATOR
#define CONCRETE_CREATOR 1

#include "Creator.h"
#include "ConcreteProduct.h"

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class ConcreteCreator : public Creator {
private:

public:

    ConcreteCreator() {}
    virtual ~ConcreteCreator() {}

    ConcreteProduct* factoryMethod() override {
        return new ConcreteProduct();
    }
};

} // namespace design

#endif // CONCRETE_CREATOR
