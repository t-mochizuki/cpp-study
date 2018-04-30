#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

const int MAX_N = 200;

int N; // 荷物の数, 200
long v[MAX_N]; // 荷物の価値, 1e9
int w[MAX_N]; // 荷物の重さ, 1e9

long search(int i, int W) {

    if (i == N) {
        return 0;
    } else if (W < w[i]) {
        return search(i + 1, W);
    } else {
        long res1 = search(i + 1, W - w[i]) + v[i];
        long res2 = search(i + 1, W);
        long res = max(res1, res2);
        return res;
    }

    return 0;
}

int main() {
    int W; // ナップサックの許容重量, 1e9
    scanf("%d %d", &N, &W);

    REP(i, N) {
        scanf("%ld %d", &v[i], &w[i]);
    }

    long res = search(0, W);

    printf("%ld\n", res);

    return 0;
}
