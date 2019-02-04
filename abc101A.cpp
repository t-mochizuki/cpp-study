#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {

    char S[4];
    scanf("%s", S);

    int n = 0;
    REP(0, i, 4) {
        if (S[i] == '+') n++;
        else n--;
    }

    printf("%d\n", n);

    return 0;
}
