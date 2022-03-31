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

// TODO: WIP

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

const long INF = 1000000000L;

class Program {
private:

    int n, k;
    long p;
    vector<long> a;
    // 選んだ品物の数
    // 値段の合計
    // 品物の選び方は何通りか
    vector<map<long, long>> dp;

public:

    Program() {
        cin >> n >> k >> p;
        a.resize(n+1);
        rep(i, 1, n+1) cin >> a[i];

        dp.assign(n+1, map<long, long>());
        dp[0][0] = 1;
    }

    void solve() {
        rep(i, 1, n+1) {
            // 品物iを選ぶ
            for (int j = n-1; j >= 0; --j) {
                for (auto [total, cnt] : dp[j]) {
                    if (total+a[i] <= p) {
                        if (dp[j+1].count(total+a[i]) == 1) {
                            dp[j+1][total+a[i]] += cnt;
                        } else {
                            dp[j+1][total+a[i]] = cnt;
                        }
                    }
                }
            }
        }

        long ans = 0;
        for (auto [total, cnt] : dp[k]) {
            ans += cnt;
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
