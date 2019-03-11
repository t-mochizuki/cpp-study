#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v;
    while (N != 0) {
        int b = N % (-2) != 0 ? 1 : 0;
        v.insert(v.begin(), b);
        N = (N - b) / (-2);
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        printf("%d", *it);
    }
    cout << endl;

    return 0;
}
