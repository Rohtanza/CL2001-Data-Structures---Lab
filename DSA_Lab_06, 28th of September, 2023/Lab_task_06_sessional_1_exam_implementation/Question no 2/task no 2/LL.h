//
// Created by rohtanza on 10/2/23.
//

#ifndef TASK_NO_2_LL_H
#define TASK_NO_2_LL_H


#include <iostream>

using namespace std;

template<typename T>
class LL {

    class Node {
    public:

        Node *next;
        T value;

        Node(T value) : value(value), next(nullptr) {}

        Node(T value, Node *next) : value(value), next(next) {}
    };

    Node *head;
    Node *tail;
    size_t size;
public:
    LL(int size = 0) : size(size), head(nullptr), tail(nullptr) {}


    void insertFirst(T value) {
        Node *node = new Node(value);

        node->next = head;
        head = node;

        if (tail == nullptr) {
            tail = head;
        } else { // New line to make the list circular
            tail->next = head;
        }
        size++;
    }

    void insertEnd(T value) {
        Node *node = new Node(value);
        if (tail == nullptr) {
            insertFirst(value);
            return;
        }
        tail->next = node;
        tail = node;
        tail->next = head; // New line to make the list circular
        size++;
    }

    void insert(T value, int pos) {

        if (pos < 1 || pos > size + 1) {
            cout << "Invalid pos" << endl;
            return;
        }
        if (pos == 1) {
            insertFirst(value);
            return;
        } else if (pos == size) {
            insertEnd(value);
            return;
        } else {
            Node *temp = head;
            for (int i = 1; i < pos - 1; ++i) {
                temp = temp->next;
            }
            Node *node = new Node(value, temp->next);
            temp->next = node;
            if (node->next == head) {
                tail = node;
            }
            size++;
        }
    }

    Node *get(int index) {
        if (index < 0 || index > size + 2) {
            cout << "Get function Index invalid" << endl;
            exit(-1);
        }
        Node *node = head;
        for (int i = 1; i < index - 1; ++i) {
            node = node->next;
        }
        return node;
    }

    void print() {

        Node *temp = head;
        do {
            cout << temp->value << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "End";
    }

    bool isPalindrome() {
        int j(2), z(size + 1);
        bool check = true;
        for (int i = 0; i < ((size / 2) + 1); ++i) {
            Node *temp1 = get(j);
            Node *temp2 = get(z);
            if (temp1->value != temp2->value)
                check = false;
            j++, z--;
        }
        return check;

    }
};


#endif //TASK_NO_2_LL_H
