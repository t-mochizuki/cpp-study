// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::map;
using std::make_pair;
using std::sort;
using std::upper_bound;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    int n;
    vector<long> a, b, c, m;

public:

    Program() {
        cin >> n;
        assert(n >= 1);
        assert(n <= 100000);

        a.resize(n);
        b.resize(n);
        c.resize(n);

        rep(i, 0, n) {
            cin >> a[i];
            assert(a[i] >= 1);
            assert(a[i] <= 1000000000);
        }
        sort(a.begin(), a.end());

        rep(i, 0, n) {
            cin >> b[i];
            assert(b[i] >= 1);
            assert(b[i] <= 1000000000);
        }
        sort(b.begin(), b.end());

        rep(i, 0, n) {
            cin >> c[i];
            assert(c[i] >= 1);
            assert(c[i] <= 1000000000);
        }
        sort(c.begin(), c.end());

        m.assign(n, 0);
    }

    // O(NlogN)
    void solve() {
        rep(i, 0, n) {
            auto middle = b[i];
            auto it = upper_bound(c.begin(), c.end(), middle);
            m[i] = distance(it, c.end());
        }

        for (int i = n-1; i >= 0; --i) {
            if (i != n-1) {
                m[i] += m[i+1];
            }
        }

        long ans = 0;
        rep(i, 0, n) {
            auto top = a[i];
            auto it = upper_bound(b.begin(), b.end(), top);
            int j = distance(b.begin(), it);
            ans += m[j];
        }

        cout << ans << endl;
    }

    // O(N^2logN)
    void search() {
        long ans = 0;
        for (auto top : a) {
            for (auto ib = upper_bound(b.begin(), b.end(), top); ib != b.end(); ++ib) {
                auto middle = *ib;

                assert(middle > top);

                auto ic = upper_bound(c.begin(), c.end(), middle);

                if (ic == c.end()) {
                    break;
                }

                auto bottom = *ic;

                assert(bottom > middle);

                ans += distance(ic, c.end());
            }
        }
        cout << ans << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Program p;
        p.solve();
    }
#else
    Program p;
    p.solve();
#endif

    return 0;
}
