#ifndef CONCRETE_PRODUCT
#define CONCRETE_PRODUCT 1

#include "Product.h"

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class ConcreteProduct : public Product {
private:

public:

    ConcreteProduct() {}
    virtual ~ConcreteProduct() {}

    void something() override {
        cout << "something" << endl;
    }
};

} // namespace design

#endif // CONCRETE_PRODUCT
