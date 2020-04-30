#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    vector<int> v;
    int ai;
    REP(0, i, N) {
        cin >> ai;
        v.push_back(ai);
    }

    vector<int> w = v;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    map<int, int> m;
    REP(0, i, v.size()) {
        m.insert(make_pair(v[i], i));
    }

    REP(0, i, w.size()) {
        cout << m[w[i]] << endl;
    }

    return 0;
}
