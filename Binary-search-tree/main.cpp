#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

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

class Node {
public:

    int _value;
    Node* _left = NULL;
    Node* _right = NULL;

    Node(int value, Node* left, Node* right): _value(value), _left(left), _right(right) {}
    Node(int value): _value(value) {}

    ~Node() {
        if (_left != NULL) {
            printf("Delete a node(%d) on the left\n", _left->_value);
            delete _left;
            _left = NULL;
        }
        if (_right != NULL) {
            printf("Delete a node(%d) on the right\n", _right->_value);
            delete _right;
            _right = NULL;
        }
    }

    void find(int value) {
        if (value < _value) {
            if (_left != NULL) {
                printf("Find %d on the left node(%d)\n", value, _left->_value);
                return _left->find(value);
            } else {
                cout << "Could not be found." << endl;
                return ;
            }
        } else {
            if (value == _value) {
                cout << "Could be found." << endl;
                return ;
            }

            if (_right != NULL) {
                printf("Find %d on the right node(%d)\n", value, _right->_value);
                return _right->find(value);
            } else {
                cout << "Could not be found." << endl;
                return ;
            }
        }
    }

    void insert(int value) {
        if (value < _value) {
            if (_left != NULL) {
                return _left->insert(value);
            } else {
                printf("Insert Node(%d) on the left.\n", value);
                _left = new Node(value);
                return ;
            }
        } else {
            if (_right != NULL) {
                return _right->insert(value);
            } else {
                printf("Insert Node(%d) on the right.\n", value);
                _right = new Node(value);
                return ;
            }
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

class BinarySearchTree {
public:

    Node _node;
    BinarySearchTree(Node& node): _node(node) {}

    void find(int value) {
        return _node.find(value);
    }

    void insert(int value) {
        return _node.insert(value);
    }

    void print() {
        _node.print();
    }
};

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) { cin >> a[i]; }

    Node root = Node(3);
    BinarySearchTree tree = BinarySearchTree(root);
    cout<<tree._node._value<<endl;

    for (int i = 0; i < n; ++i) {
        root.insert(a[i]);
    }

    root.find(5);

    root.print();
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
