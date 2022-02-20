#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <set>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::map;
using std::make_pair;
using std::sort;
using std::to_string;
using std::lower_bound;
using std::distance;
using std::deque;
using std::set;

template<int N>
struct Seq {
  int ary[N];
  constexpr Seq() : ary() {
    for (int i = 0; i < N; i++) ary[i] = i;
  }
};

void solve() {
    constexpr auto seq = Seq<262144>();
    static_assert(seq.ary[262134] == 262134, "");

    int d, t, s; cin >> d >> t >> s;

    if (d > t * s) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
