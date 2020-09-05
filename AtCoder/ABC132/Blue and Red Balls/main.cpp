#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

const int limitation = 2005;
long C[limitation][limitation]; // C[n][k] = n! / (k! * (n - k)!)

long calc(int i, int j) {
    if (C[i][j] != 0) return C[i][j];

    if (i < j) {
        return 0;
    } else if (i == j) {
        C[i][j] = 1;
        return 1;
    } else if (j == 0) {
        C[i][j] = 1;
        return 1;
    } else {
        C[i][j] = (calc(i - 1, j - 1) + calc(i - 1, j)) % 1000000007;
        return C[i][j];
    }
}

// すべてのボールが青であるならば、1回操作のみで1通り、それ以外で0通り
int main() {
    // 1 <= K <= N <= 2000
    int N; // ボール数
    int K; // 青いボール数
    cin >> N >> K;

    REP(0, i, limitation) REP(0, j, limitation) C[i][j] = 0;

    REP(1, i, K + 1) {
        cout << (calc(N - K + 1, i) * calc(K - 1, i - 1)) % 1000000007 << endl;
    }

    return 0;
}
