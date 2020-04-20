#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

bool compare(const pair<string, int> &first, const pair<string, int> &last) {
    return first.second < last.second;
}

int main() {
    int N;
    scanf("%d", &N);

    map<string, int> m;
    REP(0, i, N) {
        string S;
        cin >> S;

        map<string, int>::iterator it = m.find(S);
        if (it != m.end()) {
            m[S]++;
        } else {
            m.insert(make_pair(S, 1));
        }
    }

    printf("%s\n", (max_element(m.begin(), m.end(), compare)->first.c_str()));

    return 0;
}
