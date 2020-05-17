#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <string>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::map;
using std::make_pair;
using std::vector;
using std::pair;
using std::set;
using std::string;

void solve(int x) {
    int R, C; cin >> R >> C;
    char Wall[R][C + 1];
    for (int row = 0; row < R; ++row) {
        cin >> Wall[row];
    }

    set<pair<char, char> > vec;

    for (int col = 0; col < C; ++col) {
        char before = '\0';
        for (int row = R - 1; row >= 0; --row) {
            if (row == R - 1) {
                before = Wall[row][col];
            } else {
                if (before != Wall[row][col]) {
                    vec.insert(make_pair(before, Wall[row][col]));
                }
                before = Wall[row][col];
            }
        }
    }

    for (decltype(vec)::iterator it = vec.begin(); it != vec.end(); ++it) {
        printf("%c<-%c\n", it->first, it->second);
    }
    cout << endl;

    string y = "-1";
    cout << "Case #" << x << ": " << y << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("KickStart/Round C 2020/Stable Wall.input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#else
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#endif

    return 0;
}
