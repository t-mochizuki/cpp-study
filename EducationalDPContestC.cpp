#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

struct data_t {
    int a;
    int b;
    int c;
};

enum enum_t {
    I, A, B, C,
};

data_t d[100005];

int max(int X, int Y) {
    return X > Y ? X : Y;
}

long memo[100005][4];

long dp(int cur, int n, enum_t e) {
    if (cur == n) return 0;

    if (memo[cur][e] != 0) {
        return memo[cur][e];
    }

    if (e == A) {
        long b = dp(cur + 1, n, B) + d[cur].b;
        long c = dp(cur + 1, n, C) + d[cur].c;
        memo[cur][e] = max(b, c);
    } else if (e == B) {
        long a = dp(cur + 1, n, A) + d[cur].a;
        long c = dp(cur + 1, n, C) + d[cur].c;
        memo[cur][e] = max(a, c);
    } else if (e == C) {
        long a = dp(cur + 1, n, A) + d[cur].a;
        long b = dp(cur + 1, n, B) + d[cur].b;
        memo[cur][e] = max(a, b);
    } else {
        long a = dp(cur + 1, n, A) + d[cur].a;
        long b = dp(cur + 1, n, B) + d[cur].b;
        long c = dp(cur + 1, n, C) + d[cur].c;
        memo[cur][e] = max(a, max(b, c));
    }

    return memo[cur][e];
}

int main() {
    int n; cin >> n;
    REP(0, i, n) {
        cin >> d[i].a;
        cin >> d[i].b;
        cin >> d[i].c;
    }

    REP(0, i, n) REP(0, j, 4) memo[i][j] = 0;

    cout << dp(0, n, I) << endl;

    return 0;
}
