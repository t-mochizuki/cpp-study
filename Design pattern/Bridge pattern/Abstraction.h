#ifndef ABSTRACTION
#define ABSTRACTION 1

namespace design {

/*
 * 抽象的側面
 */
class Abstraction {
private:

    Implementor* imp;

public:

    Abstraction(Implementor& imp): imp(&imp) {}
    virtual ~Abstraction() {}

    void operation() {
        imp->operation();
    }
};

} // namespace design

#endif // ABSTRACTION
