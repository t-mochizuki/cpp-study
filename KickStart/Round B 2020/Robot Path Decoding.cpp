#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int atoi(char c) {
    return c - 48;
}

string decode(string s) {
    string::size_type opos = s.find_last_of('(');
    if (opos == string::npos) {
        return s;
    } else {
        string::size_type cpos = s.find(')', opos);

        string tmp = "";
        tmp.append(s.substr(0, opos - 1));
        int n = atoi(s[opos - 1]);
        REP(0, i, n) tmp.append(s.substr(opos + 1, cpos - opos - 1));
        tmp.append(s.substr(cpos + 1));

        return decode(tmp);
    }
}

int main() {
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        string s; cin >> s;

        string p = decode(s);

        long r = 1, c = 1;
        for (long i = 0; i < p.size(); ++i) {
            if (p[i] == 'N') {
                if (c == 1) {
                    c = 1000000000;
                } else {
                    c--;
                }
            } else if (p[i] == 'E') {
                if (r == 1000000000) {
                    r = 1;
                } else {
                    r++;
                }
            } else if (p[i] == 'S') {
                if (c == 1000000000) {
                    c = 1;
                } else {
                    c++;
                }
            } else if (p[i] == 'W') {
                if (r == 1) {
                    r = 1000000000;
                } else {
                    r--;
                }
            } else {
                return EXIT_FAILURE;
            }
        }

        cout << "Case #" << x << ": " << r << " " << c << endl;
    }

    return EXIT_SUCCESS;
}
