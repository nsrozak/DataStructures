#include "BST.h"
#include <iostream>
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
bool BST::insert(int value) {
    if (root == 0) {
        root = new Node(value);
        return true;
    }
    return _insert(root, value);
}

bool BST::balance() {
    int l_height = _height(root->left);
    int r_height = _height(root->right);
    int height_diff = l_height - r_height;
        
    if ((height_diff > 1) || (height_diff < -1))
        return false;
    else
        return true;
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
    // to do 
    return true;
}

bool BST::_DFS(Node* n, int value) const {
    // to do
    return true;
}