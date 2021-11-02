// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::set;
using std::string;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N;
    set<string> S;

public:

    Problem() {
        cin >> N;
        assert(1 <= N);
        assert(N <= 100000);
    }

    void solve() {
        rep(i, 1, N+1) {
            string userName; cin >> userName;
            if (S.find(userName) == S.end()) {
                cout << i << endl;
            }
            S.insert(userName);
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
