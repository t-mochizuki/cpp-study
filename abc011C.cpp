#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    int NG1, NG2, NG3;
    scanf("%d %d %d", &NG1, &NG2, &NG3);

    if (N == NG1 || N == NG2 || N == NG3) {
        printf("NO\n");
        return 0;
    }

    bool ans = false;
    REP(0, i, 101) {
        if (N == 0) {
            ans = true;
            break;
        } else {
            int temp = N - 3;
            if (temp != NG1 && temp != NG2 && temp != NG3 && temp >= 0) {
                N -= 3;
                continue;
            }

            temp = N - 2;
            if (temp != NG1 && temp != NG2 && temp != NG3 && temp >= 0) {
                N -= 2;
                continue;
            }

            temp = N - 1;
            if (temp != NG1 && temp != NG2 && temp != NG3 && temp >= 0) {
                N -= 1;
                continue;
            }

            break; // N, NG1, NG2, NG3, N + 4
        }
    }

    printf(ans ? "YES\n" : "NO\n");

    return 0;
}
