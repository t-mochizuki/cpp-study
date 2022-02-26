#ifndef PRODUCT
#define PRODUCT 1

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class Product {
private:

public:

    Product() {}
    virtual ~Product() {}

    virtual void something() {
        cout << "" << endl;
    }
};

} // namespace design

#endif // PRODUCT
