// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::set;
using std::min;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N, M;
    vector<vector<int>> A;
    vector<vector<bool>> B;

public:

    Problem() {
        cin >> N;
        assert(N >= 1);
        assert(N <= 10);

        A.assign(N, vector<int>(N, 0));
        rep(i, 0, N) rep(j, 0, N) {
            cin >> A[i][j];
            assert(A[i][j] >= 1);
            assert(A[i][j] <= 1000);
        }

        B.assign(N, vector<bool>(N, true));

        cin >> M;
        rep(i, 0, M) {
            int X, Y; cin >> X >> Y;
            assert(X >= 1);
            assert(X < Y);
            assert(Y <= N);
            X--; Y--;
            B[X][Y] = false;
            B[Y][X] = false;
        }
    }

    void debug(set<int> player) {
        bool first = true;
        for (auto x : player) {
            if (first) {
                first = false;
                cout << x;
            } else {
                cout << " " << x;
            }
        }
        cout << endl;
    }

    int rec(int from, int n, set<int> player) {
        player.insert(from);

        if (player.size() >= N) {
            return 0;
        }

        int value = 1000*10+1;

        rep(to, 0, N) {
            if (player.find(to) == player.end()) {
                if (B[from][to]) {
                    value = min(value, A[to][n+1] + rec(to, n+1, player));
                }
            }
        }

        return value;
    }

    void solve() {
        set<int> player;

        int value = 1000*10+1;
        rep(from, 0, N) {
            value = min(value, A[from][0] + rec(from, 0, player));
        }

        if (value == 1000*10+1) {
            cout << -1 << endl;
        } else {
            cout << value << endl;
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
