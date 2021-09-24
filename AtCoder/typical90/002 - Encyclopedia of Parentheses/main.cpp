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

// キーワード: 小さい制約は全探索を考えよう

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N;
    vector<char> paren/*thesis*/ = {')', '('};

public:
    Problem() {
        cin >> N;
    }

    bool right(int pat) {
        int open /*parenthesis*/ = 0;
        rep(i, 0, N) {
            if (bit(pat, i) == 0) {
                open++;
            } else {
                open--;
            }

            if (open < 0) return false;
        }

        if (open == 0) return true;
        else return false;
    }

    void print(int pat) {

        for (int i = N-1; i >= 0; --i) {
            cout << paren[bit(pat, i)];
        }
        cout << endl;
    }

    void solve() {
        for (int /*bit*/ pat/*tern*/ = (1<<N)-1; pat >= 0; --pat) {
            if (right(pat)) {
                print(pat);
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
