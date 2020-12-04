#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

const int INF = 2147483647;

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

class RMQ {
public:

    int _n = 1;
    int _N;
    vector<int> _minv;


    RMQ(int len) {
        while (_n < len) {
            _n *= 2;
        }
        _N = 2 * _n - 1;

        _minv.resize(_N, INF);
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

    void update(int i, int x) {
        i += _n - 1;
        _minv[i] = x;

        while (i > 0) {
            i = parent(i);
            _minv[i] = min(_minv[left(i)], _minv[right(i)]);
        }
    }

    int query(int s, int t, int i, int l, int r) {
        int ret = INF;

        if (t <= l || r <= s) {
            ret = INF;
        } else if (s <= l && r <= t) {
            ret = _minv[i];
        } else {
            int vl = query(s, t, left(i), l, (l + r) / 2);
            int vr = query(s, t, right(i), (l + r) / 2, r);
            ret = min(vl, vr);
        }

        return ret;
    }

    int find(int s, int t) {
        return query(s, t + 1, 0, 0, _n);
    }
};

void solve() {
    int n, q; cin >> n >> q;

    RMQ tree(n);

    for (int i = 0; i < q; ++i) {
        int command; cin >> command;
        int x, y; cin >> x >> y;
        if (command == 0) {
            tree.update(x, y);
        } else {
            cout << tree.find(x, y) << endl;
        }
    }
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
