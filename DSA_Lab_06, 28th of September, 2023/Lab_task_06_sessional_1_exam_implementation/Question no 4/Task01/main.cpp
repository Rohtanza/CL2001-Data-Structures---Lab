/*question no 4:
 * Assume you are given a linked list of integers. Write a function (called reverseKNodes, has one integer
 * parameter k) reverses every alternate group of k nodes in the linked list. For example, if the linked list
 * is as given below and k is 3.
 * */


#include <iostream>
#include "LL.h"

int main() {
    LL<int> *list = new LL<int>();

    // filling the linked list
    for (int i = 12; i > 0; --i) {
        list->insertFirst(i);

    }

    list->print();
    list->reverseKNodes(3);
    cout << endl;
    list->print();
    return 0;
}
