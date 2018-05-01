#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

const int MAX_N = 1e5;
int par[MAX_N];

void init(int N) {
    REP(0, i, N) par[i] = i; // par[i] = i ならば根
}

int root(int x) {
    if (par[x] == x) {
        return x;
    } else {
        par[x] = root(par[x]);
        return par[x];
    }
}

bool sameRoot(int x, int y) {
    return root(x) == root(y);
}

void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;

    par[x] = y;
}

int main() {
    int N; // 1e5
    int Q; // 1e6
    scanf("%d %d", &N, &Q);

    init(N);

    REP(0, i, Q) {
        int P, A, B;
        scanf("%d %d %d", &P, &A, &B);

        if (P == 0) {
            unite(A, B);
        } else if (P == 1) {
            if (sameRoot(A, B)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
