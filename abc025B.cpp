#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    string s;
    int d;
    int ans = 0;
    REP(0, i, N) {
        cin >> s >> d;
        if (d < A) {
            ans += s == "East" ? A : (-A);
        } else if (A <= d && d <= B) {
            ans += s == "East" ? d : (-d);
        } else {
            ans += s == "East" ? B : (-B);
        }
    }

    if (ans == 0) {
        cout << 0 << endl;
    } else if (ans > 0) {
        cout << "East" << " " <<  ans << endl;
    } else {
        cout << "West" << " " << -ans << endl;
    }

    return 0;
}
