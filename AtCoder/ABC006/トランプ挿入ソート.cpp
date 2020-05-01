#include <stdio.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

int main() {
    int n; cin >> n;
    int c[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    int cnt = 0;
    int tmp = 1;
    for (int i = 1; i <= n; ++i) {
        if (tmp > c[i]) {
            cnt++;
        } else {
            tmp = c[i];
        }
    }

    cout << cnt << endl;

    return 0;
}
