#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

const int CAKE = 4;
const int DONUT = 7;

struct data_t {
    int cake;
    int donut;
    int n;
};

int main() {
    int N;
    cin >> N;

    data_t d;
    d.donut = N / DONUT;
    d.n = N % DONUT;
    d.cake = d.n / CAKE;
    d.n = d.n % CAKE;

    if (d.n == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    while (d.n != 0) {
        if (CAKE <= d.n) {
            d.n -= CAKE;
            d.cake++;
        } else {
            if (d.donut == 0) {
                break;
            }

            d.n += DONUT - CAKE;
            d.donut--;
            d.cake++;
        }
    }

    // cout << "d.cake: " << d.cake << endl;
    // cout << "d.donut: " << d.donut << endl;
    // cout << "d.n: " << d.n << endl;

    if (d.n == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
