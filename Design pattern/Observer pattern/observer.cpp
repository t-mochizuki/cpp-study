#ifndef OBSERVER
#define OBSERVER 1

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class Observer {
private:

public:

    Observer() {}
    virtual ~Observer() {}

    virtual void update() {
        cout << "Observer" << endl;
    };
};

} // namespace design

#endif // OBSERVER
