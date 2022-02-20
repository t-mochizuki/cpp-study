// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::sort;
using std::max;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::get;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

bool compare1(const tuple<int, int>& lhs, const tuple<int, int>& rhs) {
    return get<0>(lhs) < get<0>(rhs);
}

bool compare2(const tuple<int, int>& lhs, const tuple<int, int>& rhs) {
    return get<1>(lhs) < get<1>(rhs);
}

class Problem {
private:

    int N;
    long K;
    vector<tuple<int, int>> a;

    void debug() {
        for (auto t : a) {
            int v, i;
            tie(v, i) = t;
            cout << v << "," << i << endl;
        }
    }


public:

    Problem() {
        cin >> N >> K;

        a.resize(N);
        int tmp;
        rep(i, 0, N) {
            cin >> tmp;
            a[i] = make_tuple(tmp, i);
        }

        sort(a.begin(), a.end(), compare1);

        rep(i, 0, N) {
            int& v = get<0>(a[i]);
            v = i+1;
        }

        sort(a.begin(), a.end(), compare2);
    }


    void solve() {
        long Q = K / N;
        int R = K % N;

        // debug();

        rep(i, 0, N) {
            int& v = get<0>(a[i]);
            if (v > R) {
                cout << Q << endl;
            } else {
                cout << Q+1 << endl;
            }
        }

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
