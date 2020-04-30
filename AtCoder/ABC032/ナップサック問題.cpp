#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

const int MAX_N = 200;
const int MAX_W = 2e5;
bool done[MAX_N + 1][MAX_W + 1];
long memo[MAX_N + 1][MAX_W + 1];

int N; // 荷物の数, 200
long v[MAX_N]; // 荷物の価値, 1e9
int w[MAX_N]; // 荷物の重さ, 1e9

long search(int i, int W) {
    if (done[i][W]) return memo[i][W];

    if (i == N) {
        return 0;
    } else if (W < w[i]) {
        long res = search(i + 1, W);
        memo[i][W] = res;
        done[i][W] = true;
        return res;
    } else {
        long res1 = search(i + 1, W - w[i]) + v[i];
        long res2 = search(i + 1, W);
        long res = max(res1, res2);
        memo[i][W] = res;
        done[i][W] = true;
        return res;
    }

    return 0;
}

int main() {
    int W; // ナップサックの許容重量, 1e9
    scanf("%d %d", &N, &W);

    if (W > MAX_W) return 0;

    REP(i, N) {
        scanf("%ld %d", &v[i], &w[i]);
    }

    REP(i, N + 1) {
        REP(j, W + 1) {
            done[i][j] = false;
            memo[i][j] = 0;
        }
    }

    long res = search(0, W);

    printf("%ld\n", res);

    return 0;
}
