#ifndef TASK_03_STACK_H
#define TASK_03_STACK_H

#include <memory>
#include <iostream>

using namespace std;

template<typename T>
class Stack {
private:
    class Node {
    public:
        Node(T value, Node *next) : value(value), next(next) {}

        T value;
        unique_ptr<Node> next;
    };

    size_t Stack_Length;
    unique_ptr<Node> top;

public:
    Stack() : top(nullptr), Stack_Length(0) {}

    bool isEmpty();

    T peek();

    void push(T value);

    T pop();

    void print();
};

template<typename T>
void Stack<T>::print() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }

    Stack<T> tempStack;
    while (!isEmpty()) {
        T element = pop();
        tempStack.push(element);
    }
    while (!tempStack.isEmpty()) {
        T i = tempStack.pop();
        cout << i << " ";
        push(i); // Push the element back to the original stack
    }

    cout << endl;
}


template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Can't use pop, the stack is empty" << endl;
        return T(-1);
    }
    T tempValue = top->value;
    top = move(top->next);
    Stack_Length--;
    return tempValue;
}

template<typename T>
void Stack<T>::push(T value) {
    unique_ptr<Node> newNode = make_unique<Node>(value, top.release());
    top = move(newNode);
    Stack_Length++;
}

template<typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return T(-1);
    }
    return top->value;
}


template<typename T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}

#endif //TASK_03_STACK_H
