#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);

    int h[N];
    REP(i, N) {
        scanf("%d", &h[i]);
    }

    if (N == 1) {
        int cnt = h[0] / A;
        cnt++;
        printf("%d\n", cnt);
        return 0;
    }

    bool done = false;
    int cnt = 0;
    while (true) {
        sort(h, h + N, greater<int>());
        REP(i, N) {
            if (i == 0) h[0] -= A;
            else h[i] -= B;
        }

        done = true;
        REP(i, N) {
            if (h[i] > 0) {
                done = false;
                break;
            }
        }

        cnt++;

        if (done) break;
    }

    printf("%d\n", cnt);

    return 0;
}
