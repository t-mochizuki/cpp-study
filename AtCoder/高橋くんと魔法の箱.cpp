#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int op(int n) {
    return n % 2 == 0 ? op(n / 2) : n;
}

int main() {
    int N;
    cin >> N;

    vector<int> v;
    int ai;
    REP(0, i, N) {
        cin >> ai;
        v.push_back(ai);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        *it = op(*it);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v.size() << endl;

    return 0;
}
