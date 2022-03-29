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

// キーワード: 上界と下界を見積もる

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    long n, k;
    vector<long> a;

public:

    Program() {
        cin >> n >> k;
        long A, B;
        rep(i, 0, n) {
            cin >> A >> B;
            a.push_back(B);
            a.push_back(A-B);
        }
        sort(a.begin(), a.end(), std::greater<long>());
    }

    void solve() {
        long ans = 0;
        rep(i, 0, k) {
            ans += a[i];
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
