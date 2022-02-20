#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

// TODO: RETRY

struct data_t {
    int city;
    int prefecture;
    int year;
    int nth;
};

bool compare(const data_t &lhs, const data_t &rhs) {
    return lhs.prefecture < rhs.prefecture || lhs.year < rhs.year;
}

bool city_compare(const data_t &lhs, const data_t &rhs) {
    return lhs.city < rhs.city;
}

int main() {
    int N, M;
    cin >> N >> M;

    data_t D[M];
    REP(0, i, M) {
        int P, Y;
        cin >> P >> Y;
        D[i] = (data_t){ i, P, Y, 0 };
    }

    sort(D, D + M, compare);

    // REP(0, i, M) {
    //     cout << D[i].prefecture << " " << D[i].year << endl;
    // }

    int p = 0, nth = 0;
    REP(0, i, M) {
        if (p != D[i].prefecture) {
            p = D[i].prefecture;
            nth = 1;
        } else {
            nth++;
        }
        D[i].nth = nth;
    }

    sort(D, D + M, city_compare);

    REP(0, i, M) {
        printf("%06d%06d\n", D[i].prefecture, D[i].nth);
    }

    return 0;
}
