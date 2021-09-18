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

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:

public:
    Problem() {
    }

    void solve(int x) {
        int y = 0;
        cout << "Case #" << x << ": " << y << endl;
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
