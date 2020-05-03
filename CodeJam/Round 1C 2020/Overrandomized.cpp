#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
// #include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::set;

struct Record {
    string M;
    string R;
    bool operator<(const Record& rhs) const {
        return M.size() < rhs.M.size();
    }
};

int main() {
    // std::ifstream in("Overrandomized.input");
    // cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        int U; cin >> U;

        vector<Record> v;
        set<char> s;
        for (int i = 0; i < 10000; ++i) {
            string M; cin >> M;
            string R; cin >> R;
            if (M.size() == R.size()) {
                v.push_back((Record){M, R});
            }
            if (s.size() != 10) {
                for (int j = 0; j < R.size(); ++j) {
                    s.insert(R[j]);
                }
            }
        }

        char D[11];
        for (vector<Record>::iterator it = v.begin(); it != v.end(); ++it) {
            if (it->M.front() == '1') {
                D[1] = it->R.front();
            } else if (it->M.front() == '2') {
                if (it->R.front() != D[1]) {
                    D[2] = it->R.front();
                }
            } else if (it->M.front() == '3') {
                if (it->R.front() != D[1] && it->R.front() != D[2]) {
                    D[3] = it->R.front();
                }
            } else if (it->M.front() == '4') {
                if (it->R.front() != D[1] && it->R.front() != D[2] && it->R.front() != D[3]) {
                    D[4] = it->R.front();
                }
            } else if (it->M.front() == '5') {
                if (it->R.front() != D[1] && it->R.front() != D[2] && it->R.front() != D[3] && it->R.front() != D[4]) {
                    D[5] = it->R.front();
                }
            } else if (it->M.front() == '6') {
                if (it->R.front() != D[1] && it->R.front() != D[2] && it->R.front() != D[3] && it->R.front() != D[4] && it->R.front() != D[5]) {
                    D[6] = it->R.front();
                }
            } else if (it->M.front() == '7') {
                if (it->R.front() != D[1]
                        && it->R.front() != D[2]
                        && it->R.front() != D[3]
                        && it->R.front() != D[4]
                        && it->R.front() != D[5]
                        && it->R.front() != D[6]) {
                    D[7] = it->R.front();
                }
            } else if (it->M.front() == '8') {
                if (it->R.front() != D[1]
                        && it->R.front() != D[2]
                        && it->R.front() != D[3]
                        && it->R.front() != D[4]
                        && it->R.front() != D[5]
                        && it->R.front() != D[6]
                        && it->R.front() != D[7]) {
                    D[8] = it->R.front();
                }
            } else if (it->M.front() == '9') {
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

        for (decltype(s)::iterator it = s.begin(); it != s.end(); ++it) {
            bool notFound = true;
            for (int i = 1; i <= 9; ++i) {
                if (D[i] == (*it)) {
                    notFound = false;
                }
            }
            if (notFound) {
                D[0] = (*it);
                break;
            }
        }

        D[10] = '\0';

        printf("Case #%d: %s\n", x, D);
    }

    return 0;
}

