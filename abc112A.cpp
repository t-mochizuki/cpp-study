#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N; cin >> N;

    if (N == 1) {
        cout << "Hello World" << endl;
    } else {
        int A, B; cin >> A >> B;

        cout << A + B << endl;
    }

    return 0;
}
