#ifndef EDGE
#define EDGE 1

#include <iostream>

namespace nutshell {

const int INF = 1 << 30;

class Edge {
public:

    int _u = -1;
    int _v = -1;
    int _value = INF;

    Edge() {}
    Edge(int u, int v, int value): _u(u), _v(v), _value(value) {}

    friend bool operator<(const Edge& lhs, const Edge& rhs) {
        return lhs._value < rhs._value;
    }
    friend bool operator>(const Edge& lhs, const Edge& rhs) { return rhs < lhs; }
    friend bool operator<=(const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); }
    friend bool operator>=(const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); }
    friend bool operator==(const Edge& lhs, const Edge& rhs) {
        return lhs._value == rhs._value;
    }
    friend bool operator!=(const Edge& lhs, const Edge& rhs) { return !(lhs == rhs); }

    friend std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        return os << e._v;
    }
};

} // namespace nutshell

#endif // EDGE
