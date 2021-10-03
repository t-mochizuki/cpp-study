// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::sort;
using std::max;

// キーワード: 仕事は締切の早い順に

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Job {
private:

public:
    int D, C, S;

    Job() {
        cin >> D >> C >> S;
    }

    void debug() {
        cout << D << "," << C << "," << S << endl;
    }

    bool operator<(const Job& that) const {
        return D < that.D;
    }
};

class Problem {
private:
    int N;
    vector<Job> xs;

public:
    Problem() {
        cin >> N;

        rep(i, 0, N) xs.push_back(Job());

        if (N > 20) {
            terminate();
        }
    }

    void debug() {
        for (auto x : xs) {
            x.debug();
        }
    }

    void solve() {
        sort(xs.begin(), xs.end());

        long y = 0;
        for (int /*bit*/ pat/*tern*/ = (1<<N)-1; pat >= 0; --pat) {
            int day = 1;
            long score = 0;
            rep(i, 0, N) {
                auto x = xs[i];
                if (bit(pat, i) == 1) {
                    if (day+x.C-1 <= x.D) {
                        day += x.C;
                        score += x.S;
                    }
                }
            }
            y = max(y, score);
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
