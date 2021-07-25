#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int s[N];
    int total = 0;
    REP(0, i, N) {
        cin >> s[i];
        total += s[i];
    }

    sort(s, s + N);

    if (total % 10 == 0) {
        REP(0, i, N) {
            if (s[i] % 10 != 0) {
                total -= s[i];
                break;
            }
        }
    }

    if (total % 10 == 0) {
        total = 0;
    }

    cout << total << endl;

    return 0;
}
