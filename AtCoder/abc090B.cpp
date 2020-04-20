#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

bool isPalindromic(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int ans = 0;
    REP(A, i, B + 1) {
        char c[6];
        sprintf(c, "%d", i);
        if (isPalindromic(string(c))) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
