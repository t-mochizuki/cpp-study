#ifndef FACTORY_1
#define FACTORY_1 1

#include "AbstractFactory.h"
#include "ProductA1.h"
#include "ProductB1.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Factory1 : public AbstractFactory {
private:

public:

    Factory1() {}
    virtual ~Factory1() {}

    AbstractProductA* createProductA() override { return new ProductA1; }
    AbstractProductB* createProductB() override { return new ProductB1; }
};

} // namespace design

#endif // FACTORY_1
