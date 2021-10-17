// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)

class Problem {
private:

    int N, D, M;
    long C;
    string S;

public:
    Problem() {
        cin >> N >> D >> C >> M >> S;
    }

    void solve(int x) {
        int cnt = 0;
        rep(i, 0, N) {
            if (S[i] == 'D') {
                if (D > 0) {
                    D--;
                    C += M;
                } else {
                    cout << "Case #" << x << ": NO" << endl;
                    return ;
                }
            } else if (S[i] == 'C') {
                if (C > 0) {
                    C--;
                } else {
                    rep(j, i, N) {
                        if (S[j] == 'D') {
                            cout << "Case #" << x << ": NO" << endl;
                            return ;
                        }
                    }

                    cout << "Case #" << x << ": YES" << endl;
                    return ;
                }
            } else {
                terminate();
            }
        }

        cout << "Case #" << x << ": YES" << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve(x);
    }
#else
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve(x);
    }
#endif

    return 0;
}
