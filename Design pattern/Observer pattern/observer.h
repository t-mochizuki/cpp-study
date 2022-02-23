#ifndef OBSERVER
#define OBSERVER 1

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class Subject;

/*
 * 観察者
 * 観察対象からのイベントの発生の通知を監視する
 */
class Observer {
private:

public:

    Observer() {};
    virtual ~Observer() {
        cout << "Delete an observer" << endl;
    };

    virtual void update(Subject* s) {
        cout << "Observer" << endl;
    };
};

} // namespace design

#endif // OBSERVER
