#include <stdio.h>

using namespace std;

#define rep(a, i, n) for (int i = a; i <= n; ++i)

int main() {
    // 偶数回裏返すと表
    // 奇数回裏返すと裏
    // 周りにあるマスの数 + 1回裏返される

    long N, M;
    scanf("%ld %ld", &N, &M);

    // 1, 1 ならば 1
    // 2, 1 ならば 0
    // 2, 2 ならば 0
    // 3, 1 ならば 1
    // N, 1 ならば N - 2
    // 3, 2 ならば 0
    // 3, 3 ならば 1
    // 4, 4 ならば 4
    // 5, 4 ならば 6
    // N, M は 2 以上のとき
    // N, M ならば (N - 2) * (M - 2)

    if (N <= 2 && M <= 2) {
        if (N == 1 && M == 1) {
            printf("1\n");
            return 0;
        }
        if (N == 2 || M == 2) {
            printf("0\n");
            return 0;
        }

        printf("0\n");
        return 0;
    }

    if (N == 1 || M == 1) {
        printf("%ld\n", N == 1 ? M - 2 : N - 2);
        return 0;
    }

    printf("%ld\n", (N - 2) * (M - 2));
    return 0;
}
