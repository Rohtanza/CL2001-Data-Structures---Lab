//
// Created by rohtanza on 11/30/23.
//

#ifndef TOWEROFHANOI_STACK_H
#define TOWEROFHANOI_STACK_H


#include "Node.h"

class Stack {
    Node *top;
    unsigned int size;
    string tag;
public:
    Stack(string Tag) : tag(Tag), size(0) { top = new Node(); }

    Stack(Node *data) : top(data), size(1) {}

    Node *peek() const { return top; }

    unsigned int getSize() const { return size; }

    string getTag() const { return tag; }

    void push(Node *node) {
        if (size > 0) {
            if (top->data->Length > node->data->Length) {
                node->next = top;
                top = node;
            }
        } else top = node;
        size++;
    }

    void pop() {
        if (size > 1) {
            Node *temp = top;
            top = top->next;
            delete temp;
        } else if (size == 1) {
            Node *temp = top;
            top = nullptr;
            delete temp;
        }
        size--;
    }

    void print() {
        if (size > 0) {
            Node *temp = top;
            while (temp != nullptr) {
                temp->print();
                cout << endl;
                temp = temp->next;
            }
        }
        cout << "______" << tag;
    }
};


#endif //TOWEROFHANOI_STACK_H
