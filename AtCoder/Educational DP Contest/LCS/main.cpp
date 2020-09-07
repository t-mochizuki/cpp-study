#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

// trace back approach
void solve() {
    string s, t; cin >> s >> t;

    int dp[s.size() + 1][t.size() + 1];
    for (int i = 0; i < s.size() + 1; ++i) {
        for (int j = 0; j < t.size() + 1; ++j) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
        }
    }

    // for (int i = 0; i < s.size(); ++i) {
    //     for (int j = 0; j < t.size(); ++j) {
    //         if (j != t.size() - 1) cout << dp[i+1][j+1] << " ";
    //         else cout << dp[i+1][j+1] << endl;
    //     }
    // }

    string ans = "";
    int i, j; i = s.size() - 1; j = t.size() - 1;
    while (i >= 0 && j >= 0 && dp[i+1][j+1] != 0) {
        if (dp[i+1][j+1] == dp[i+1][j]) {
            --j;
        } else if (dp[i+1][j+1] == dp[i][j+1]) {
            --i;
        } else if (dp[i+1][j+1] != dp[i+1][j] && dp[i+1][j+1] != dp[i][j+1]) {
            ans.insert(ans.begin(), s[i]);
            --i; --j;
        } else {
            // It's not reachable
        }
    }

    cout << ans << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
