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
// キーワード: 半分全列挙をしよう

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    int n, k;
    long p;
    vector<long> a;
    // 選んだ品物の数
    // 値段の合計
    // 品物の選び方は何通りか
    vector<map<long, long>> dp1, dp2;

public:

    Program() {
        cin >> n >> k >> p;
        a.resize(n+1);
        rep(i, 1, n+1) cin >> a[i];
        sort(a.begin(), a.end());

        dp1.assign(n+1, map<long, long>());
        dp1[0][0] = 1;
        dp2.assign(n+1, map<long, long>());
        dp2[0][0] = 1;
    }

    void solve() {
        int x = n / 2;

        rep(i, 1, x+1) {
            // 品物iを選ぶ
            for (int j = k-1; j >= 0; --j) {
                for (auto [total, cnt] : dp1[j]) {
                    if (total+a[i] <= p) {
                        if (dp1[j+1].count(total+a[i]) == 1) {
                            dp1[j+1][total+a[i]] += cnt;
                        } else {
                            dp1[j+1][total+a[i]] = cnt;
                        }
                    } else {
                        break;
                    }
                }
            }
        }

        rep(i, x+1, n+1) {
            // 品物iを選ぶ
            for (int j = k-1; j >= 0; --j) {
                for (auto [total, cnt] : dp2[j]) {
                    if (total+a[i] <= p) {
                        if (dp2[j+1].count(total+a[i]) == 1) {
                            dp2[j+1][total+a[i]] += cnt;
                        } else {
                            dp2[j+1][total+a[i]] = cnt;
                        }
                    } else {
                        break;
                    }
                }
            }
        }

        long ans = 0;
        rep(i, 0, k+1) {
            for (auto [total1, cnt1] : dp1[i]) {
                for (auto [total2, cnt2] : dp2[k-i]) {
                    if (total1 + total2 <= p) {
                        ans += cnt1 * cnt2;
                    } else {
                        break;
                    }
                }
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
