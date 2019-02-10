#include <stdio.h>
#include <map>
#include <string>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

struct data_t {
    int blue_card_cnt;
    int red_card_cnt;
};

int main() {
    // 青いカード
    int N;
    scanf("%d", &N);

    map<string, data_t> m;
    REP(i, N) {
        char str[11];
        scanf("%s", str);

        map<string, data_t>::iterator it = m.find(str);
        if (it != m.end()) {
            m[str].blue_card_cnt++;
        } else {
            m.insert(make_pair(str, (data_t){1, 0}));
        }
    }

    // 赤いカード
    int M;
    scanf("%d", &M);

    REP(i, M) {
        char str[11];
        scanf("%s", str);

        map<string, data_t>::iterator it = m.find(str);
        if (it != m.end()) {
            m[str].red_card_cnt++;
        } else {
            m.insert(make_pair(str, (data_t){0, 1}));
        }
    }


    int ans = 0;
    for (map<string, data_t>::iterator it = m.begin(); it != m.end(); ++it) {
        ans = max(ans, (it->second).blue_card_cnt - (it->second).red_card_cnt);
        /*
        printf(
            "%s: %d - %d = %d\n",
            (it->first).c_str(),
            (it->second).blue_card_cnt,
            (it->second).red_card_cnt,
            (it->second).blue_card_cnt - (it->second).red_card_cnt
        );
        */
    }

    printf("%d\n", ans);

    return 0;
}
