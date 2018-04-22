#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    vector<int> x(N), y(N);
    vector<int> xary, yary;

    REP(i, N) {
        scanf("%d %d", &x[i], &y[i]);
        xary.push_back(x[i]);
        yary.push_back(y[i]);
    }

    sort(xary.begin(), xary.end());
    sort(yary.begin(), yary.end());

    ll ans = 1LL * (xary[N - 1] - xary[0]) * (yary[N - 1] - yary[0]);
    // printf("%lld\n", ans);

    REP(xi, N) {
        for (int xj = xi + 1; xj < N; ++xj) {
            REP(yi, N) {
                for (int yj = yi + 1; yj < N; ++yj) {
                    ll lx = xary[xi], rx = xary[xj];
                    ll by = yary[yi], uy = yary[yj];

                    int num = 0;
                    REP(i, N) {
                        if ((lx <= x[i]) && (x[i] <= rx) && (by <= y[i]) && (y[i] <= uy)) {
                            num++;
                        }
                    }

                    if (num >= K) {
                        ans = min(ans, 1LL * (rx - lx) * (uy - by));
                    }
                }
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
