// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

// W:     E:     S:     N:
//   1->3   1->4   1->5   1->2
//  [2->2] [2->2]  2->1   2->6
//   3->6   3->1  [3->3] [3->3]
//   4->1   4->6  [4->4] [4->4]
//  [5->5] [5->5]  5->6   5->1
//   6->4   6->3   6->2   6->5

class Dice {
private:

    vector<int> v;

    void swap(int &i, int &j) {
        int tmp = i;
        i = j;
        j = tmp;
    }

    bool equal(const Dice &other) const {
        bool ret = true;

        rep(i, 1, 7) {
            if (this->v[i] != other.v[i]) {
                ret = false;
                break;
            }
        }

        return ret;
    }

    Dice counterclockwise() const {
        return Dice(v[1], v[4], v[2], v[5], v[3], v[6]);
    }

    bool match(Dice &other) const {
        bool ret = false;

        rep(j, 0, 4) {
            // other.debug();

            if (this->equal(other)) {
                ret = true;
            }

            other = other.counterclockwise();
        }

        return ret;
    }

    Dice rotate(char direction) const {
        if (direction == 'W') {
            return Dice(v[3], v[2], v[6], v[1], v[5], v[4]);
        } else if (direction == 'E') {
            return Dice(v[4], v[2], v[1], v[6], v[5], v[3]);
        } else if (direction == 'S') {
            return Dice(v[5], v[1], v[3], v[4], v[6], v[2]);
        } else {
            assert(direction == 'N');
            return Dice(v[2], v[6], v[3], v[4], v[1], v[5]);
        }
    }

public:

    Dice() {
        v.resize(7);

        rep(i, 1, 7) {
            cin >> v[i];
        }
    }

    Dice(int v1, int v2, int v3, int v4, int v5, int v6) {
        v.resize(7);

        v[1] = v1; v[2] = v2; v[3] = v3; v[4] = v4; v[5] = v5; v[5] = v5; v[6] = v6;
    }

    int get(int i, int j) {
        assert(i != 0);
        assert(j != 0);

        if (i == 1 && j == 2 || i == 5 && j == 1 || i == 6 && j == 5 || i == 2 && j == 6) {
            return v[3];
        }

        if (i == 2 && j == 3 || i == 3 && j == 5 || i == 5 && j == 4 || i == 4 && j == 2) {
            return v[1];
        }

        if (i == 1 && j == 4 || i == 4 && j == 6 || i == 6 && j == 3 || i == 3 && j == 1) {
            return v[2];
        }

        swap(i, j);

        if (i == 1 && j == 2 || i == 5 && j == 1 || i == 6 && j == 5 || i == 2 && j == 6) {
            return v[4];
        }

        if (i == 2 && j == 3 || i == 3 && j == 5 || i == 5 && j == 4 || i == 4 && j == 2) {
            return v[6];
        }

        if (i == 1 && j == 4 || i == 4 && j == 6 || i == 6 && j == 3 || i == 3 && j == 1) {
            return v[5];
        }

        terminate();
    }

    bool operator==(Dice &other) const {
        // top: 1
        if (this->match(other)) {
            return true;
        }

        // top: 2
        other = other.rotate('N');
        if (this->match(other)) {
            return true;
        }

        // top: 6
        other = other.rotate('N');
        if (this->match(other)) {
            return true;
        }

        // top: 5
        other = other.rotate('N');
        if (this->match(other)) {
            return true;
        }
        other = other.rotate('N');

        // top: 4
        other = other.rotate('E');
        if (this->match(other)) {
            return true;
        }
        other = other.rotate('W');

        // top: 3
        other = other.rotate('W');
        if (this->match(other)) {
            return true;
        }
        other = other.rotate('E');

        return false;
    }

    void debug() const {
        printf("%d,%d,%d,%d,%d,%d\n", v[1], v[2], v[3], v[4], v[5], v[6]);
    }
};

class Program {
private:

public:

    Program() {
    }

    void solve() {
        int n;
        cin >> n;
        vector<Dice> ds(n);

        rep(i, 0, n) rep(j, i+1, n) {
            if (ds[i] == ds[j]) {
                cout << "No" << endl;
                return ;
            }
        }

        cout << "Yes" << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Program p;
        p.solve();
    }
#else
    Program p;
    p.solve();
#endif

    return 0;
}
