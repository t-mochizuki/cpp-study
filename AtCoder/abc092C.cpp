#include <stdio.h>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int max(int X, int Y) {
    return X > Y ? X : Y;
}

int abs(int a, int b) {
    return max(b - a, a - b);
}

struct data_t {
    int i;
    int before_cost;
    int after_cost;
    int new_cost;
    int total;
};

int main() {
    int N;
    scanf("%d", &N);

    int A[N + 2];
    A[0] = 0;
    REP(1, i, N + 1) {
        scanf("%d", &A[i]);
    }
    A[N + 1] = 0;

    int total = 0;
    REP(0, i, N + 1) {
        total += abs(A[i], A[i + 1]);
    }

    vector<data_t> v;
    int before_cost = 0;
    int after_cost = 0;
    int new_cost = 0;
    REP(1, i, N + 1) {
        before_cost = abs(A[i], A[i - 1]);
        after_cost = abs(A[i + 1], A[i]);
        new_cost = abs(A[i + 1], A[i - 1]);
        v.push_back((data_t){i, before_cost, after_cost, new_cost, total - before_cost - after_cost + new_cost});
    }

    REP(0, i, N) {
        // printf("i: %d, before_cost: %d, after_cost: %d, new_cost: %d, total: %d\n", v[i].i, v[i].before_cost, v[i].after_cost, v[i].new_cost, v[i].total);
        printf("%d\n", v[i].total);
    }

    return 0;
}
