#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

bool dfs(int i, int v, int N, int K, int T[]) {
    if (i == N) {
        return (v == 0);
    }

    REP(0, j, K) {
        if (dfs(i + 1, v ^ T[K * i + j], N, K, T)) return true;
    }

    return false;
}

int main() {
    int N, K;
    cin >> N >> K;

    int T[N * K];
    REP(0, i, N) {
        REP(0, j, K) {
            cin >> T[K * i + j];
        }
    }

    if (dfs(0, 0, N, K, T)) {
        cout << "Found" << endl;
    } else {
        cout << "Nothing" << endl;
    }

    return 0;
}
