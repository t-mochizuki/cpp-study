#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;

int N;
int w[MAX];
int v[MAX];
int W;

int dp[MAX + 1][MAX + 1];

void solve() {
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j <= W; ++j) {
            if (j < w[i]) {
                dp[i][j] = dp[i + 1][j];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &w[i], &v[i]);
    }

    scanf("%d", &W);

    solve();

    printf("%d\n", dp[0][W]);

    return 0;
}

/*
Input:
4
2 3
1 2
3 4
2 2
5

Output:
7
*/
