//
// Created by rohtanza on 10/12/23.
//

#ifndef TASK_01_CIRUCULARLINKEDLIST_H
#define TASK_01_CIRUCULARLINKEDLIST_H

#include <iostream>

using namespace std;

template<typename T>

class CircularLinkedList {

    class Node {
    public:

        Node *next;
        T value;

        explicit Node(T value) : value(value), next(nullptr) {}

        Node(T value, Node *next) : value(value), next(next) {}
    };

    Node *head;
    Node *tail;
    size_t size;

public:
    CircularLinkedList() : size(size), head(nullptr), tail(nullptr) {
        if (size > 0)
            tail = head;
    }

    void insertFirst(T value) {
        Node *node = new Node(value);

        if (size == 0) {
            head = node;
            tail = node;
            node->next = head;
        } else {
            node->next = head;
            head = node;
            tail->next = head;
        }

        size++;
    }

    void insertEnd(T value) {
        Node *node = new Node(value);
        if (size == 0) {
            insertFirst(value);
        } else {
            tail->next = node;
            tail = node;
            tail->next = head;
            size++;
        }
    }

    void insert(T value, int pos) {
        if (pos < 1 || pos > size + 1) {
            cout << "Invalid pos" << endl;
            return;
        }
        if (pos == 1) {
            insertFirst(value);
        } else if (pos == size + 1) {
            insertEnd(value);
        } else {
            Node *temp = head;
            for (int i = 1; i < pos - 1; ++i) {
                temp = temp->next;
            }
            Node *node = new Node(value, temp->next);
            temp->next = node;
            size++;
        }
    }

    void print(int index) {
        if (size == 0) {
            cout << "List is empty." << endl;
            return;
        }
        size_t i = 0;
        size_t flag = index;
        Node *temp = head;
        do {
            if (i == flag)
                cout << temp->value << endl;
            temp = temp->next;
            i++;
        } while (temp != head);
    }

    void deleteFirst() {
        if (size == 0) {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        size--;

        if (size == 0) {
            head = nullptr;
            tail = nullptr;
        }
    }

    Node *get(int index) {
        if (index < 1 || index > size) {
            cout << "Invalid index" << endl;
            return nullptr;
        }

        Node *node = head;
        for (int i = 1; i < index; ++i) {
            node = node->next;
        }
        return node;
    }

    void deleteIndex(int index) {
        if (index < 1 || index > size) {
            cout << "Invalid index" << endl;
            return;
        }

        if (index == 1) {
            deleteFirst();
        } else {
            Node *node = get(index - 1);
            Node *temp = node->next;
            node->next = node->next->next;
            cout << temp->value << endl;
            cout << "\tWitch : " << temp->value << " is out of the circle" << endl;
            delete temp;
            size--;
        }
    }

    void deleteLast() {
        if (size == 0) {
            cout << "List is empty." << endl;
            return;
        }

        if (size == 1) {
            deleteFirst();
        } else {
            Node *temp = tail;
            Node *prevNode = get(size - 1);
            tail = prevNode;
            tail->next = head;
            delete temp;
            size--;
        }
    }

    Node *find(T value) {
        if (size == 0) {
            cout << "List is empty." << endl;
            return nullptr;
        }

        Node *node = head;
        do {
            if (node->value == value)
                return node;
            node = node->next;
        } while (node != head);

        return nullptr;
    }
};


#endif //TASK_01_CIRUCULARLINKEDLIST_H

