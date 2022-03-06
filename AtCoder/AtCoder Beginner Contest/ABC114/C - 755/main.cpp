// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    int n;
    int d = 0;
    vector<int> v;

    int pow(int base, int exponent) {
        int ret = 1;
        rep(i, 0, exponent) {
            ret *= base;
        }
        return ret;
    }

    void rec(int d, int x) {
        assert(d >= 0);
        assert(x >= 0);

        if (d == 0) {
            v.push_back(x);
        } else {
            rec(d-1, x + 7 * pow(10, d-1));
            rec(d-1, x + 5 * pow(10, d-1));
            rec(d-1, x + 3 * pow(10, d-1));
        }
    }

    bool validate(int x) {
        bool seven = false;
        bool five = false;
        bool three = false;

        while (true) {
            int y = x % 10;
            x /= 10;

            if (y == 7) {
                seven = true;
            } else if (y == 5) {
                five = true;
            } else if (y == 3) {
                three = true;
            }

            if (x > 0) {
            } else {
                break;
            }
        }

        if (seven && five && three) {
            return true;
        } else {
            return false;
        }
    }

    void debug() {
        for (auto x : v) {
            cout << x << endl;
        }
    }

public:

    Program() {
        cin >> n;

        int tmp = n;
        while (true) {
            tmp /= 10;
            d++;
            if (tmp > 0) {
            } else {
                break;
            }
        }

        for (int i = d; i >= 3; --i) {
            rec(i, 0);
        }
    }

    void solve() {
        int ans = 0;
        for (auto x : v) {
            if (x <= n) {
                if (validate(x)) {
                    ans++;
                    // cout << "valid:" << x << endl;
                } else {
                    // cout << "invalid:" << x << endl;
                }
            } else {
                // printf("%d > %d\n", x, n);
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
