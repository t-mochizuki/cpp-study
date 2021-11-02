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

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N;
    map<int, vector<int>> E;
    vector<bool> visited;
    vector<bool> colors;

    void debug() {
        rep(i, 1, N+1) {
            cout << colors[i] << endl;
        }
        cout << endl;
    }

    void ans(int stop, bool color) {
        bool first = true;
        int cnt = 0;
        rep(i, 1, N+1) {
            if (cnt == stop) break;

            if (first) {
                first = false;
                if (color == colors[i]) {
                    cout << i;
                    cnt++;
                }
            } else {
                if (color == colors[i]) {
                    cout << " " << i;
                    cnt++;
                }
            }
        }
        cout << endl;
    }

public:

    Problem() {
        cin >> N;
        assert(N % 2 == 0);
        assert(2 <= N);
        assert(N <= 100000);

        for (int x = 1; x <= N-1; ++x) {
            int a, b; cin >> a >> b;
            assert(1 <= a);
            assert(a <= N);
            assert(1 <= b);
            assert(b <= N);
            assert(a < b);

            if (E.find(a) == E.end()) {
                E.insert(make_pair(a, vector<int>(1, b)));
            } else {
                E[a].push_back(b);
            }
            if (E.find(b) == E.end()) {
                E.insert(make_pair(b, vector<int>(1, a)));
            } else {
                E[b].push_back(a);
            }
        }

        visited.assign(N+1, false);
        colors.assign(N+1, false);
    }

    void visit(int from, bool color) {
        if (visited[from]) return ;

        visited[from] = true;

        for (auto to : E[from]) {
            visit(to, !color);
        }

        colors[from] = color;
    }

    void solve() {
        int from = 1;

        visit(from, true);

        int cnt = 0;
        rep(i, 1, N+1) if (colors[i]) cnt++;

        if (cnt < N/2) {
            ans(N/2, false);
        } else {
            ans(N/2, true);
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
