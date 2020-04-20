#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    char S[2];
    bool isFour = false;
    REP(0, i, N) {
        scanf("%s", S);
        if ('Y' == S[0]) {
            isFour = true;
            break;
        }
    }

    printf("%s\n", isFour ? "Four" : "Three");

    return 0;
}
