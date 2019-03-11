#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, K;
    cin >> N >> K;

    cout << (N % K == 0 ? 0 : 1) << endl;

    return 0;
}
