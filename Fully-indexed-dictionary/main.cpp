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

bool access(vector<bool> B, int i) {
    return B[i];
}

// B[0, n)中のi+1番目の1の位置を返す
int select1(int* acc, int i) {
    if (i == -1) {
        return -1;
    } else {
        return acc[i] + (-1);
    }
}

// B[0, n)中のi+1番目の0の位置を返す
int select0(vector<bool> B, int i) {
    int cnt = 0;
    vector<bool>::iterator it;
    for (it = B.begin(); it != B.end(); ++it) {
        if ((*it) == 0) {
            cnt++;
        }
        if (cnt == i+1) {
            break;
        }
    }
    return distance(B.begin(), it);
}

// B[0, i)中の1の数を返す
int rank1(int* first, int* last, int i) {
    auto it = upper_bound(first, last, i);
    return distance(first, it);
}

// B[0, i)中の0の数を返す
int rank0(int* first, int* last, int i) {
    return i - rank1(first, last, i);
}

void solve() {
    int m; cin >> m;
    int P[m]; // 正整数列P[0, m)
    int n = 0; // ビット列の長さ
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

    // P[0]+P[1]+P[2]
    if (select1(acc, 2) - select1(acc, -1) != 6) {
        terminate();
    }

    // P[4]
    if (select1(acc, 4) - select1(acc, 3) != P[4]) {
        terminate();
    }

    if (rank1(acc, acc+m, 4) != 1) {
        terminate();
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
