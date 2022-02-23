#ifndef PRODUCT_B_2
#define PRODUCT_B_2 1

#include "AbstractProductB.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ProductB2 : public AbstractProductB {
private:

public:

    ProductB2() {}
    virtual ~ProductB2() {
        cout << "Delete ProductB2" << endl;
    }
};

} // namespace design

#endif // PRODUCT_B_2
