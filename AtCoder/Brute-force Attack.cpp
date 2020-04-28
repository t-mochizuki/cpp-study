#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

void dfs(int i, int N, char* s) {
    if (i == N) {
        s[i] = '\0';
        cout << s << endl;
        return ;
    }

    REP(0, j, 3) {
        if (j == 0) {
            s[i] = 'a';
            dfs(i + 1, N, s);
        } else if (j == 1) {
            s[i] = 'b';
            dfs(i + 1, N, s);
        } else {
            s[i] = 'c';
            dfs(i + 1, N, s);
        }
    }

}

int main() {
    int N;
    cin >> N;

    char s[N + 1];
    dfs(0, N, s);

    return 0;
}
