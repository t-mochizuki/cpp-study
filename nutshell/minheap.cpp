#ifndef MIN_HEAP
#define MIN_HEAP 1

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

namespace nutshell {

template<class T>
class MinHeap {
public:
    T* _a = NULL;
    int _heapSize;

    MinHeap(int heapSize, T* a): _heapSize(heapSize), _a(a) {}

    T top() {
        return _a[0];
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void swap(T &A, T &B) {
        T tmp = A;
        A = B;
        B = tmp;
    }

    void upHeap(int i) {
        while (true) {
            if (i <= 0) {
                break;
            }

            int j = parent(i);

            if (_a[i] >= _a[j]) {
                break;
            }

            swap(_a[i], _a[j]);

            i = j;
        }
    }

    void downHeap(int i) {
        while (true) {
            int j = i;

            int l = left(i);
            if (l >= _heapSize) {
                break;
            }

            if (_a[l] < _a[j]) {
                j = l;
            }

            int r = right(i);
            if (r >= _heapSize) {
                break;
            }

            if (_a[r] < _a[j]) {
                j = r;
            }

            if (i == j) {
                break;
            }

            swap(_a[i], _a[j]);

            i = j;
        }
    }

    T extract() {
        T ret = _a[0];
        _a[0] = _a[_heapSize - 1];
        _heapSize--;
        downHeap(0);
        return ret;
    }

    void insert(T x) {
        _heapSize++;
        _a[_heapSize - 1] = x;
        upHeap(_heapSize - 1);
    }

    void print() {
        for (int i = 0; i < _heapSize; ++i) {
            if (i == _heapSize - 1) {
                cout << _a[i] << endl;
            } else {
                cout << _a[i] << " ";
            }
        }
    }
};

} // namespace nutshell

#endif // MIN_HEAP
