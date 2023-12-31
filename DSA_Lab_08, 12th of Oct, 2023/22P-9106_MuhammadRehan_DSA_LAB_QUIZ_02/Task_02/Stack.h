//
// Created by rohtanza on 10/12/23.
//

#ifndef TASK_02_STACK_H
#define TASK_02_STACK_H

#include <iostream>
#include <memory>
#include <optional>

using namespace std;

template<typename datatype>
class Stack {
    class Node {
        datatype data;
        unique_ptr<Node> next;

        friend class Stack;

    public:
        explicit Node(datatype data) : next(nullptr), data(data) {}
    };


    unique_ptr<Node> top;
    size_t size;
public:

    size_t sizeStack() {
        return size;
    }

    optional<datatype> topElement() {
        // i am using a optinal datatype here, as it is only the sol to use
        // when using the templete datatype and user call it on empty stack
        // it will prevent the program crash
        if (empty())
            return nullopt;
        return optional<datatype>(top->data);

    }


    Stack() : size(0), top(nullptr) {}

    bool empty() { return size == 0; }

    datatype pop() {
        if (empty())
            throw out_of_range("Stack underflow\n");
        datatype temp = top->data;
        top = move(top->next);
        size--;
        return temp;
    }


    bool push(datatype data) {
        unique_ptr<Node> newNode;
        try {
            newNode = make_unique<Node>(data);
        } catch (const bad_alloc &node) {
            cerr << "Memory Allocation failed " << node.what() << endl;
            return false;
        }
        newNode->next = move(top);
        top = move(newNode);
        size++;
        return true;
    }

    void display() {
        const Node *current = top.get();
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next.get();
        }
        std::cout << " End." << std::endl;
    }


};


#endif //TASK_02_STACK_H
