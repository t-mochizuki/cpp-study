#ifndef ABSTRACT_CLASS
#define ABSTRACT_CLASS 1

namespace design {

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::runtime_error;

class AbstractClass {
private:

public:

    AbstractClass() {}
    virtual ~AbstractClass() {}

    void templateMethod() {
        if (!preproc()) {
            throw runtime_error("preproc error");
        }

        if (!mainproc()) {
            throw runtime_error("mainproc error");
        }

        if (!postproc()) {
            throw runtime_error("postproc error");
        }
    }

    virtual bool preproc() { return false; }
    virtual bool mainproc() { return false; }
    virtual bool postproc() { return false; }
};

} // namespace design

#endif // ABSTRACT_CLASS
