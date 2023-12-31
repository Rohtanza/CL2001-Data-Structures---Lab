//
// Created by test2023 on 23/11/2023.
//

#ifndef HEAPTASK_HEAP_H
#define HEAPTASK_HEAP_H

#include <vector>
#include "Patient.h"

class Heap {
public:
    vector <Patient> htree;

    int getParent(int child) {
        return (child - 1) / 2;
    }

    int getLeft(int parent) {
        return parent * 2 + 1;
    }

    int getRight(int parent) {
        return parent * 2 + 2;
    }

    void swap(Patient *a, Patient *b) {
        Patient temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node) {
        int parent = getParent(node);
        if (node != 0 && htree[node].urgency < htree[parent].urgency) {
            swap(&htree[node], &htree[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int node) {
        int left = getLeft(node);
        int right = getRight(node);
        int smallest = node;
        if (left < htree.size() && htree[left].urgency < htree[smallest].urgency)
            smallest = left;
        if (right < htree.size() && htree[right].urgency < htree[smallest].urgency)
            smallest = right;
        if (smallest != node) {
            swap(&htree[node], &htree[smallest]);
            heapifyDown(smallest);
        }
    }

    void insert(Patient patient) {
        htree.push_back(patient);
        heapifyUp(htree.size() - 1);
    }

    void del() {
        if (htree.empty()) {
            cout << "No appointments to display." << endl;
            return;
        }
        swap(&htree[0], &htree[htree.size() - 1]);
        htree.pop_back();
        heapifyDown(0);
    }

    void updateUrgency(string patientName, int newUrgency) {
        for (int i = 0; i < htree.size(); i++) {
            if (htree[i].name == patientName) {
                htree[i].urgency = newUrgency;
                heapifyUp(i);
                break;
            }
        }
    }

    void display() {
        if (htree.empty()) {
            cout << "No appointments to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++) {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
    }
};

#endif //HEAPTASK_HEAP_H
