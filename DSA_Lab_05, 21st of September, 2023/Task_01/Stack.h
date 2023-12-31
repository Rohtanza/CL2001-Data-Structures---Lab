//
// Created by rohtanza on 9/21/23.
//

#ifndef TASK_01_STACK_H
#define TASK_01_STACK_H

#include <memory>
#include <iostream>

using namespace std;

template<typename T>
class Stack {
private:
    class Node {
        Node(T value, Node *next) : value(value), next(next) {}

    public:
        explicit Node(T value) : value(value), next(nullptr) {}

        unique_ptr<Node> next;
        T value;
    };

    size_t Stack_Length;
    unique_ptr<Node> top;

public:
    Stack() : top(nullptr), Stack_Length(0) {}

    bool isEmpty();

    T peek();

    void push(T value);

    T pop();


};

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Cant use pop , the stack is empty" << endl;
        return T(-1);
    }
    auto tempValue = top->value;
    top = move(top->next);
    Stack_Length--;
    return tempValue;
}


template<typename T>
void Stack<T>::push(T value) {
    unique_ptr<Node> newNode = make_unique<Node>(value);
    newNode->next = move(top);
    top = move(newNode);
    Stack_Length++;

}

template<typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return top->data;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}


#endif //TASK_01_STACK_H
