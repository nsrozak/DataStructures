#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    // create a BST
    BST tree1;
    int values[8] = {8, 7, 2, 4, 10, 12, 7, 3};
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        tree1.insert(values[i]);
    }

    cout << "Tree 1 values: " << endl;
    tree1.printTree();
    cout << endl;
    cout << "Tree 1 height: " << tree1.height() << endl;
    cout << "Tree 1 DFS false: " << tree1.DFS(20) << endl;
    cout << "Tree 1 DFS true: " << tree1.DFS(10) << endl;
    cout << "Tree 1 BFS false: " << tree1.BFS(20) << endl;
    cout << "Tree 1 BFS true: " << tree1.BFS(10) << endl;

    BST tree2 = tree1;
    cout << "Tree 2 values: " << endl;
    tree2.printTree();
    cout << endl;

    BST tree3;
    cout << "Tree 3 BFS: " << tree3.BFS(10) << endl; 

    return 0;
}