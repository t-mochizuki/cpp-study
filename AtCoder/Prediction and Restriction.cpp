#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    int R, S, P; cin >> R >> S >> P;
    string T; cin >> T;
    string Q = "";

    int ans = 0;
    for (int i = 0; i < T.size(); ++i) {
        if (T[i] == 'r') {
            if (i >= K && Q[i - K] == 'p') {
                if (T[i + K] == 's') {
                    Q.append(1, 's');
                } else {
                    Q.append(1, 'r');
                }
            } else {
                Q.append(1, 'p');
                ans += P;
            }
        } else if (T[i] == 's') {
            if (i >= K && Q[i - K] == 'r') {
                if (T[i + K] == 'p') {
                    Q.append(1, 'p');
                } else {
                    Q.append(1, 's');
                }
            } else {
                Q.append(1, 'r');
                ans += R;
            }
        } else if (T[i] == 'p') {
            if (i >= K && Q[i - K] == 's') {
                if (T[i + K] == 'r') {
                    Q.append(1, 'r');
                } else {
                    Q.append(1, 'p');
                }
            } else {
                Q.append(1, 's');
                ans += S;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
