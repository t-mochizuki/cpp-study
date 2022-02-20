#ifndef SUBJECT
#define SUBJECT 1

namespace design {

#include <vector>

using std::vector;

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

    Subject() {
    }

    virtual ~Subject() {
        cout << "Delete a subject" << endl;
    }

    /*
     * 指定した観察者を観察者の一覧に追加する
     */
    void addObserver(Observer* o);

    /*
     * 指定した観察者を観察者の一覧から削除する
     */
    void removeObserver(Observer* o);

    void notifyObserver();
};

} // namespace design

#endif // SUBJECT
