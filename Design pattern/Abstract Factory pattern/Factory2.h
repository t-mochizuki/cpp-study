#ifndef FACTORY_2
#define FACTORY_2 1

#include "AbstractFactory.h"
#include "ProductA2.h"
#include "ProductB2.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Factory2 : public AbstractFactory {
private:

public:

    Factory2() {}
    virtual ~Factory2() {}

    AbstractProductA* createProductA() override { return new ProductA2; }
    AbstractProductB* createProductB() override { return new ProductB2; }
};

} // namespace design

#endif // FACTORY_2
