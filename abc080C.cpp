#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

#define rep(a, i, n) for (int i = a; i < n; ++i)

int deepFirstSearch(int i, int p[10]) {
    if (i == 10) {
        // rep(0, j, 10) printf("%d ", p[j]);
        // printf("\n");
        return 0;
    }

    p[i] = 0;
    deepFirstSearch(i + 1, p);
    p[i] = 1;
    deepFirstSearch(i + 1, p);

    return 0;
}

int main() {
    int N; // 100
    scanf("%d", &N);

    bool F[N][10];
    rep(0, i, N) rep(0, j, 10) {
        int temp;
        scanf("%d", &temp);
        F[i][j] = (temp == 1) ? true : false;
    }

    int p[N][11];
    rep(0, i, N) rep(0, j, 11) {
        scanf("%d", &p[i][j]);
    }

    // {
    //     rep(0, i, N) {
    //         rep(0, j, 10) {
    //             printf("%d ", F[i][j]);
    //         }
    //         printf("\n");
    //     }
    //     rep(0, i, N) {
    //         rep(0, j, 11) {
    //             printf("%d ", p[i][j]);
    //         }
    //         printf("\n");
    //     }
    // }

    int pat[10] = {0};
    deepFirstSearch(0, pat);

    return 0;
}
