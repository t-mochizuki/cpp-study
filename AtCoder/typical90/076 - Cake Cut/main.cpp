// g++ -std=c++17 -D DEV=1 main.cpp
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

#define rep(i, a, n) for (long i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

// 尺取り虫
class Program {
private:

    long n, k = 0;
    vector<long> a;

public:

    Program() {
        cin >> n;
        a.resize(n);
        rep(i, 0, n) {
            cin >> a[i];
            k += a[i];
        }

        vector<long> b = a;
        for (auto v : b) {
            a.push_back(v);
        }
    }

    void solve() {
        if (k % 10 == 0) {
            k /= 10;
        } else {
            cout << "No" << endl;
            return ;
        }

        long c = 0, j = 0;
        rep(i, 0, 2*n) {
            if (c == k) {
                cout << "Yes" <<endl;
                return ;
            } else if (c < k) {
                c += a[i];
            } else {
                assert(c > k);
                c -= a[j];
                j++;
                i--;
            }
        }

        cout << "No" <<endl;
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
