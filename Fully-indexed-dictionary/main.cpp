#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::lower_bound;
using std::upper_bound;
using std::distance;

class FullyIndexedDictionary {
public:

    vector<bool> _B;
    int widthOfChunk = 8;
    vector<int> _chunk; // 幅は256
    int widthOfBlock = 4;
    vector<int> _block; // 幅は8
    FullyIndexedDictionary(vector<bool> B): _B(B) {
        int cnt = 0;
        for (int i = 0; i < B.size(); ++i) {
            if (i % widthOfChunk == 0) {
                _chunk.push_back(cnt);
            }
            if (i % widthOfBlock == 0) {
                _block.push_back(cnt - _chunk.back());
            }
            if (_B[i]) {
                cnt++;
            }
        }
    }

    bool access(int i) {
        return _B[i];
    }

    int rank1(int i) {
        int ichunk = i / widthOfChunk;
        int iblock = i / widthOfBlock;
        int cnt = 0;
        for (int j = (iblock * widthOfBlock); j < i; ++j) {
            if (_B[j]) {
                cnt++;
            }
        }
        return _chunk[ichunk] + _block[iblock] + cnt;
    }

    int rank0(int i) {
        return i - rank1(i);
    }

    int select1(int i) {
        return 0; // TODO
    }

    int select0(int i) {
        return 0; // TODO
    }

};


void solve() {
    int m; cin >> m;
    int P[m]; // 正整数列P[0, m)
    int n = 0; // ビット列の長さ (2^16以下とする)
    int acc[m];
    for (int i = 0; i < m; ++i) {
        cin >> P[i];
        n += P[i];
        acc[i] = n;
    }

    // 正整数列の各要素をアルファ符号で表したものを順につなげたビット列を求めよ
    vector<bool> B(n);
    for (int i = 0; i < n; ++i) {
        B[i]=false;
    }
    for (int i = 0; i < m; ++i) {
        B[acc[i]-1]=true;
    }

    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            cout << B[i] << endl;
        } else {
            cout << B[i];
        }
    }

    FullyIndexedDictionary f = FullyIndexedDictionary(B);

    for (int i = 0; i <= n; ++i) {
        printf("rank1(B, %d)=%d\n", i, f.rank1(i));
    }

    for (int i = 0; i <= n; ++i) {
        printf("rank0(B, %d)=%d\n", i, f.rank0(i));
    }
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
