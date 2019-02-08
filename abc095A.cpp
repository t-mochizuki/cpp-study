#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    char S[4];
    scanf("%s", S);

    int ans = 700;
    REP(0, i, 3) {
        if (S[i] == 'o') {
            ans += 100;
        }
    }

    printf("%d\n", ans);

    return 0;
}
