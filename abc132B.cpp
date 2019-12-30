#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int n; cin >> n;
    int p[n]; REP(0, i, n) cin >> p[i];
    int cnt = 0;
    REP(0, i, n - 2) {
        if (p[i] > p[i + 1] && p[i + 1] > p[i + 2]) {
            cnt++;
        } else if (p[i] < p[i + 1] && p[i + 1] < p[i + 2]) {
            cnt++;
        } else {
        }
    }
    cout << cnt << endl;
    return 0;
}
