#include <stdio.h>
#include <map>
#include <string>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N; // 青いカード, 100
    scanf("%d", &N);

    map<string, int> s;
    REP(i, N) {
        char str[11];
        scanf("%s", str);

        map<string, int>::iterator it = s.find(str);
        if (it != s.end()) {
            s[str]++;
        } else {
            s.insert(make_pair(str, 1));
        }
    }

    int M; // 赤いカード, 100
    scanf("%d", &M);
    map<string, int> t;
    REP(i, M) {
        char str[11];
        scanf("%s", str);

        map<string, int>::iterator it = t.find(str);
        if (it != t.end()) {
            t[str]++;
        } else {
            t.insert(make_pair(str, 1));
        }
    }

    int ans = 0;
    for (map<string, int>::iterator it = s.begin(); it != s.end(); ++it) {
        map<string, int>::iterator it2 = t.find(it->first);
        if (it2 != t.end()) {
            ans = max(ans, it->second - it2->second);
        } else {
            ans = max(ans, it->second);
        }
    }

    printf("%d\n", ans);

    return 0;
}
