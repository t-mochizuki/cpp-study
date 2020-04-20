#include <stdio.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

const int MAX_H = 50;
const int MAX_W = 50;
char s[MAX_H][MAX_W + 1];

bool test(int H, int W) {
    REP(i, H) {
        REP(j, W) {
            if (s[i][j] == '#') {
                if ((i - 1) >= 0 && s[i - 1][j] == '#') {
                    continue;
                }
                if ((i + 1) < H && s[i + 1][j] == '#') {
                    continue;
                }
                if ((j - 1) >= 0 && s[i][j - 1] == '#') {
                    continue;
                }
                if ((j + 1) < W && s[i][j + 1] == '#') {
                    continue;
                }
                return false;
            }
        }
    }

    return true;
}

int main() {
    int H, W;
    scanf("%d %d", &H, &W);

    REP(i, H) {
        scanf("%s", s[i]);
    }

    if (test(H, W)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
