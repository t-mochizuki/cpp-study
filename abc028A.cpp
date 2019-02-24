#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    if (N == 100) {
        cout << "Perfect" << endl;
        return 0;
    }

    if (90 <= N && N <= 99) {
        cout << "Great" << endl;
        return 0;
    }

    if (60 <= N && N <= 89) {
        cout << "Good" << endl;
        return 0;
    } else {
        cout << "Bad" << endl;
        return 0;
    }

    return 0;
}
