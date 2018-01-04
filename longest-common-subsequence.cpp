#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int n, m;
char s[MAX_N + 1], t[MAX_M + 1];

int dp[MAX_N + 1][MAX_M + 1];

void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

}

int main() {

    scanf("%d %d", &n, &m);

    scanf("%s", s);
    scanf("%s", t);

    solve();

    printf("%d\n", dp[n][m]);

    return 0;
}

/*
Input:
4 4
abcd
becd

Output:
3
*/
