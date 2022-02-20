#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N; // バス停の数, 300
    int M; // 路線の数, 44850
    scanf("%d %d", &N, &M);

    int d[N][N];
    REP(i, N) REP(j, N) {
        if (i != j) d[i][j] = 1e9;
        else d[i][j] = 0;
    }
    REP(k, M) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        a--;
        b--;
        d[a][b] = d[b][a] = t;
    }
    REP(k, N) REP(i, N) REP(j, N) {
        if (d[i][j] > d[i][k] + d[k][j]) {
            d[i][j] = d[i][k] + d[k][j];
        }
    }

    // 高橋君が引っ越した後、
    // 最も長くバスに乗らないといけない時にかかってしまう時間
    int ans = 1e9;
    REP(i, N) {
        int temp = 0;
        REP(j, N) {
            if (i != j) temp = max(temp, d[i][j]);
        }
        ans = min(ans, temp);
    }

    printf("%d\n", ans);

    return 0;
}
