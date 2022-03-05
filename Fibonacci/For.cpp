// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    int n;
    vector<long> Fib;

public:

    Program() {
        cin >> n;
        cout << "n=" << n << endl;

        Fib.resize(n+1);
    }

    void output() {
        for (int i = 0; i < n; ++i) {
            printf("Fib[%d]=%ld\n", i, Fib[i]);
        }
    }

    // O(N)
    void solve() {
        Fib[0] = 0;
        Fib[1] = 1;

        for (int i = 2; i < n; ++i) {
            Fib[i] = Fib[i-1] + Fib[i-2];
        }

        output();
    }
};

int main() {

#ifdef DEV
    std::ifstream in("Matrix.input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Program p;
        p.solve();
    }
#else
    Program p;
    p.solve();
#endif

    return 0;
}
