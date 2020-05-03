#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
#include <map>
// #include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::set;
using std::map;
using std::make_pair;

int main() {
    // std::ifstream in("Overrandomized.input");
    // cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        int U; cin >> U;

        set<char> s;
        map<char, int> m;
        for (int i = 0; i < 10000; ++i) {
            string M; cin >> M;
            string R; cin >> R;

            decltype(m)::iterator it = m.find(R.front());
            if (it != m.end()) {
                it->second++;
            } else {
                m.insert(make_pair(R.front(), 1));
            }

            if (s.size() != 10) {
                for (int j = 0; j < R.size(); ++j) {
                    s.insert(R[j]);
                }
            }
        }

        char tmp[10000] = {'\0'};
        for (decltype(m)::iterator it = m.begin(); it != m.end(); ++it) {
            tmp[it->second] = it->first;
        }

        char D[11] = {'\0'};
        for (decltype(s)::iterator it = s.begin(); it != s.end(); ++it) {
            bool notFound = true;
            for (decltype(m)::iterator it2 = m.begin(); it2 != m.end(); ++it2) {
                if (it2->first == (*it)) {
                    notFound = false;
                }
            }
            if (notFound) {
                D[0] = (*it);
                break;
            }
        }

        int index = 9;
        for (int i = 0; i < 10000; ++i) {
            if (tmp[i] != '\0') {
                D[index] = tmp[i];
                index--;
            }
            if (index <= 0) {
                break;
            }
        }

        printf("Case #%d: %s\n", x, D);
    }

    return 0;
}
