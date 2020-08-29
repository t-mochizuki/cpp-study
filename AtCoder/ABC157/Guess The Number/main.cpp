#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::map;
using std::make_pair;

void solve() {
    int n, m; cin >> n >> m;

    map<int, char> dic;
    for (int a = 1; a <= m; ++a) {
        int s; cin >> s; s--;
        char c; cin >> c;

        map<int, char>::iterator it = dic.find(s);
        if (it != dic.end()) {
            if (it->second != c) {
                cout << -1 << endl;
                return ;
            }
        } else {
            dic.insert(make_pair(s, c));
        }
    }

    // for (decltype(dic)::iterator it = dic.begin(); it != dic.end(); ++it) {
    //     cout << it->first << " " << it->second << endl;
    // }

    if (dic.find(0) == dic.end()) {
        if (n == 1) {
            dic.insert(make_pair(0, '0'));
        } else {
            dic.insert(make_pair(0, '1'));
        }
    } else {
        if (n != 1 && dic.find(0)->second == '0') {
            cout << -1 << endl;
            return ;
        }
    }

    string str;
    str.append(n, '0');
    for (decltype(dic)::iterator it = dic.begin(); it != dic.end(); ++it) {
        str[it->first] = it->second;
    }
    cout << str << endl;

}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
