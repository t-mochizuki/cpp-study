#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

#define REP(i, a, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    int _3N = 3 * N;
    int a[_3N];
    REP(i, 0, _3N) {
        scanf("%d", &a[i]);
    }

    priority_queue<int, vector<int>, greater<int> > red_q;
    long red_sum = 0;
    REP(i, 0, N) {
        red_q.push(a[i]);
        red_sum += a[i];
    }


    int _2N = 2 * N;
    priority_queue<int> blue_q;
    long blue_sum = 0;
    REP(i, _2N, _3N) {
        blue_q.push(a[i]);
        blue_sum += a[i];
    }

    REP(i, N, _2N) {
        long ai = a[i];
        long red_t = red_q.top();
        long blue_t = blue_q.top();
        if (ai > red_t) {
            red_q.pop();
            red_q.push(ai);
            red_sum += ai - red_t;
        } else if (ai < blue_t) {
            blue_q.pop();
            blue_q.push(ai);
            blue_sum += ai - blue_t;
        }
    }

    printf("%ld\n", red_sum - blue_sum);

    return 0;
}
