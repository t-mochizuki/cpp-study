#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int A;
    map<int, int> m;
    REP(0, i, N) {
        cin >> A;

        map<int, int>::iterator it = m.find(A);
        if (it != m.end()) {
            m[A]++;
        } else {
            m.insert(make_pair(A, 0));
        }
    }

    int cnt = 0;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        cnt += it->second;
    }

    cout << cnt << endl;

    return 0;
}
