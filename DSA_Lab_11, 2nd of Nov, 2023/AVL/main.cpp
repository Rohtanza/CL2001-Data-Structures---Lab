#include<iostream>
#include "AVL.h"

using namespace std;


int main() {
    AVL<float> tree;
    int option;
    while (true) {
        cout
                << "1. Insert\n2. Remove\n3. Display Tree\n4. Inorder Traversal\n5. Find Max\n6. Find Min\n7. Update\n8. Search Value\n9. Exit\nEnter your option: ",
                cin >> option;
        switch (option) {
            case 1:
                int value;
                cout << "Enter value to enter:", cin >> value;
                tree.insert(value);
                break;
            case 2: {
                int value;
                cout << "Enter value to remove :", cin >> value;
                tree.remove(value);
            }
                break;
            case 3:
                tree.displayTree();
                break;
            case 4:
                tree.inorder();
                break;
            case 5:
                tree.FindMax();
                break;
            case 6:
                tree.FindMin();
                break;
            case 7: {
                int value, update;
                cout << "Enter value to update :", cin >> value;
                cout << "Enter value to update with :", cin >> update;
                tree.update(value, update);
            }
                break;
            case 8: {
                int value;
                cout << "Enter value to search :", cin >> value;
                if (tree.searchValue(value))cout << "Value exits" << endl;
                else cout << "Value does not exits" << endl;
            }
                break;
            case 9:
                return 0;
            default:
                cout << "Enter a valid option" << endl;
        }
    }

    return 0;


}
