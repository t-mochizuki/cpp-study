// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

// キーワード: 真ん中決め打ち+偏角ソート

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::atan2;
using std::acos;
using std::lower_bound;
using std::min;
using std::max;
using std::abs;
using std::sort;
using std::fmod;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)
double pi() { return acos(-1.0); }

class Problem {
private:

    int N;
    vector<int> x, y;

public:
    Problem() {
        cin >> N;

        x.resize(N);
        y.resize(N);
        rep(i, 0, N) cin >> x[i] >> y[i];
    }

    // 偏角を求めよ。
    double argument(int x, int y) {
        return atan2(y, x)*180.0/pi();
    }

    // 角度を求めよ。
    double angle(double t1, double t2) {
        return min(abs(t1-t2), 360.0-abs(t1-t2));
    }

    void debug(const vector<double>& as) {
        rep(i, 0, N-1) {
            if (i != 0) cout << ",";
            cout << i << ":" << as[i];
        }
        cout << endl;
    }

    void solve() {
        double ans = 0.0;

        rep(j, 0, N) {
            vector<double> as;
            rep(i, 0, N) {
                if (i == j) continue;
                as.push_back(argument(x[i]-x[j], y[i]-y[j]));
            }

            // 偏角ソート
            sort(as.begin(), as.end());

            // debug(as);

            // 二分探索
            rep(i, 0, N-1) {
                double t1 = as[i];
                double value = fmod(t1 + 180.0, 360.0);
                auto it = lower_bound(as.begin(), as.end(), value, std::greater_equal<double>());
                if (it != as.end()) ans = max(ans, angle(t1, *it));
                it = lower_bound(as.begin(), as.end(), value, std::less_equal<double>());
                if (it != as.end()) ans = max(ans, angle(t1, *it));
            }
        }

        printf("%.10f\n", ans);
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
