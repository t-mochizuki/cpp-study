// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::map;
using std::make_pair;
using std::max;

// キーワード: 単調性を利用した尺取り法

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N, K;
    vector<int> A, B;

    void debug(const map<int, int> &m) {
        bool first = true;
        for (const auto &p : m) {
            if (first) {
                first = false;
                printf("(%d, %d)", p.first, p.second);
            } else {
                printf(" (%d, %d)", p.first, p.second);
            }
        }
        cout << endl;
    }

    void debug(const vector<int> &v) {
        bool first = true;
        for (auto x : v) {
            if (first) {
                first = false;
                cout << x;
            } else {
                cout << " " << x;
            }
        }
        cout << endl;
    }

public:

    Problem() {
        cin >> N >> K;
        assert(N >= 1);
        assert(N <= 100000);
        assert(K >= 1);
        assert(N >= K);

        A.resize(N);
        rep(i, 0, N) {
            cin >> A[i];
            assert(A[i] >= 1);
            assert(A[i] <= 1000000000);
        }

        B.assign(N, 0);
    }

    void solve() {
        map<int, int> m;
        int from = 0;
        int to = 0;
        for (; from < N; ++from) {
            for (; to < N; ++to) {
                if (m.find(A[to]) != m.end()) {
                    m[A[to]] = to;
                } else {

                    if (m.size() >= K) {
                        B[from] = to;

                        if (m[A[from]] == from) {
                            m.erase(m.find(A[from]));
                        }

                        break;
                    } else {
                        m.insert(make_pair(A[to], to));
                    }
                }
            }

            if (to >= N) {
                B[from] = to;
            }
        }

        int ans = 0;
        rep(i, 0, N) {
            ans = max(ans, B[i] - i);
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
