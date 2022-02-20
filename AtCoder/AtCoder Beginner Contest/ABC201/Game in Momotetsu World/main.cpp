// g++ -std=c++14 -DDEV=1 -Wall main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

const int UPPERLIMIT = 2005;
const int INF = 1e9+7;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

class Game {
private:

    vector<vector<bool> > visited;
    vector<vector<int> > memo;
    vector<vector<int> > B;
    int H, W;

public:

    Game() {
        cin >> H >> W;
        vector<string> A(H);
        for (int j = 0; j < H; ++j) {
            cin >> A[j];
        }

        B.resize(UPPERLIMIT, vector<int>(UPPERLIMIT));
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                B[j][k] = A[j][k] == '+' ? 1 : -1;
            }
        }

        visited.resize(UPPERLIMIT, vector<bool>(UPPERLIMIT, false));
        memo.resize(UPPERLIMIT, vector<int>(UPPERLIMIT));
    }


    int f(int i, int j) {
        if (i == H-1 && j == W-1) return 0;

        if (visited[i][j]) return memo[i][j];
        visited[i][j] = true;

        int res = -INF;
        if (j+1 < W) res = max(res, B[i][j+1]-f(i, j+1));
        if (i+1 < H) res = max(res, B[i+1][j]-f(i+1, j));

        return memo[i][j] = res;
    }
};

void solve() {
    Game g;
    int score = g.f(0,0);
    if (score == 0) cout << "Draw" << endl;
    if (score > 0) cout << "Takahashi" << endl;
    if (score < 0) cout << "Aoki" << endl;
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
