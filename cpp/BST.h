#ifndef _BST_H
#define _BST_H

class BST {
    private:

        struct Node {
            int data;
            Node *left, *right;
            Node(int n = 0) : data(n), left(0), right(0) { }
        };
        Node* root;

        // CONSTRUCTORS AND DESTRUCTORS
        void _BST(Node*& n, const Node* source_n);
        void _clear(Node* n);

        // MODIFIERS
        Node* _insert(Node* n, int value);
        Node* _balance(Node* n, int value);
        Node* _leftRotate(Node* n);
        Node* _rightRotate(Node* n);

        // OBSERVERS
        int _height(Node* n) const;
        void _printTree(Node* n) const;
        bool _BFS(Node* n, int value) const;
        bool _DFS(Node* n, int value) const;

    public:

        // CONSTRUCTORS AND DESTRUCTORS
        BST() { root = 0; }
        BST(const BST& source);
        ~BST();

        // MODIFIERS
        void insert(int value);

        // OBSERVERS
        int height() const;
        void printTree() const;
        bool BFS(int value) const;
        bool DFS(int value) const;
};

#endif