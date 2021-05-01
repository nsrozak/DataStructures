#include "BST.h"
#include <iostream>
using namespace std;

// *** PUBLIC *** //

// CONSTRUCTORS AND DESTRUCTORS
BST::BST(const BST& source){
    _BST(root, source.root);
}

BST::~BST() {
    _clear(root);
}

// MODIFIERS
bool BST::insert(int value) {
    if (root == 0) {
        root = new Node(value);
        return true;
    }
    return _insert(root, value);
}

// OBSERVERS
void BST::printTree() const {
    _printTree(root);
}


bool BST::BFS(int value) const {
    return _BFS(root, value);
}

bool BST::DFS(int value) const {
    return _DFS(root, value);
}

// *** PRIVATE *** //

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
bool BST::_insert(Node* n, int value){
    if (value == n->data)
        return false;
    if (value < n->data) {
        if (n->left != 0)
            return _insert(n->left, value);
        else {
            n->left = new Node(value);
            return true;
        }
    }
    else {
        if (n->right != 0)
            return _insert(n->right, value);
        else {
            n->right = new Node(value);
            return true;
        }
    }
}

// OBSERVERS
void BST::_printTree(Node* n) const {
    if (n != 0) {
        _printTree(n->left);
        cout << n->data << " ";
        _printTree(n->right);
    }
}

bool BST::_BFS(Node* n, int value) const {
    // to do 
    return true;
}

bool BST::_DFS(Node* n, int value) const {
    // to do
    return true;
}