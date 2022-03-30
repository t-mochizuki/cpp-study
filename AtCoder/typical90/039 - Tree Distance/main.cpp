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

// キーワード: 答えへの貢献度を考える
// 主客転倒, 木DP

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    int n;
    vector<vector<int>> edge;
    vector<int> dp, a, b;

    // 頂点posを含む部分木の頂点数を求める
    // 葉: dp[pos] == 1
    void dfs(int pos, int pre) {
        dp[pos] = 1;
        for (int i : edge[pos]) {
            if (i != pre) {
                dfs(i, pos);
                dp[pos] += dp[i];
            }
        }
    }

    void dEdge() {
        for (auto& v : edge) {
            for (auto x : v) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void dDp() {
        for (auto x : dp) {
            cout << x << " ";
        }
        cout << endl;
    }

public:

    Program() {
        cin >> n;
        edge.resize(n);
        a.assign(n, 0);
        b.assign(n, 0);
        rep(i, 0, n-1) {
            cin >> a[i] >> b[i];
            a[i]--; b[i]--;
            edge[a[i]].push_back(b[i]);
            edge[b[i]].push_back(a[i]);
        }

        dp.assign(n, 0);
    }

    void solve() {
        // 頂点0を根とする根付き木
        dfs(0, -1);

        long ans = 0;
        // すべての辺の貢献度を足し合わせる
        // なぜグループAの頂点数とグループBの頂点数の積が貢献度か？
        // 木なので連結なグラフである
        // 必ず頂点uから頂点vに移動できる
        rep(i, 0, n-1) {
            long r = dp[a[i]] > dp[b[i]] ? dp[b[i]] : dp[a[i]];
            assert(r != n);
            ans +=  r * (n - r);
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
