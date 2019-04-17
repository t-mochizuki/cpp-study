#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

// P 進数
int main() {
    int P, N;
    cin >> P >> N;

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v;
    while (N != 0) {
        int tmp = N % P;
        int b = tmp != 0 ? (tmp > 0 ? tmp : tmp - P) : 0;
        v.insert(v.begin(), b);
        N = (N - b) / P;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        printf("%d", *it);
    }
    cout << endl;

    return 0;
}
