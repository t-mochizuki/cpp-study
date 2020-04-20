#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, D; cin >> N >> D;
    cout << (N + 2 * D) / (2 * D + 1) << endl;
    return 0;
}
