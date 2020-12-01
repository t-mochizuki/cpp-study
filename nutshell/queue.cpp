#ifndef QUEUE
#define QUEUE 1

namespace nutshell {

template<class T>
class Queue {
public:
    int head = 0;
    int tail = 0;
    T* _a = NULL;

    Queue(T* a): _a(a) {}
    Queue(const Queue&) = default;
    Queue& operator=(const Queue&) = delete;

    void enqueue(T x) {
        _a[tail++] = x;
    }

    T dequeue() {
        return _a[head++];
    }

    bool empty() {
        return head == tail;
    }
};

} // namespace nutshell

#endif // QUEUE
