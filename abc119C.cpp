#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int abs(int X) {
    return X > 0 ? X : -X;
}

const int INF = 1000000000;
int N, A, B, C;

int dfs(int* l, int i, int a, int b, int c) {
    if (i == N) {
        if (min(min(a, b), c) > 0) {
            return abs(a - A) + abs(b - B) + abs(c - C) - 30;
        } else {
            return INF;
        }
    }

    int ret0 = dfs(l, i + 1, a, b, c);
    int ret1 = dfs(l, i + 1, a + l[i], b, c) + 10;
    int ret2 = dfs(l, i + 1, a, b + l[i], c) + 10;
    int ret3 = dfs(l, i + 1, a, b, c + l[i]) + 10;

    return min(min(min(ret0, ret1), ret2), ret3);
}

int main() {
    cin >> N >> A >> B >> C;
    int l[N]; REP(0, i, N) cin >> l[i];

    cout << dfs(l, 0, 0, 0, 0) << endl;

    return 0;
}
