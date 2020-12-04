#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::sort;

class Point {
public:

    int _x = 0;
    int _y = 0;

    Point() {}
    Point(int x, int y): _x(x), _y(y) {}

    friend bool operator<(const Point& lhs, const Point& rhs) {
        return lhs._x < rhs._x && lhs._y < rhs._y;
    }
    friend bool operator>(const Point& lhs, const Point& rhs) { return rhs < lhs; }
    friend bool operator<=(const Point& lhs, const Point& rhs) { return !(lhs > rhs); }
    friend bool operator>=(const Point& lhs, const Point& rhs) { return !(lhs < rhs); }
    friend bool operator==(const Point& lhs, const Point& rhs) {
        return lhs._x == rhs._x && lhs._y == rhs._y;
    }
    friend bool operator!=(const Point& lhs, const Point& rhs) { return !(lhs == rhs); }
};

int counterclockwise(Point o, Point a, Point b) {
    int val = (a._y - o._y) * (b._x - a._x) - (a._x - o._x) * (b._y - a._y);

    if (val == 0) return 0;
    return val > 0 ? 1 : 2;
}

int distance2(Point o, Point a) {
    return (a._x - o._x) * (a._x - o._x) + (a._y - o._y) * (a._y - o._y);
}

class Comparison {
public:

    Point _p;

    Comparison(Point p): _p(p) {}

    bool operator()(const Point& lhs, const Point& rhs) {
        int val = counterclockwise(_p, lhs, rhs);
        return val == 2 ? true : false;
    }
};

template<class T>
class Stack {
public:
    int _top = -1;
    T* _a = NULL;

    Stack(T* a): _a(a) {};
    Stack(const Stack&) = default;
    Stack& operator=(const Stack&) = delete;

    void push(T x) {
        _a[++_top] = x;
    }

    T pop() {
        return _a[_top--];
    }

    T top() {
        return _a[_top];
    }

    T next_to_top() {
        return _a[_top - 1];
    }

    bool empty() {
        return _top == -1;
    }

    int size() {
        return _top + 1;
    }
};

inline void swap(Point &A, Point &B) {
    Point tmp = A;
    A = B;
    B = tmp;
}

void solve() {
    int n; cin >> n;
    Point v[n];
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        v[i] = Point(x, y);
    }

    int yi = 0;
    int ymin = v[yi]._y;
    for (int i = 1; i < n; ++i) {
        int y = v[i]._y;

        if ((y < ymin) || (ymin == y && v[i]._x < v[yi]._x)) {
            ymin = y;
            yi = i;
        }
    }

    swap(v[0], v[yi]);

    sort(v, v + n, Comparison(v[0]));

    Point a[100005];
    Stack<Point> st(a);
    st.push(v[0]);
    st.push(v[1]);
    st.push(v[2]);

    for (int i = 3; i < n; ++i) {
        Point head = v[i];

        while (st.size() >= 2) {
            Point top2 = st.next_to_top();
            Point top = st.top();

            if (2 != counterclockwise(top2, top, head)) {
                st.pop();
            } else {
                break;
            }
        }

        st.push(head);
    }

    cout << st.size() << endl;
    for (int i = 0; i < st.size(); ++i) {
        cout << st._a[i]._x << " " << st._a[i]._y << endl;
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
