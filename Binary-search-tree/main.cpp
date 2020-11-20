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
                _left->find(value);
            } else {
                cout << "Could not be found." << endl;
            }
        } else if (value > _value) {
            if (_right != NULL) {
                printf("Find %d on the right node(%d)\n", value, _right->_value);
                _right->find(value);
            } else {
                cout << "Could not be found." << endl;
            }
        } else {
            cout << "Could be found." << endl;
        }
    }

    void insert(int value) {
        if (value < _value) {
            if (_left != NULL) {
                _left->insert(value);
            } else {
                printf("Insert Node(%d) on the left.\n", value);
                _left = new Node(value);
            }
        } else {
            if (_right != NULL) {
                _right->insert(value);
            } else {
                printf("Insert Node(%d) on the right.\n", value);
                _right = new Node(value);
            }
        }
    }

    Node* erase(int value) {
        if (value < _value) {
            if (_left != NULL) {
                printf("Erase %d on the left node(%d)\n", value, _left->_value);
                _left = _left->erase(value);
            } else {
                cout << "Could not be found." << endl;
            }
        } else if (value > _value) {
            if (_right != NULL) {
                printf("Erase %d on the right node(%d)\n", value, _right->_value);
                _right = _right->erase(value);
            } else {
                cout << "Could not be found." << endl;
            }
        } else {
            cout << "Could be found." << endl;

            if (_left == NULL && _right == NULL) {
                printf("Delete a node(%d)\n", _value);
                delete this;
                return NULL;
            } else if (_left == NULL || _right == NULL) {
                printf("Delete a node(%d)\n", _value);
                Node* tmp = _left != NULL ? _left : _right;
                _value = tmp->_value;
                delete tmp;
                if (_left != NULL) _left = NULL;
                else _right = NULL;
            } else {
                Node* tmp = _right;
                while (tmp->_left != NULL) {
                    tmp = tmp->_left;
                }
                _value = tmp->_value;
                _right = _right->erase(_value);
            }
        }

        return this;
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
        _node.find(value);
    }

    void insert(int value) {
        _node.insert(value);
    }

    void erase(int value) {
        _node.erase(value);
    }

    void print() {
        _node.print();
    }
};

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) { cin >> a[i]; }

    Node root = Node(a[0]);
    BinarySearchTree tree = BinarySearchTree(root);

    for (int i = 1; i < n; ++i) {
        tree.insert(a[i]);
    }

    tree.find(5);

    tree.print();

    tree.erase(10);
    tree.erase(6);
    tree.erase(2);
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
