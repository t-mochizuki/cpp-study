// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;
using std::atan2;
using std::abs;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const double epsilon = 1e-6;

template<class T> inline void swap(T &A, T &B) {
    T tmp = A;
    A = B;
    B = tmp;
}

class Problem {
private:

    int N;
    vector<double> a, b, c, d;

public:
    Problem() {
        cin >> N;

        a.resize(N);
        b.resize(N);
        double x, y;
        x = y = 0.0;
        rep(i, N) {
            cin >> a[i] >> b[i];
            x += a[i];
            y += b[i];
            a[i] *= N;
            b[i] *= N;
        }

        // Sの重心を原点に平行移動する。
        rep(i, N) {
            a[i] -= x;
            b[i] -= y;
        }

        c.resize(N);
        d.resize(N);
        x = y = 0.0;
        rep(i, N) {
            cin >> c[i] >> d[i];
            x += c[i];
            y += d[i];
            c[i] *= N;
            d[i] *= N;
        }

        // Tの重心を原点に平行移動する。
        rep(i, N) {
            c[i] -= x;
            d[i] -= y;
        }
    }

    void solve() {
        rep(i, N) {
            if (a[i] != 0 || b[i] != 0) {
                swap(a[i], a[0]);
                swap(b[i], b[0]);
                break;
            }
        }

        string ans = "No";
        rep(i, N) {
            double angle = atan2(d[i], c[i])-atan2(b[0], a[0]);

            bool flag = true;
            rep(j, N) {
                double aa = a[j]*cos(angle)-b[j]*sin(angle);
                double bb = a[j]*sin(angle)+b[j]*cos(angle);
                bool flag2 = false;
                rep(k, N) {
                    if (abs(aa-c[k]) <= epsilon && abs(bb-d[k]) <= epsilon) {
                        flag2 = true;
                        break;
                    }
                }
                flag &= flag2;
            }

            if (flag) {
                ans = "Yes";
                break;
            }
        }

        cout << ans << endl;
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
