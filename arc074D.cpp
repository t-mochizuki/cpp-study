#include <stdio.h>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)
#define RREP(n, i, a) for (int i = n - 1; i >= a; --i)

int main() {
    int N;
    scanf("%d", &N);

    int _3N = 3 * N;
    int a[_3N];
    REP(0, i, _3N) {
        scanf("%d", &a[i]);
    }

    // Red
    priority_queue<int, vector<int>, greater<int> > red_q;
    long red_sum = 0;
    REP(0, i, N) {
        red_q.push(a[i]);
        red_sum += a[i];
    }
    long red_sum_v[_3N];
    red_sum_v[N - 1] = red_sum;

    int _2N = 2 * N;
    REP(N, i, _2N) {
        long ai = a[i];
        long red_t = red_q.top();
        if (ai > red_t) {
            red_q.pop();
            red_q.push(ai);
            red_sum += ai - red_t;
        }
        red_sum_v[i] = red_sum;
    }

    // Blue
    priority_queue<int> blue_q;
    long blue_sum = 0;
    REP(_2N, i, _3N) {
        blue_q.push(a[i]);
        blue_sum += a[i];
    }
    long blue_sum_v[_3N];
    blue_sum_v[_2N] = blue_sum;

    RREP(_2N, i, N) {
        long ai = a[i];
        long blue_t = blue_q.top();
        if (ai < blue_t) {
            blue_q.pop();
            blue_q.push(ai);
            blue_sum += ai - blue_t;
        }
        blue_sum_v[i] = blue_sum;
    }

    long ans = LONG_MIN;
    REP(N, i, _2N + 1) {
        // printf("%ld - %ld = %ld\n", red_sum_v[i - 1], blue_sum_v[i], red_sum_v[i - 1] - blue_sum_v[i]);
        ans = max(ans, red_sum_v[i - 1] - blue_sum_v[i]);
    }

    printf("%ld\n", ans);

    return 0;
}
