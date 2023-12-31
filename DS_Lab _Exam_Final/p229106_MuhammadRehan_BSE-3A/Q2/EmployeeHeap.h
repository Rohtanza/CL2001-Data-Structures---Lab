//
// Created by rohtanza on 12/12/23.
//

#ifndef Q2_EMPLOYEEHEAP_H
#define Q2_EMPLOYEEHEAP_H


#include <iostream>
#include <vector>
#include <algorithm>
#include "Employee.h"


template<typename T>
class EmployeeHeap {
private:
    std::vector<T> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    void siftDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            siftDown(largest);
        }
    }

public:
    void insert(T key) {
        heap.push_back(key);
        int i = heap.size() - 1;
        while (i != 0 && heap[parent(i)] < heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void deleteMax() {
        if (heap.empty()) {
            std::cout << "Heap is empty." << std::endl;
            return;
        }
        if (heap.size() == 1) {
            heap.clear();
            return;
        }
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        siftDown(0);
    }

    void display() {
        if (heap.empty()) {
            std::cout << "Heap is empty." << std::endl;
            return;
        }
        for (const auto &item: heap)
            std::cout << item << " ";
        std::cout << std::endl;
    }

    T getMax() {
        if (heap.empty()) {
            std::cerr << "Heap is empty. No maximum element." << std::endl;
            return T{};
        }
        return heap[0];
    }
};


#endif //Q2_EMPLOYEEHEAP_H
