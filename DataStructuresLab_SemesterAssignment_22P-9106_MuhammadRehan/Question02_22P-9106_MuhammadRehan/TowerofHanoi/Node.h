//
// Created by rohtanza on 11/30/23.
//

#ifndef TOWEROFHANOI_NODE_H
#define TOWEROFHANOI_NODE_H


#include "Disk.h"

class Node {
public:
    Disk *data;
    Node *next;

    Node() : data(nullptr), next(nullptr) {}

    Node(Disk *diskS) : data(diskS), next(nullptr) {}

    void print() {
        for (unsigned int i = 0; i < data->Length; i++)
            cout << data->character;
    }

};

#endif //TOWEROFHANOI_NODE_H
