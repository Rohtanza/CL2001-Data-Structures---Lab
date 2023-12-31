//
// Created by rohtanza on 10/5/23.
//

#ifndef LAB_07_QUEUECLASS_H
#define LAB_07_QUEUECLASS_H

#include <iostream>

using namespace std;

template<typename type>
class queueClass {

    type *data;
    size_t capacity;
    size_t front;
    size_t end;

public:
    queueClass() : queueClass(capacity) {}

    queueClass(int size) : capacity(size), front(0), end(0) {
        data = new type[size];
    }

    ~queueClass() { delete[] data; }

    bool isFull() { return (end + 1) % capacity == front; }

    bool isEmpty() { return front == end; }

    type frontItem() {
        if (isEmpty()) { throw underflow_error("UnderFlow"); }
        return data[front];
    }

    type endItem() {
        if (isEmpty()) { throw underflow_error("UnderFlow"); }
        return data[end];
    }

    bool Enqueue(type item) {
        if (isFull()) { throw overflow_error("OverFlow"); }
        data[end++] = item;
        end %= capacity;
        return true;
    }

    type Dequeue() {
        if (isEmpty()) { throw underflow_error("UnderFlow"); }
        type removed = data[front++];
        front %= capacity;
        return removed;
    }

    bool display() {
        if (isEmpty()) { return false; }
        size_t i = front;
        while (i != end) {
            cout << data[i++] << "->";
            i %= capacity;
        }
        cout << "End" << endl;
        return true;
    }

};


#endif //LAB_07_QUEUECLASS_H
