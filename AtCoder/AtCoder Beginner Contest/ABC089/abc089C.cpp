#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i <= n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    vector<string> v;
    REP(1, i, N) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    long M, A, R, C, H;
    M = A = R = C = H = 0;
    vector<string>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        if ((*it)[0] == 'M') M++;
        else if ((*it)[0] == 'A') A++;
        else if ((*it)[0] == 'R') R++;
        else if ((*it)[0] == 'C') C++;
        else if ((*it)[0] == 'H') H++;
        else {}
    }

    long ans =
        M * A * (R + C + H) +
        A * R * (C + H) +
        M * R * (C + H) +
        (A + M + R) * C * H;

    printf("%ld\n", ans);

    return 0;
}
