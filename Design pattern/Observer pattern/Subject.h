#ifndef SUBJECT
#define SUBJECT 1

#include "Observer.h"

namespace design {

#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Observer;

/*
 * 観察対象
 * 観察者にイベントの発生を通知する
 * 観察者の型をカプセル化する
 */
class Subject {
private:

    vector<Observer*> observers;

public:

    Subject() {}

    virtual ~Subject() {
        cout << "Delete a subject" << endl;
    }

    /*
     * 指定した観察者を観察者の一覧に追加する
     */
    void addObserver(Observer& o) {
        observers.push_back(&o);
    };

    /*
     * 指定した観察者を観察者の一覧から削除する
     */
    void removeObserver(Observer& o) {
        // todo
    };

    void notifyObserver() {
        for (auto o : observers) {
            o->update();
        }
    };
};

} // namespace design

#endif // SUBJECT
