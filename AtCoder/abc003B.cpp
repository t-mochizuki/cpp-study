#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S, T;
    cin >> S >> T;

    char at[7] = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

    REP(0, i, S.size()) {
        if (S[i] == '@' && T[i] == '@') {
            continue;
        }

        if (S[i] == '@') {
            bool b = false;

            REP(0, j, 7) {
                if (T[i] == at[j]) {
                    // equal!
                    b = true;
                    break;
                }
            }

            if (b == false) {
                printf("You will lose\n");
                return 0;
            } else {
                continue;
            }
        }

        if (T[i] == '@') {
            bool b = false;

            REP(0, j, 7) {
                if (S[i] == at[j]) {
                    // equal!
                    b = true;
                    break;
                }
            }

            if (b == false) {
                printf("You will lose\n");
                return 0;
            } else {
                continue;
            }
        }

        if (S[i] == T[i]) {
            // equal !
            continue;
        } else {
            // ! equal
            printf("You will lose\n");
            return 0;
        }
    }

    printf("You can win\n");

    return 0;
}
