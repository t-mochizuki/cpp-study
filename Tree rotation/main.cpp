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

    Node* find(long key) {
        if (key < _key) {
            if (_left != NULL) {
                return _left->find(key);
            } else {
                return NULL;
            }
        } else if (key > _key) {
            if (_right != NULL) {
                return _right->find(key);
            } else {
                return NULL;
            }
        } else {
            return this;
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
                rotateRight(t);
            }
        } else {
            t->_right = _insert(t->_right, key, priority);

            if (t->_priority < t->_right->_priority) {
                rotateLeft(t);
            }
        }

        return t;
    }

    void insert(long key, long priority) {
        if (_node == NULL) {
            _node = new Node(key, priority);
        } else {
            _insert(_node, key, priority);
        }
    }

    Node* find(long key) {
        return _node->find(key);
    }

    void print(Node* t) {
        inorder(t);
        cout << endl;
        preorder(t);
        cout << endl;
    }

    void inorder(Node* t) {
        if (t->_left != NULL) {
            inorder(t->_left);
        }

        cout << " " << t->_key;

        if (t->_right != NULL) {
            inorder(t->_right);
        }
    }

    void preorder(Node* t) {
        cout << " " << t->_key;

        if (t->_left != NULL) {
            preorder(t->_left);
        }

        if (t->_right != NULL) {
            preorder(t->_right);
        }
    }

    Node* rotateRight(Node* t) {
        Node* s = t->_left;
        t->_left = s->_right;
        s->_right = t;
        return s;
    }

    Node* rotateLeft(Node* t) {
        Node* s = t->_right;
        t->_right = s->_left;
        s->_left = t;
        return s;
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
            tree.print(tree._node);
        } else if (command == "find") {
            long k; cin >> k;
            if (tree.find(k) != NULL) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        } else if (command == "rotate_left") {
            long k; cin >> k;
            Node* s = tree.find(k);
            if (s == tree._node) {
                if (s != NULL) {
                    s = tree.rotateLeft(s);
                    tree._node = s;
                }
            } else {
                if (s != NULL) {
                    s = tree.rotateLeft(s);
                }
            }
        } else if (command == "rotate_right") {
            long k; cin >> k;
            Node* s = tree.find(k);
            if (s == tree._node) {
                if (s != NULL) {
                    s = tree.rotateRight(s);
                    tree._node = s;
                }
            } else {
                if (s != NULL) {
                    s = tree.rotateRight(s);
                }
            }
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
