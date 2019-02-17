#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

#define RREP(a, i, n) for (int i = n - 1; i >= 0; --i)

struct data_t {
    int i;
    int j;
    int k;
};

data_t search(int i, int j, int k, int M) {
    // if (-1 == i) {
    //     return (data_t){-1, -1, -1};
    // }

    if ((2 * i + 3 * j + 4 * k) == M) {
        return (data_t){i, j, k};
    } else if ((2 * i + 3 * j + 4 * k) > M){
        return search(i, j + 1, k - 1, M);
    } else {
        return search(i - 1, j, k + 1, M);
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    data_t ans;
    if (2 * N <= M && M <= 4 * N) {
        ans = search(N, 0, 0, M);
    } else {
        printf("-1 -1 -1\n");
        return 0;
    }

    printf("%d %d %d\n", ans.i, ans.j, ans.k);

    return 0;
}
