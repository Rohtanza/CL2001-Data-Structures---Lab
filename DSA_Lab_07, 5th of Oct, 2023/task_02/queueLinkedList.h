#ifndef LAB_7TASK02_QUEUELINKEDLIST_H
#define LAB_7TASK02_QUEUELINKEDLIST_H

#include <iostream>

using namespace std;

template<typename type>
class queueLinkedList {

    class Node {
    public:
        Node *next;
        type value;

        Node(type value) : value(value), next(nullptr) {}

        Node(type value, Node *next) : value(value), next(next) {}
    };

    Node *Front;
    Node *End;

public:

    queueLinkedList(int size = 0) : Front(nullptr), End(nullptr) {}

    bool isEmpty() { return Front == nullptr; }

    type frontItem() {
        if (isEmpty()) { throw underflow_error("UnderFlow"); }
        return Front->value;
    }

    void Enqueue(type item) {
        Node *node = new Node(item);
        if (End == nullptr) {
            Front = End = node;
        } else {
            End->next = node;
            End = node;
        }
    }

    type Dequeue() {
        if (isEmpty()) { return "-1"; }
        Node *temp = Front;
        type removed = temp->value;
        Front = Front->next;
        if (Front == nullptr)
            End = nullptr;
        delete temp;
        return removed;
    }

    bool display() {
        if (isEmpty()) { return false; }
        Node *temp = Front;
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "End";
        return true;
    }


};

#endif //LAB_7TASK02_QUEUELINKEDLIST_H
