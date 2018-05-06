#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N; // 200
    int M; // N * (N - 1) / 2
    int R; // min(8, N)
    scanf("%d %d %d", &N, &M, &R);

    vector<int> r;
    REP(i, R) {
        int ri = 0;
        scanf("%d", &ri);
        ri--;
        r.push_back(ri);
    }
    sort(r.begin(), r.end());

    int d[N][N];
    REP(i, N) REP(j, N) {
        d[i][j] = 1e9;
    }

    REP(i, M) {
        int A, B;
        int C; // 町 Ai と町 Bi の間の距離, 1e5
        scanf("%d %d %d", &A, &B, &C);
        A--; B--;
        if (d[A][B] > C) d[A][B] = d[B][A] = C;
    }

    REP(k, N) REP(i, N) REP(j, N) {
        if (d[i][j] > d[i][k] + d[k][j]) {
            d[i][j] = d[i][k] + d[k][j];
        }
    }

    int ans = 1e9;
    do {
        // REP(i, R - 1) {
        //     printf("%d, ", r[i]);
        // }
        // printf("%d\n", r[R - 1]);

        int temp = 0;
        REP(i, R - 1) {
            temp += d[r[i]][r[i + 1]];
        }
        ans = min(ans, temp);
    } while(next_permutation(r.begin(), r.end()));

    printf("%d\n", ans);

    return 0;
}
