#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::set;

const int INF = 1 << 30;

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

class Edge {
public:

    int _v = -1;
    int _value = INF;

    Edge() {}
    Edge(int value, int v): _value(value), _v(v) {}

    friend bool operator<(const Edge& lhs, const Edge& rhs) {
        return lhs._value < rhs._value;
    }
    friend bool operator>(const Edge& lhs, const Edge& rhs) { return rhs < lhs; }
    friend bool operator<=(const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); }
    friend bool operator>=(const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); }
    friend bool operator==(const Edge& lhs, const Edge& rhs) {
        return lhs._value == rhs._value;
    }
    friend bool operator!=(const Edge& lhs, const Edge& rhs) { return !(lhs == rhs); }

    friend std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        return os << e._value;
    }
};

void solve() {
    int n; cin >> n;

    vector<vector<Edge>> E;
    E.resize(n);
    for (int i = 0; i < n; ++i) {
        int u; cin >> u;
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int v; cin >> v;
            int c; cin >> c;
            E[u].push_back(Edge(c, v));
        }
    }

    int dist[n];
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (i == s) {
            dist[i] = 0;
        } else {
            dist[i] = INF;
        }
    }

    Edge a[500005];
    MinHeap<Edge> h(0, a);
    h.insert(Edge(0, s));

    int parent[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = -1;
    }

    set<int> T;

    while (h._heapSize != 0) {
        Edge tmp = h.extract();
        int u = tmp._v;
        int cost = tmp._value;

        if (dist[u] < cost) {
            continue;
        }

        T.insert(u);

        for (auto e : E[u]) {
            if (T.find(e._v) != T.end()) {
                continue;
            }
            if (dist[e._v] > dist[u] + e._value) {
                dist[e._v] = dist[u] + e._value;
                h.insert(Edge(dist[e._v], e._v));
                parent[e._v] = u;
            }
        }
    }

    for (int v = 0; v < n; ++v) {
        cout << v << " " << dist[v] << endl;
    }

    // for (int v = 0; v < n; ++v) {
    //     if (v == n - 1) {
    //         cout << dist[v] << endl;
    //     } else {
    //         cout << dist[v] << " ";
    //     }
    // }

    // for (int v = 0; v < n; ++v) {
    //     if (v == n - 1) {
    //         cout << parent[v] << endl;
    //     } else {
    //         cout << parent[v] << " ";
    //     }
    // }
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
