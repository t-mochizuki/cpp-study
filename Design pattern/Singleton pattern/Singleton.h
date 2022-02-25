#ifndef SINGLETON
#define SINGLETON 1

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Singleton {
private:

    Singleton() {}
    static Singleton* instance;

public:

    virtual ~Singleton() {}
    static Singleton* getInstance() {
        if (instance == 0x0) {
            instance = new Singleton();
        }

        return instance;
    }

};

} // namespace design

#endif // SINGLETON
