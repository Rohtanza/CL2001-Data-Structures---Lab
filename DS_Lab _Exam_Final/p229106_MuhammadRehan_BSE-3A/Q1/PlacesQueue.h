//
// Created by rohtanza on 12/12/23.
//

#ifndef Q1_PLACESQUEUE_H
#define Q1_PLACESQUEUE_H

#include <iostream>

using namespace std;


template<typename type>
class PlacesQueue {

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

    PlacesQueue(int size = 0) : Front(nullptr), End(nullptr) {}

    bool isEmpty() { return Front == nullptr; }

    type frontItem() {
        if (isEmpty()) { throw underflow_error("No more places."); }
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
        temp = nullptr;
        return removed;
    }

    bool display() {
        if (isEmpty()) {
            cout << "No Places in the mansion." << endl;
            return false;
        }
        Node *temp = Front;
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "End";
        return true;
    }


};


#endif //Q1_PLACESQUEUE_H
