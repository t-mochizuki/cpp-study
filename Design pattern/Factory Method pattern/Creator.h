#ifndef CREATOR
#define CREATOR 1

#include "Product.h"

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class Creator {
private:

public:

    Creator() {}
    virtual ~Creator() {}

    void operation() {
        Product* product = factoryMethod();
        product->something();
        delete product;
    }

    virtual Product* factoryMethod() {
        return NULL;
    }
};

} // namespace design

#endif // CREATOR
