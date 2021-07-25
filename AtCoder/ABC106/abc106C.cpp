#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

// 5000兆
// 5 * 10^15
int main() {
    string S;
    cin >> S; // 1 <= |S| <= 100

    long K; // 1 <= K <= 10^18
    cin >> K;

    REP(0, i, S.length()) {
        if (S[i] == '1') {
            if ((i + 1) == K) {
                cout << 1 << endl;
                return 0;
            }
        } else {
            cout << S[i] << endl;
            return 0;
        }
    }
}
