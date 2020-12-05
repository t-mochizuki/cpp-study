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

class RSQ {
public:

    int _n = 1;
    int _N;
    vector<long> _sum;


    RSQ(int len) {
        while (_n < len) {
            _n *= 2;
        }
        _N = 2 * _n - 1;

        _sum.resize(_N, 0L);
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

    void add(int i, long x) {
        i += _n - 1;
        _sum[i] += x;

        while (i > 0) {
            i = parent(i);
            _sum[i] = _sum[left(i)] + _sum[right(i)];
        }
    }

    long query(int s, int t, int i, int l, int r) {
        auto ret = 0L;

        if (t <= l || r <= s) {
        } else if (s <= l && r <= t) {
            ret = _sum[i];
        } else {
            int vl = query(s, t, left(i), l, (l + r) / 2);
            int vr = query(s, t, right(i), (l + r) / 2, r);
            ret = vl + vr;
        }

        return ret;
    }

    long sum(int s, int t) {
        return query(s, t + 1, 0, 0, _n);
    }
};

void solve() {
    int n, q; cin >> n >> q;

    RSQ tree(n);

    for (int i = 0; i < q; ++i) {
        int command; cin >> command;
        int x, y; cin >> x >> y;
        if (command == 0) {
            tree.add(x, y);
        } else {
            cout << tree.sum(x, y) << endl;
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
