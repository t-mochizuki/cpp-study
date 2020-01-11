#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    // N: スイッチ
    // M: 電球
    int N, M; cin >> N >> M; // 1 <= N, M <= 10

    int pSize = 1;
    REP(0, n, N) {
        pSize *= 2;
    }

    // スイッチのパターン
    // 0: OFF, 1: ON
    int b[pSize][N];
    REP(0, j, pSize) REP(0, n, N) b[j][n] = 0;
    REP(0, j, pSize) REP(0, n, N) b[j][n] = ((j >> n) & 0x1);

    // 電球に関連するスイッチ
    int s[M][N];
    REP(0, m, M) REP(0, n, N) s[m][n] = 0;
    REP(0, m, M) {
        int k; cin >> k;
        REP(0, i, k) {
            int tmp; cin >> tmp; tmp--; // 配列の添字に合わせる
            s[m][tmp] = 1;
        }
    }

    // 電球に関連する点灯条件
    int p[M]; REP(0, m, M) cin >> p[m];

    int cnt = 0;
    REP(0, j, pSize) {
        int lights[M]; REP(0, m, M) lights[m] = 0;
        REP(0, m, M) {
            REP(0, n, N) {
                if (b[j][n] == 1) { // スイッチがON
                    // 電球に関連したスイッチならばカウントアップ
                    lights[m] += s[m][n];
                }
            }
        }
        REP(0, m, M) {
            lights[m] = lights[m] % 2;
        }
        // すべて点灯か？
        bool flag = true;
        REP(0, m, M) {
            if (lights[m] != p[m]) {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
/*
2 2
2 1 2
1 2
0 1
*/
