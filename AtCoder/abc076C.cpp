#include <stdio.h>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define RREP(n, i) for (int i = n - 1; i > -1; --i)

int main() {
    char S[51];
    char T[51];
    scanf("%s", S);
    scanf("%s", T);

    int s_len = (int)strlen(S);
    int t_len = (int)strlen(T);

    if (t_len > s_len) {
        printf("UNRESTORABLE\n");
        return 0;
    }

    bool done = false;
    int index = 0;
    RREP(s_len - t_len + 1, i) {
        done = true;
        REP(j, t_len) {
            if (! (S[i + j] == T[j] || S[i + j] == '?')) {
                done = false;
                break;
            }
        }

        if (done) {
            index = i;
            break;
        }
    }

    if (done) {
        REP(i, s_len) {
            if (i == index) {
                // printf("i = %d\n", i);
                REP(j, t_len) {
                    S[index + j] = T[j];
                }
                i += t_len - 1;
            } else {
                // printf("i = %d\n", i);
                S[i] = (S[i] == '?') ? 'a' : S[i];
            }
        }
        printf("%s\n", S);
    } else {
        printf("UNRESTORABLE\n");
    }

    return 0;
}
