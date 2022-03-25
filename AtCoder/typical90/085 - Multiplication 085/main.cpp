// g++ -std=c++17 -D DEV=1 main.cpp
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
using std::sort;
using std::unique;

// キーワード: 約数の個数は少ない
// キーワード: 工夫した全探索/約数列挙の復習

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

// 約数列挙
void divisor(long n, vector<long> &v) {
    for (long i = 1; i * i <= n; ++i) {
        if (n % i != 0) {
            // 約数でない
            continue;
        }

        v.push_back(i);

        if (i != (n/i)) {
            // 商も約数である
            v.push_back(n/i);
        }
    }
}

class Program {
private:

    long K;

public:

    Program() {
        cin >> K;
    }

    void solve() {
        vector<long> v; divisor(K, v);

        sort(v.begin(), v.end());

        // for (auto x : v) {
        //     cout << x << " ";
        // }
        // cout << endl;

        long ans = 0;
        rep(i, 0, v.size()) rep(j, i, v.size()) {
            // ab > K
            if (v[j] > (K / v[i])) continue;

            // cが約数でない
            if (K % (v[i] * v[j]) != 0) continue;

            // b <= c
            if (v[j] <= K / (v[i] * v[j])) {
                ans++;
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
