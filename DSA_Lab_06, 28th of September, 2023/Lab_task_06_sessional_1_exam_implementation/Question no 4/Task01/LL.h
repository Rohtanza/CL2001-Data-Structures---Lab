//
// Created by rohtanza on 10/2/23.
//

#ifndef TASK01_LL_H
#define TASK01_LL_H


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
            size++;
        }
    }

    void print() {

        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "End";
    }

    void deleteFirst() {
        Node *temp = head;
        head = head->next;
        if (head->next == nullptr);
        tail == nullptr;
        delete temp;
        size--;

    }

    Node *get(int index) {

        Node *node = head;
        for (int i = 1; i < index - 1; ++i) {
            node = node->next;
        }
        return node;
    }

    void deleteIndex(int index) {

        Node *node = get(index);
        Node *temp = node->next;
        node->next = node->next->next;
        delete temp;
        size--;
    }

    void deleteLast() {
        Node *temp = tail;
        Node *node = get(size);
        tail = node;
        tail->next = nullptr;
        delete temp;
        size--;
    }

    Node *find(T value) {
        Node *node = head;
        while (node != nullptr) {
            if (node->value == value)
                return node;
            node = node->next;
        }
        return nullptr;

    }

    void reverseKNodes(int k) {
        if (k < 0 || k > size) {
            cout << "The parameter is invalid" << endl;
            return;
        }
        /*
         * The reason behind initializing j with 2 and z with k + 1
         * is that whenever I try to reach the first node, I need to give
         * the get node function 2 value, so that's why I am giving the
         * get function n+1 value.
         * */
        int j(2), z = k + 1;

        Node *loop = head;
        while (loop != nullptr) {
            Node *temp1 = get(j);
            Node *temp2 = get(z);
            auto temp = temp1->value;
            temp1->value = temp2->value;
            temp2->value = temp;
            if (loop != nullptr)
                for (int i = 0; i < k; ++i) {
                    loop = loop->next;
                    //this loop will get the loop done from the first group we just swapped
                }
            if (loop != nullptr)
                for (int i = 0; i < k; ++i) {
                    loop = loop->next;
                    //this loop will skip the loop k times
                }
            j = j + (k * 2);
            z = z + (k * 2);

        }
    }

};


#endif //TASK01_LL_H