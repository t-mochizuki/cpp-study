#include <stdio.h>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    // N = 30 のときに N = 0 と同じになる。
    N = N % 30;

    string s = "123456";

    REP(0, i, N) {
        int j = (i % 5);
        int k = (i % 5) + 1;
        char t = s[j];
        s[j] = s[k];
        s[k] = t;
    }

    printf("%s\n", s.c_str());

    return 0;
}
