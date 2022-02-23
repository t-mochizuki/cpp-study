#ifndef PRODUCT_B_1
#define PRODUCT_B_1 1

#include "AbstractProductB.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ProductB1 : public AbstractProductB {
private:

public:

    ProductB1() {}
    virtual ~ProductB1() {
        cout << "Delete ProductB1" << endl;
    }
};

} // namespace design

#endif // PRODUCT_B_1
