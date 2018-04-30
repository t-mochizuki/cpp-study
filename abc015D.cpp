#include <stdio.h>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

const int MAX_N = 50;
int N; // スクリーンショットの数, 50
vector<int> v;
int A[MAX_N]; // 幅
int B[MAX_N]; // 優先度

int search(int i, int k, int w) {
    if (i == N) {
        return 0;
    } else if (w < A[i] || k == 0) {
        return search(i + 1, k, w);
    } else {
        int res1 = search(i + 1, k - 1, w - A[i]) + B[i];
        int res2 = search(i + 1, k, w);
        return max(res1, res2);
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

    int res = search(0, K, W);

    printf("%d\n", res);

    return 0;
}
