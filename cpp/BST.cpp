#include "BST.h"
#include <iostream>
#include <queue>
using namespace std;

// *** PUBLIC MEMBER FUNCTIONS *** //

// CONSTRUCTORS AND DESTRUCTORS
BST::BST(const BST& source){
    _BST(root, source.root);
}

BST::~BST() {
    _clear(root);
}

// MODIFIERS
void BST::insert(int value) {
    root = _insert(root, value);
}

// OBSERVERS
int BST::height() const {
    return _height(root);
}

void BST::printTree() const {
    _printTree(root);
}


bool BST::BFS(int value) const {
    return _BFS(root, value);
}

bool BST::DFS(int value) const {
    return _DFS(root, value);
}

// *** PRIVATE MEMBER FUNCTIONS *** //

// CONSTRUCTORS AND DESTRUCTOR
void BST::_BST(Node*& n, const Node* source_n) {
    if (source_n == 0) {
        n = 0;
        return;
    }
    n = new Node(source_n->data);
    _BST(n->left, source_n->left);
    _BST(n->right, source_n->right);
}

void BST::_clear(Node* n) {
    if (n != 0) {
        _clear(n->left);
        _clear(n->right);
        delete n;
    }
}

// MODIFIERS
BST::Node* BST::_insert(Node* n, int value){
    if (n == 0) {
        n = new Node(value);
        return n;
    }
    else if (value < n->data) {
        n->left = _insert(n->left, value);
        n = _balance(n, value);
    }
    else if (value > n->data) {
        n->right = _insert(n->right, value);
        n = _balance(n, value);
    }
    return n;
}

BST::Node* BST::_balance(Node* n, int value) {
    int l_height = _height(n->left);
    int r_height = _height(n->right);
    int balance_factor = l_height - r_height;

    if ((balance_factor > 1) && (value < n->left->data)) {  // left, left
        return _rightRotate(n);
    }
    else if ((balance_factor > 1) && (value > n->left->data)) {  // left, right
        n->left = _leftRotate(n->left);
        return _rightRotate(n);
    }
    else if ((balance_factor < -1) && (value < n->right->data)) {  // right, left
        n->right = _rightRotate(n->right);
        return _leftRotate(n);
    }
    if ((balance_factor < -1) && (value > n->right->data)) {  // right, right
        return _leftRotate(n);
    }
    else
        return n;
}

BST::Node* BST::_leftRotate(Node* n) {
    Node* swap = n->right;
    n->right = swap->left;
    swap->left = n;
    return swap;
}

BST::Node* BST::_rightRotate(Node* n){
    Node* swap = n->left;
    n->left = swap->right;
    swap->right = n;
    return swap;
}

// OBSERVERS
int BST::_height(Node* n) const {
    if (n == 0)
        return 0;
    else 
        return 1 + max(_height(n->left), _height(n->right));
}

void BST::_printTree(Node* n) const {
    if (n != 0) {
        _printTree(n->left);
        cout << n->data << " ";
        _printTree(n->right);
    }
}

bool BST::_BFS(Node* n, int value) const {
    if (n == 0)
        return false;

    std::queue<Node*> q;
    q.push(n);
    
    while (q.empty() == false) {
        Node* n_front = q.front();
        q.pop();

        if (n_front->data == value)
            return true;

        if (n_front->left != 0)
            q.push(n_front->left);
        if (n_front->right != 0)
            q.push(n_front->right);
    }
    return false;
}

bool BST::_DFS(Node* n, int value) const {
    if (n == 0) 
        return false;

    if (n->data == value)
        return true;
    
    bool recursive_left = _DFS(n->left, value);
    if (recursive_left == true)
        return true;

    bool recursive_right = _DFS(n->right, value);
    return recursive_right;  
}
