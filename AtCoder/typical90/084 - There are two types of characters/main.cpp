// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

// キーワード: ランレングス圧縮

class Program {
private:

    long n;
    string s;

public:

    Program() {
        cin >> n >> s;
    }

    void solve() {
        vector<long> v;
        long cnt = 1;
        for(long i = 1; i < n; ++i) {

            if (s[i] == s[i-1]) {
                cnt++;
            } else {
                v.push_back(cnt);
                cnt = 1;
            }
        }
        v.push_back(cnt);

        // for (auto x : v) {
        //     cout << x << " ";
        // }
        // cout << endl;

        long ans = n * (n + 1) / 2;
        for (auto x : v) {
            // 条件を満たさない個数を引く
            ans -= x * (x + 1) / 2;
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
