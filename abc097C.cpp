#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define REP1(i, n) for (int i = 1; i <= n; ++i)

vector<string> v;

int main() {
    string s;
    cin >> s;

    int K;
    scanf("%d", &K);

    // printf("%lu\n", strlen(s));
    REP1(j, 5) {
        REP(i, s.size()) {
            if (s.size() < i + j) break;
            // REP(k, j) {
            //     printf("%c", s[i + k]);
            // }
            // printf("\n");

            v.push_back(s.substr(i, j));
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    printf("%s\n", v[K - 1].c_str());

    return 0;
}
