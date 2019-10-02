#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

const int MOD = 1e9 + 7;
const string AGC = "AGC";
const string ACGT[4] = {"A", "C", "G", "T"};
map<string, int> table;
int memo[101][64];

bool ok(string last4) {
    REP(0, i, 4) {
        string tmp = last4;
        if (i >= 1) {
            char c = tmp[i - 1];
            tmp[i - 1] = tmp[i];
            tmp[i] = c;
        }

        if (tmp.find(AGC) != string::npos) {
            return false;
        }
    }
    return true;
}

int dfs(int N, int cur, string last3) {
    if (memo[cur][table[last3]] != 0) {
        return memo[cur][table[last3]];
    }

    if (cur == N) {
        return 1;
    }

    int ret = 0;
    REP(0, i, 4) {
        if (ok(last3 + ACGT[i])) {
            ret = (ret + dfs(N, cur + 1, last3.substr(1) + ACGT[i])) % MOD;
        }
    }
    memo[cur][table[last3]] = ret;
    return ret;
}

int main() {
    int N; cin >> N;
    REP(0, i, 101) REP(0, j, 64) memo[i][j] = 0;
    int count = 0;
    REP(0, i, 4) REP(0, j, 4) REP(0, k, 4) {
        table.insert(make_pair(ACGT[i] + ACGT[j] + ACGT[k], count));
        count++;
    }
    cout << dfs(N, 0, string("TTT")) << endl;
    return 0;
}
