// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)

class Rectangle {
private:

    int x1, y1; // the bottom left
    int x2, y2; // the top right

public:

    Rectangle(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}

    int manhattan(int x, int y) {
        int ret = 0;
        if (x1-x > 0) {
            ret += x1-x;
        } else if (x-x2 > 0) {
            ret += x-x2;
        } else {
        }

        if (y1-y > 0) {
            ret += y1-y;
        } else if (y-y2 > 0) {
            ret += y-y2;
        } else {
        }

        return ret;
    }
};


class Point {
private:


public:

    int x, y;

    Point(int x, int y): x(x), y(y) {}

};

class Problem {
private:

    int K;
    vector<Rectangle> rs;

public:

    Problem() {
        cin >> K;

        int x1, y1;
        int x2, y2;
        rep(i, 0, K) {
            cin >> x1 >> y1 >> x2 >> y2;
            rs.push_back(Rectangle(x1, y1, x2, y2));
        }

        if (K > 20) {
            terminate();
        }
    }

    void solve(int x) {

        int minv = 1 << 30;
        Point p = Point(-100, -100);
        rep(i, -100, 101) rep(j, -100, 101) {
            int tmp = 0;
            rep(k, 0, K) {
                tmp += rs[k].manhattan(i, j);
            }
            if (tmp < minv) {
                minv = tmp;
                p = Point(i, j);
            }
        }
        cout << "Case #" << x << ": " << p.x << " " << p.y << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve(x);
    }
#else
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve(x);
    }
#endif

    return 0;
}
