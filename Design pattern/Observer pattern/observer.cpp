#ifndef OBSERVER
#define OBSERVER 1

namespace design {

#include <iostream>

using std::cout;
using std::endl;

/*
 * 観察者
 * 観察対象からのイベントの発生の通知を監視する
 */
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
