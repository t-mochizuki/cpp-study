#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N; cin >> N;
    int a[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    int cnt = 1;
    for (int i = 1; i <= N; ++i) {
        if (a[i] != cnt) {
            ans++;
        } else {
            cnt++;
        }
    }

    cout << (ans == N ? -1 : ans) << endl;

    return 0;
}
