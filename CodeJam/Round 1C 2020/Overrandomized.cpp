#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// #include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::sort;

struct Record {
    int M;
    string R;
    bool operator<(const Record& rhs) const {
        return M < rhs.M;
    }
};

int main() {
    // std::ifstream in("input");
    // cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        int U; cin >> U;

        vector<Record> v;
        for (int i = 0; i < 10000; ++i) {
            int M; cin >> M;
            string R; cin >> R;
            v.push_back((Record){M, R});
        }

        sort(v.begin(), v.end());

        char D[11];
        for (vector<Record>::iterator it = v.begin(); it != v.end(); ++it) {
            if (it->M == 1) {
                D[1] = it->R.front();
            } else if (it->M == 10) {
                if (it->R.size() == 2 && it->R.front() == D[1]) {
                    // cout << "DEGUB: R=" << it->R << endl;
                    D[0] = it->R.back();
                }
            } else if (it->M == 2) {
                if (it->R.front() != D[1]) {
                    D[2] = it->R.front();
                }
            } else if (it->M == 3) {
                if (it->R.front() != D[1] && it->R.front() != D[2]) {
                    D[3] = it->R.front();
                }
            } else if (it->M == 4) {
                if (it->R.front() != D[1] && it->R.front() != D[2] && it->R.front() != D[3]) {
                    D[4] = it->R.front();
                }
            } else if (it->M == 5) {
                if (it->R.front() != D[1] && it->R.front() != D[2] && it->R.front() != D[3] && it->R.front() != D[4]) {
                    D[5] = it->R.front();
                }
            } else if (it->M == 6) {
                if (it->R.front() != D[1] && it->R.front() != D[2] && it->R.front() != D[3] && it->R.front() != D[4] && it->R.front() != D[5]) {
                    D[6] = it->R.front();
                }
            } else if (it->M == 7) {
                if (it->R.front() != D[1]
                        && it->R.front() != D[2]
                        && it->R.front() != D[3]
                        && it->R.front() != D[4]
                        && it->R.front() != D[5]
                        && it->R.front() != D[6]) {
                    D[7] = it->R.front();
                }
            } else if (it->M == 8) {
                if (it->R.front() != D[1]
                        && it->R.front() != D[2]
                        && it->R.front() != D[3]
                        && it->R.front() != D[4]
                        && it->R.front() != D[5]
                        && it->R.front() != D[6]
                        && it->R.front() != D[7]) {
                    D[8] = it->R.front();
                }
            } else if (it->M == 9) {
                if (it->R.front() != D[1]
                        && it->R.front() != D[2]
                        && it->R.front() != D[3]
                        && it->R.front() != D[4]
                        && it->R.front() != D[5]
                        && it->R.front() != D[6]
                        && it->R.front() != D[7]
                        && it->R.front() != D[8]) {
                    D[9] = it->R.front();
                }
            } else {
                continue;
            }
        }
        D[10] = '\0';

        printf("Case #%d: %s\n", x, D);
    }

    return 0;
}

