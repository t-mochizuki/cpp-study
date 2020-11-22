#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
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
using std::set;

int a2i(char a);

class Node {
public:

    int _n;
    string _value;
    Node* _left = NULL;
    Node* _right = NULL;

    Node(int n, string value): _n(n), _value(value) {}

    void insert() {
        if (_n > 0) {
            int bitNum = _n - 1;
            string lvalue, rvalue;
            for (auto c : _value) {
                int tmp = a2i(c);
                if ((tmp >> bitNum & 1) == 0) {
                    lvalue.push_back(c);
                } else {
                    rvalue.push_back(c);
                }
            }
            if (!(lvalue.empty())) {
                _left = new Node(bitNum, lvalue);
                _left->insert();
            }
            if (!(rvalue.empty())) {
                _right = new Node(bitNum, rvalue);
                _right->insert();
            }
        }
    }

    ~Node() {
        if (_left != NULL) {
            printf("Delete a node(%s) on the left\n", _left->_value.c_str());
            delete _left;
            _left = NULL;
        }
        if (_right != NULL) {
            printf("Delete a node(%s) on the right\n", _right->_value.c_str());
            delete _right;
            _right = NULL;
        }
    }

    void print() {
        if (_left != NULL) {
            _left->print();
        }

        cout << _value << endl;

        if (_right != NULL) {
            _right->print();
        }
    }
};

class BinaryTree {
public:

    Node _root;
    BinaryTree(Node& node): _root(node) {}

    void insert() {
        _root.insert();
    }

    void print() {
        _root.print();
    }
};

int a2i(char a) {
    return a - 'a';
}

void solve() {
    // 文字列の文字はアルファベット
    string T; cin >> T;

    // 文字の種類を求めよ
    set<char> U;
    for (auto t : T) {
        U.insert(t);
    }

    // 文字を区別するために必要なビット数を求めよ
    int d = U.size();
    int bitNum = 0;
    while (d != 1) {
        d /= 2;
        bitNum++;
    }

    Node node = Node(bitNum, T);
    BinaryTree tree = BinaryTree(node);
    tree.insert();
    tree.print();
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
