// g++ -std=c++14 -DDEV=1 -Wall main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Problem {
private:

    const int MAX = 30;
    int A, B;
    long K;
    vector<vector<long> > dp;

public:
    Problem() {
        cin >> A >> B >> K;

        // Pascal's triangle
        dp.resize(MAX+1, vector<long>(MAX+1));
        dp[0][0] = 1;
        for (int i = 0; i <= A; ++i) {
            for (int j = 0; j <= B; ++j) {
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        // cout << dp[0][0] << endl;
        // cout << dp[1][0] << " " << dp[1][0] << endl;
        // cout << dp[2][0] << " " << dp[1][1] << " " << dp[0][2] << endl;
        // cout << dp[3][0] << " " << dp[2][1] << " " << dp[1][2] << " " << dp[0][3] << endl;
        // cout << dp[4][0] << " " << dp[3][1] << " " << dp[2][2] << " " << dp[1][3] << " " << dp[0][4] << endl;
        // cout << dp[5][0] << " " << dp[4][1] << " " << dp[3][2] << " " << dp[2][3] << " " << dp[1][4] << " " << dp[0][5] << endl;
    }

    string find_kth(int i, int j, long K) {
        if (i == 0) {
            return string(j, 'b');
        }
        if (j == 0) {
            return string(i, 'a');
        }
        if (dp[i - 1][j] >= K) {
            return string("a") + find_kth(i - 1, j, K);
        } else {
            return string("b") + find_kth(i, j - 1, K - dp[i - 1][j]);
        }
    }

    void solve() {
        cout << find_kth(A, B, K) << endl;
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
