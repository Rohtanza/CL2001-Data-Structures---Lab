#include <iostream>
#include "LL.h"

int main() {
    LL<char> *list = new LL<char>();

    // filling the linked list
    list->insertFirst('r');
    list->insertFirst('a');
    list->insertFirst('c');
    list->insertFirst('e');
    list->insertFirst('c');
    list->insertFirst('a');
    list->insertFirst('r');


    if(list->isPalindrome())
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    list->print();
    cout << endl;
    list->print();
    return 0;
}