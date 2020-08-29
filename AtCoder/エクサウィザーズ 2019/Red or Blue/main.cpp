#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    int cnt = 0;
    REP(0, i, N) {
        if (s[i] == 'R') {
            cnt++;
        }
    }

    if (2 * cnt > N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
