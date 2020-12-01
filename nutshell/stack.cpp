#ifndef STACK
#define STACK 1

namespace nutshell {

template<class T>
class Stack {
public:
    int top = -1;
    T* _a = NULL;

    Stack(T* a): _a(a) {};
    Stack(const Stack&) = default;
    Stack& operator=(const Stack&) = delete;

    void push(T x) {
        _a[++top] = x;
    }

    T pop() {
        return _a[top--];
    }

    T peak() {
        return _a[top];
    }

    bool empty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }
};

} // namespace nutshell

#endif // STACK
