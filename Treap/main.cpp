#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;

class Node {
public:

    long _key;
    long _priority;
    Node* _left = NULL;
    Node* _right = NULL;

    Node(long key, long priority, Node* left, Node* right): _key(key), _priority(priority), _left(left), _right(right) {}
    Node(long key, long priority): _key(key), _priority(priority) {}

    ~Node() {
        if (_left != NULL) {
            delete _left;
            _left = NULL;
        }
        if (_right != NULL) {
            delete _right;
            _right = NULL;
        }
    }

    bool find(long key) {
        if (key < _key) {
            if (_left != NULL) {
                return _left->find(key);
            } else {
                return false;
            }
        } else if (key > _key) {
            if (_right != NULL) {
                return _right->find(key);
            } else {
                return false;
            }
        } else {
            return true;
        }
    }

    Node* erase(long key) {
        if (key < _key) {
            if (_left != NULL) {
                printf("Erase %ld on the left node(%ld)\n", key, _left->_key);
                _left = _left->erase(key);
            } else {
                cout << "Could not be found." << endl;
            }
        } else if (key > _key) {
            if (_right != NULL) {
                printf("Erase %ld on the right node(%ld)\n", key, _right->_key);
                _right = _right->erase(key);
            } else {
                cout << "Could not be found." << endl;
            }
        } else {
            cout << "Could be found." << endl;

            if (_left == NULL && _right == NULL) {
                printf("Delete a node(%ld)\n", _key);
                delete this;
                return NULL;
            } else if (_left == NULL || _right == NULL) {
                printf("Delete a node(%ld)\n", _key);
                Node* tmp = _left != NULL ? _left : _right;
                _key = tmp->_key;
                delete tmp;
                if (_left != NULL) _left = NULL;
                else _right = NULL;
            } else {
                Node* tmp = _right;
                while (tmp->_left != NULL) {
                    tmp = tmp->_left;
                }
                _key = tmp->_key;
                _right = _right->erase(_key);
            }
        }

        return this;
    }

    void inorder() {
        if (_left != NULL) {
            _left->inorder();
        }

        cout << " " << _key;

        if (_right != NULL) {
            _right->inorder();
        }
    }

    void preorder() {
        cout << " " << _key;

        if (_left != NULL) {
            _left->preorder();
        }

        if (_right != NULL) {
            _right->preorder();
        }
    }
};

class Treap {
public:

    Node* _node;
    Treap() {}
    ~Treap() {
        if (_node != NULL) {
            delete _node;
            _node = NULL;
        }
    }

    Node* rightRotate(Node* t) {
        Node* s = t->_left;
        t->_left = s->_right;
        s->_right = t;
        return s;
    }

    Node* leftRotate(Node* t) {
        Node* s = t->_right;
        t->_right = s->_left;
        s->_left = t;
        return s;
    }

    Node* _insert(Node* t, long key, long priority) {
        if (t == NULL) {
            return new Node(key, priority);
        }

        if (key == t->_key) {
            return t;
        }

        if (key < t->_key) {
            t->_left = _insert(t->_left, key, priority);

            if (t->_priority < t->_left->_priority) {
                t = rightRotate(t);
            }
        } else {
            t->_right = _insert(t->_right, key, priority);

            if (t->_priority < t->_right->_priority) {
                t = leftRotate(t);
            }
        }

        return t;
    }

    bool find(long key) {
        return _node->find(key);
    }

    void insert(long key, long priority) {
        if (_node == NULL) {
            _node = new Node(key, priority);
        } else {
            _insert(_node, key, priority);
        }
    }

    void erase(int key) {
        _node->erase(key);
    }

    void print() {
        _node->inorder();
        cout << endl;
        _node->preorder();
        cout << endl;
    }
};

void solve() {
    int m; cin >> m;

    Treap tree;

    for (int i = 0; i < m; ++i) {
        string command; cin >> command;
        if (command == "insert") {
            long k, p; cin >> k >> p;
            tree.insert(k, p);
        } else if (command == "print") {
            tree.print();
        } else if (command == "find") {
            long k; cin >> k;
            if (tree.find(k)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        } else if (command == "delete") {
            long k; cin >> k;
            tree.erase(k);
        } else {}
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
