#include <stdio.h>
#include <iostream>

using namespace std;

// TODO: RETRY

#define REP(a, i, n) for (int i = a; i < n; ++i)

long ans = 0;

void dfs(int i, int N, char* s) {
    if (i - 2 > 0) {
        if ((s[i - 3] == 'A' && s[i - 2] == 'G' && s[i - 1] == 'C')
            || (s[i - 3] == 'A' && s[i - 2] == 'C' && s[i - 1] == 'G')
            || (s[i - 3] == 'G' && s[i - 2] == 'A' && s[i - 1] == 'C')) {
            s[i] = '\0';
            return ;
        }
    }

    if (i - 3 > 0) {
        if ((s[i - 4] == 'A' && s[i - 3] == 'G' && s[i - 1] == 'C')
            || (s[i - 4] == 'A' && s[i - 2] == 'G' && s[i - 1] == 'C')) {
            s[i] = '\0';
            return ;
        }
    }

    if (i == N) {
        s[i] = '\0';
        // cout << s << endl;
        ans++;
        return ;
    }

    REP(0, j, 4) {
        if (j == 0) {
            s[i] = 'A';
            dfs(i + 1, N, s);
        } else if (j == 1) {
            s[i] = 'C';
            dfs(i + 1, N, s);
        } else if (j == 2) {
            s[i] = 'G';
            dfs(i + 1, N, s);
        } else {
            s[i] = 'T';
            dfs(i + 1, N, s);
        }
    }

}

int main() {
    int N; cin >> N;

    if (N > 14) {
        cout << 0 << endl;
        return 0;
    }

    char s[N + 1];
    dfs(0, N, s);

    cout << ans << endl;

    return 0;
}
