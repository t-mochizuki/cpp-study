// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;

// キーワード: 辞書順最小は前から貪欲法

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

const int ALPHABET = 26;

class Problem {
private:

    int N, K;
    string S;
    // ch[i][j]:
    // 文字列のi番目の右側にある文字の中で
    // 文字jは文字列の何番目かを求めよ。
    // 文字列のi番目の右側にある文字の中に
    // 文字jが複数ある場合は最も左側のものを求めよ。
    // j: a=0, b=1, c=2, ..., z=25
    vector<vector<int>> ch;

public:
    Problem() {
        cin >> N >> K >> S;

        ch.assign(N, vector<int>(ALPHABET, -1));
        rep(i, 0, N) {
            ch[i][S[i]-'a'] = i;
        }

        rep(j, 0, ALPHABET) for (int i = N-2; i >= 0; --i) {
            if (ch[i][j] == -1 && ch[i+1][j] != -1) {
                ch[i][j] = ch[i+1][j];
            }
        }
    }

    void debug() {
        rep(j, 0, ALPHABET) rep(i, 0, N) {
            if (i == 0) {
                cout << (char)(j+'a') << ":";
                cout << std::setw(2) << ch[i][j];
            }
            else cout << "," << std::setw(2) << ch[i][j];

            if (i == N-1) cout << endl;
        }
    }

    void solve() {
        string T;
        int i = 0;
        for (int j = 0; j < ALPHABET;) {
            if (ch[i][j] == -1) {
                ++j;
                continue;
            }

            if (ch[i][j]+K-1 > N-1) {
                // cout << "skip:" << i << "," << (char)(j+'a') << "," << ch[i][j] << endl;

                ++j;
                continue;
            }

            // cout << i << "," << (char)(j+'a') << "," << ch[i][j] << endl;

            T.push_back(S[ch[i][j]]);
            K--;
            i = ch[i][j]+1;
            j = 0;

            if (K == 0) break;
        }

        cout << T << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
