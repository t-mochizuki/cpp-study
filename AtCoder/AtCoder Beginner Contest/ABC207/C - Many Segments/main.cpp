// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::max;
using std::min;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:

    int N;
    vector<double> l, r;

public:
    Problem() {
        cin >> N;

        l.assign(N, 0.0);
        r.assign(N, 0.0);

        rep(i, N) {
            int t;
            cin >> t >> l[i] >> r[i];

            if (t==1) {
            } else if (t==2) {
                r[i]-=0.5;
            } else if (t==3) {
                l[i]+=0.5;
            } else if (t==4) {
                l[i]+=0.5;
                r[i]-=0.5;
            } else {
            }
        }

    }

    void solve() {
        int y = 0;
        rep(i, N) for (int j = i+1; j < N; ++j) {
            double a = l[i], b = r[i];
            double c = l[j], d = r[j];
            if (max(a,c) <= min(b,d)) y++;
        }
        cout << y << endl;
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
