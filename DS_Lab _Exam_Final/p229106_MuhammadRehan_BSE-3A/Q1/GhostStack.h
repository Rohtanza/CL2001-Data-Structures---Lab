//
// Created by rohtanza on 12/12/23.
//

#ifndef Q1_GHOSTSTACK_H
#define Q1_GHOSTSTACK_H

#include <memory>
#include <iostream>

using namespace std;

class GhostStack {
private:
    class Node {
    public:
        Node(string value, Node *next) : value(value), next(next) {}

        string value;
        unique_ptr<Node> next;
    };

    size_t Stack_Length;
    unique_ptr<Node> top;

public:
    GhostStack() : top(nullptr), Stack_Length(0) {}

    bool isEmpty();

    string peek();

    void push(string value);

    string pop();

    void print();
};


void GhostStack::print() {
    if (isEmpty()) {
        cout << "GhostStack is empty" << endl;
        return;
    }

    GhostStack tempStack;
    while (!isEmpty()) {
        string element = pop();
        tempStack.push(element);
    }
    while (!tempStack.isEmpty()) {
        string i = tempStack.pop();
        cout << i << " -> ";
        push(i); // Push the element back to the original stack
    }

    cout << endl;
}


string GhostStack::pop() {
    if (isEmpty()) {
        cout << "Can't use pop, the stack is empty" << endl;
        return "-1";
    }
    string tempValue = top->value;
    top = move(top->next);
    Stack_Length--;
    return tempValue;
}

void GhostStack::push(string value) {
    unique_ptr<Node> newNode = make_unique<Node>(value, top.release());
    top = move(newNode);
    Stack_Length++;
}

string GhostStack::peek() {
    if (isEmpty()) {
        cout << "GhostStack is empty" << endl;
        return "-1";
    }
    return top->value;
}


bool GhostStack::isEmpty() {
    return top == nullptr;
}

#endif //Q1_GHOSTSTACK_H
