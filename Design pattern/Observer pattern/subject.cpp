#ifndef SUBJECT
#define SUBJECT 1

namespace design {

#include <vector>
#include "observer"

using std::vector;

/*
 * 観察対象
 * 観察者にイベントの発生を通知する
 * 観察者の型をカプセル化する
 */
class Subject {
private:

    vector<Observer*> observers;

public:

    Subject() {
    }

    virtual ~Subject() {}

    /*
     * 指定した観察者を観察者の一覧に追加する
     */
    void addObserver(Observer* o) {
        observers.push_back(o);
    }

    /*
     * 指定した観察者を観察者の一覧から削除する
     */
    void removeObserver(Observer* o) {
        // todo
    }

    void notifyObserver() {
        for (auto o : observers) {
            o->update();
        }
    }
};

} // namespace design

#endif // SUBJECT
