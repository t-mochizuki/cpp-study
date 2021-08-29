// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::max;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:

    int N;
    vector<long> a;
    vector<vector<long>> dp;
    vector<vector<bool>> visited;

public:
    Problem() {
        cin >> N;

        a.resize(N+1);
        for (int i = 1; i <= N; ++i) cin >> a[i];

        // 数列a'=(a_L,a_L+1,...,a_R-1,a_R)であるときに、X-Yを求める。
        dp.assign(N+1, vector<long>(N+1, 0));

        visited.assign(N+1, vector<bool>(N+1, false));
    }

    long rec(int L, int R) {
        if (visited[L][R]) return dp[L][R];

        visited[L][R] = true;

        if (L == R) dp[L][R] = a[L];
        else dp[L][R] = max(a[L] - rec(L+1, R), a[R] - rec(L, R-1));

        return dp[L][R];
    }

    void solve() {
        cout << rec(1, N) << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
