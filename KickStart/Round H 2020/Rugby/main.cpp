#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::sort;
using std::map;
using std::make_pair;
using std::pair;

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

class Point {
public:

    long x = 0L;
    long y = 0L;
    bool moved = false;

    Point(long _x, long _y): x(_x), y(_y) {};
    Point() {};
};

const long INF = 1L<<60;

class Grid {
public:

    long n;
    vector<Point> ps;
    Grid(long _n): n(_n) {
        ps.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> ps[i].x >> ps[i].y;
        }
    };

    pair<long, long> man(long x, long y) {
        map<long, long> m;
        for (long i = 0; i < n; ++i) {
            if (ps[i].moved==true) continue;
            long tmp = abs(ps[i].x - x)+abs(ps[i].y - y);
            m.insert(make_pair(i, tmp));
        }
        auto it = min_element(m.begin(), m.end(), [](const pair<long, long>& l, const pair<long, long>& r) { return l.second > r.second; });
        return *(it);
    }

};


void solve(int x) {
    long n; cin >> n;
    Grid g(n);

    // for (int i = 0; i < n; ++i) {
    //     cout << g.ps[i].x << " " << g.ps[i].y << endl;
    // }

    if (n>10) terminate();

    // 中央値を求めよ
    sort(g.ps.begin(), g.ps.end(), [](const Point& l, const Point& r) { return l.x < r.x; });
    long xm = 0;
    if (n%2==0) xm=(g.ps[n/2-1].x+g.ps[n/2].x)/2;
    else xm=g.ps[n/2].x;
    // cout<<xm<<endl;

    sort(g.ps.begin(), g.ps.end(), [](const Point& l, const Point& r) { return l.y < r.y; });
    long ym = 0;
    if (n%2==0) ym=(g.ps[n/2-1].y+g.ps[n/2].y)/2;
    else ym=g.ps[n/2].y;
    // cout<<ym<<endl;

    long l=1,r=1;
    long y = 0;
    for (long i = 0; i < n; ++i) {
        if (i==0) {
            pair<long, long> p = g.man(xm,ym);
            g.ps[p.first].moved=true;
            y+=p.second;
        } else {
            pair<long, long> p1 = g.man(xm-l,ym);
            pair<long, long> p2 = g.man(xm+r,ym);
            if (p1.second<p2.second) {
                g.ps[p1.first].moved=true;
                y+=p1.second;
                l++;
            } else {
                g.ps[p2.first].moved=true;
                y+=p2.second;
                r++;
            }
        }
    }

    cout << "Case #" << x << ": " << y << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#else
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#endif

    return 0;
}
