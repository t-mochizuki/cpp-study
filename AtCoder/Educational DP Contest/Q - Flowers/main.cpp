// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::max;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class RangeMaxQuery {
private:

    int N;
    vector<long> v;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

public:

    // 葉の最も左に配列[0]の値があり、最も右に配列[n-1]がある。
    int n = 1;

    RangeMaxQuery(int len) {
        while (n < len) {
            n *= 2;
        }

        N = 2 * n - 1;

        v.assign(N, 0);
    }

    void update(int i, long x) {
        i = n + i - 1;
        v[i] = x;

        while (i > 0) {
            i = parent(i);
            v[i] = max(v[left(i)], v[right(i)]);
        }
    }

    long query(int i, int j, int k, int l, int r) {
        long ret = 0;

        if (j <= l || r <= i) {
        } else if (i <= l && r <= j) {
            ret = v[k];
        } else {
            long vl = query(i, j, left(k), l, (l + r) / 2);
            long vr = query(i, j, right(k), (l + r) / 2, r);
            ret = max(vl, vr);
        }

        return ret;
    }

    void print() {
        bool first = true;
        for (auto x : v) {
            if (first) {
                cout << x;
                first = false;
            } else {
                cout << " " << x;
            }
        }
        cout << endl;
    }
};

class Problem {
private:

    int N;
    vector<int> h;
    vector<int> a;

public:
    Problem() {
        cin >> N;

        h.resize(N);
        rep(i, N) cin >> h[i];

        a.resize(N);
        rep(i, N) cin >> a[i];
    }

    void solve() {
        RangeMaxQuery dp(N+1);

        rep(i, N) {
            long tmp = dp.query(0, h[i], 0, 0, dp.n);
            dp.update(h[i], tmp + a[i]);
        }

        cout << dp.query(0, dp.n, 0, 0, dp.n) << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
