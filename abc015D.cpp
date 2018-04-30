#include <stdio.h>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

const int MAX_N = 50;
const int MAX_W = 1e4;
int N; // スクリーンショットの数, 50
vector<int> v;
int A[MAX_N]; // 幅
int B[MAX_N]; // 優先度
bool done[MAX_N + 1][MAX_N + 1][MAX_W + 1];
int memo[MAX_N + 1][MAX_N + 1][MAX_W + 1];

// i 番目以降のスクリーンショットで、枚数の総和が k 以下、幅の総和が w 以下となるように選ぶ
int search(int i, int k, int w) {
    if (done[i][k][w]) return memo[i][k][w];

    if (i == N) {
        done[i][k][w] = true;
        memo[i][k][w] = 0;
        return 0;
    } else if (w < A[i] || k == 0) {
        int res = search(i + 1, k, w);
        done[i][k][w] = true;
        memo[i][k][w] = res;
        return res;
    } else {
        int res1 = search(i + 1, k - 1, w - A[i]) + B[i];
        int res2 = search(i + 1, k, w);
        int res = max(res1, res2);
        done[i][k][w] = true;
        memo[i][k][w] = res;
        return res;
    }
}

int main() {
    int W; // 表計算ソフトの幅, 10000
    scanf("%d", &W);
    int K; // 表計算ソフトに貼り付け可能なスクリーンショットの枚数, N
    scanf("%d %d", &N, &K);
    REP(i, N) {
        scanf("%d %d", &A[i], &B[i]);
    }

    REP(i, N + 1) {
        REP(j, K + 1) {
            REP(k, W + 1) {
                done[i][j][k] = false;
            }
        }
    }

    int res = search(0, K, W);

    printf("%d\n", res);

    return 0;
}
