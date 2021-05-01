#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    // create a BST
    BST tree1;
    int values[7] = {16, 7, 2, 4, 10, 12, 3};
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        tree1.insert(values[i]);
    }

    cout << "Tree 1 values: " << endl;
    tree1.printTree();

    BST tree2 = tree1;
    cout << "Tree 2 values: " << endl;
    tree2.printTree();

    return 0;
}