#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int takahashi_calc(int* a, int s, int e) {
    int sum = 0;
    for (int i = s; i <= e; i += 2) {
        sum += a[i];
    }
    return sum;
}

int aoki_calc(int* a, int s, int e) {
    int sum = 0;
    for (int i = s + 1; i <= e; i += 2) {
        sum += a[i];
    }
    return sum;
}

int main() {
    int N;
    cin >> N;

    int a[N];
    REP(0, i, N) {
        cin >> a[i];
    }

    int max_takahashi = -51;
    REP(0, i, N) {
        int takahashi = -51;
        int aoki = -51;
        REP(0, j, N) {
            if (i == j) {
                continue;
            }

            int tmp_takahashi = i > j ? takahashi_calc(a, j, i) : takahashi_calc(a, i, j);
            int tmp_aoki = i > j ? aoki_calc(a, j, i) : aoki_calc(a, i, j);
            if (tmp_aoki > aoki) {
                aoki = tmp_aoki;
                takahashi = tmp_takahashi;
            }
        }

        if (takahashi > max_takahashi) {
            max_takahashi = takahashi;
        }
    }

    printf("%d\n", max_takahashi);

    return 0;
}
