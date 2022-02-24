#ifndef ABSTRACT_FACTORY
#define ABSTRACT_FACTORY 1

#include "AbstractProductA.h"
#include "AbstractProductB.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
 * 具象クラスを指定せずに
 * オブジェクトのファミリを生成するインタフェースを提供する
 */
class AbstractFactory {
private:

public:

    AbstractFactory() {}
    virtual ~AbstractFactory() {}

    virtual AbstractProductA* createProductA() { return 0; }
    virtual AbstractProductB* createProductB() { return 0; }
};

} // namespace design

#endif // ABSTRACT_FACTORY
