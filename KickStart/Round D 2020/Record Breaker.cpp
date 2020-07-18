#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve(int x) {
    int N; cin >> N;
    int V[N + 2];
    V[0] = -1;
    for (int i = 1; i <= N; ++i) {
        cin >> V[i];
    }
    V[N + 1] = -1;

    int y = 0;
    int tmp = -1;
    for (int i = 1; i <= N; ++i) {
        if (V[i - 1] < V[i] && V[i] > V[i + 1] && V[i] > tmp) {
            tmp = V[i];
            y++;
        }
    }

    cout << "Case #" << x << ": " << y << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("KickStart/Round D 2020/Record Breaker.input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#else
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#endif

    return 0;
}

