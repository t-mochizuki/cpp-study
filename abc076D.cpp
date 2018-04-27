#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define REP1(i, n) for (int i = 1; i <= n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    int t[N];
    REP(i, N) {
        scanf("%d", &t[i]);
    }

    int v[N];
    REP(i, N) {
        scanf("%d", &v[i]);
    }

    double ans = 0;
    int current_velocity = 0;
    REP(i, N) {
        REP1(current_time, t[i]) {
            if (current_velocity < v[i]) {
                current_velocity += 1;
            } else if (current_velocity == v[i]) {
                //
            } else {
                current_velocity -= 1;
            }
            printf("t = %d, v = %d\n", current_time, current_velocity);
        }
    }

    return 0;
}
