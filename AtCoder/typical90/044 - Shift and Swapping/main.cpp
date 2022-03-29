// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <tuple>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;
using std::map;
using std::pair;
using std::deque;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::abs;
using std::sort;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    int n, q;
    deque<int> a;

public:

    Program() {
        cin >> n >> q;
        a.resize(n);
        for (auto& x : a) {
            cin >> x;
        }
    }

    void solve() {
        long T, x, y;
        rep(i, 0, q) {
            cin >> T >> x >> y;

            if (T == 1) {
                x--; y--;
                long tmp = a[x];
                a[x] = a[y];
                a[y] = tmp;
            } else if (T == 2) {
                long tmp = a.back();
                a.pop_back();
                a.push_front(tmp);
            } else {
                assert(T == 3);
                x--;
                cout << a[x] << endl;
            }
        }
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
