#include <iostream>
#include "Tree.h"

int main() {
    Tree<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "In-order traversal: ";
    tree.transversal();


    size_t level = tree.findlevel(5);



    size_t depth = tree.depth();
    cout << "Depth of the tree: " << depth << endl;



    tree.deleteTree();

    return 0;
}
