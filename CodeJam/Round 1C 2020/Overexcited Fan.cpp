#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
// #include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

template<class T> inline T manhattan(T X, T Y) {
    return abs(X) + abs(Y);
}

struct Intersection {
    int x, y;
};

void solve(int x) {
    int X, Y; cin >> X >> Y;
    string M; cin >> M;

    vector<Intersection> v;
    v.push_back((Intersection){X, Y});
    for (int i = 0; i < M.size(); ++i) {
        if (M[i] == 'N') {
            Y++;
        } else if (M[i] == 'S') {
            Y--;
        } else if (M[i] == 'E') {
            X++;
        } else if (M[i] == 'W') {
            X--;
        }
        v.push_back((Intersection){X, Y});
    }

    int ans = -1;
    for (int R = 0; R < v.size(); ++R) {
        int distance = manhattan(v.at(R).x, v.at(R).y);
        if (R >= distance) {
            ans = R;
            break;
        }
    }


    if (ans == -1) {
        printf("Case #%d: IMPOSSIBLE\n", x);
    } else {
        printf("Case #%d: %d\n", x, ans);
    }
}

int main() {
    // std::ifstream in("CodeJam/Round 1C 2020/Overexcited Fan.input");
    // cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
    return 0;
}
