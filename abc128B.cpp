#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

struct data_t {
    int number;
    string store_name;
    int point;

    bool operator<(const data_t& other) const {
        if (store_name != other.store_name)
            return store_name < other.store_name;
        if (point != other.point)
            return point > other.point;
        return true;
    }
};

bool compare_name(const data_t &lhs, const data_t &rhs) {
    return lhs.store_name < rhs.store_name;
}

bool compare_point(const data_t &lhs, const data_t &rhs) {
    return lhs.store_name == rhs.store_name && lhs.point > rhs.point;
}

int main() {
    int N; cin >> N;
    vector<data_t> v;
    REP(0, i, N) {
        string S; cin >> S;
        int P; cin >> P;
        v.push_back((data_t){i + 1, S, P});
    }

    sort(v.begin(), v.end());

    REP(0, i, N) {
        // cout << v[i].number << " " << v[i].store_name << " " << v[i].point << endl;
        cout << v[i].number << endl;
    }
    return 0;
}
