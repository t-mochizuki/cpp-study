#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)
#define RREP(a, i, n) for (int i = n - 1; i >= a; --i)

int main() {

    int N;
    scanf("%d", &N);

    string s;
    cin >> s;

    int W[N];
    REP(0, i, N) {
        W[i] = s[i] == 'W' ? 1 : 0;
        W[i] += i == 0 ? 0 : W[i - 1];
        // cout << "W[" << i << "]: " << W[i] << endl;
    }
    int E[N];
    RREP(0, i, N) {
        E[i] = s[i] == 'E' ? 1 : 0;
        E[i] += i == N - 1 ? 0 : E[i + 1];
        // cout << "E[" << i << "]: " << E[i] << endl;
    }

    int ans = N;
    REP(0, i, N) {
        // リーダーの西側に並んでいるひとは東を向く。
        // => 0 から i - 1 までで西を向いている人を数える。
        int l = i == 0 ? 0 : W[i - 1];

        // リーダーの東側に並んでいるひとは西を向く。
        // => i + 1 から N までで東を向いている人を数える。
        int r = i == N - 1 ? 0 : E[i + 1];

        if (l + r < ans) ans = l + r;
    }

    printf("%d\n", ans);

    return 0;
}

