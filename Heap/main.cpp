#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

template<class T> inline void swap(T &A, T &B) {
    T tmp = A;
    A = B;
    B = tmp;
}

class Heap {
public:
    int* _a = NULL;
    int _heapSize;

    Heap(int heapSize, int* a): _heapSize(heapSize), _a(a) {}

    int top() {
        return _a[0];
    }

    void update(int i, int x) {
        _a[i] = x;
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

    void upHeap(int i) {
        while (true) {
            if (i <= 0) {
                break;
            }

            int j = parent(i);

            if (_a[i] <= _a[j]) {
                break;
            }

            swap(_a[i], _a[j]);

            i = j;
        }
    }

    void downHeap(int i) {
        while (true) {
            int l = left(i);
            if (l >= _heapSize) {
                break;
            }

            int j = i;
            if (_a[l] > _a[i]) {
                j = l;
            }

            int r = right(i);
            if (r >= _heapSize) {
                break;
            }

            if (_a[r] > _a[j]) {
                j = r;
            }

            if (j == i) {
                break;
            }

            swap(_a[i], _a[j]);

            i = j;
        }
    }

    int extract() {
        int ret = _a[0];
        _a[0] = _a[_heapSize - 1];
        _heapSize--;
        downHeap(0);
        return ret;
    }

    void insert(int x) {
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

void solve() {
    int n; cin >> n;

    int a[100];
    Heap h = Heap(0, a);

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        h.insert(x);
    }

    h.print();
    cout << h.extract() << endl;
    h.print();
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
