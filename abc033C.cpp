#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S;
    cin >> S;

    stringstream ss(S);
    string buf;
    vector<string> v;
    while (getline(ss, buf, '+')) {
        v.push_back(buf);
    }

    int cnt = 0;
    for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
        if ((*it).find("0") == std::string::npos) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
