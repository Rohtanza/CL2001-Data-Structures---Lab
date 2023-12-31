//
// Created by rohtanza on 11/25/23.
//

#ifndef TOWEROFHANOI_DISK_H
#define TOWEROFHANOI_DISK_H

#include <iostream>

using namespace std;

class Disk {
public:
    char character;
    unsigned int Length;

    Disk(unsigned int l, char c = '*') : Length(l), character(c) {}
};

#endif //TOWEROFHANOI_DISK_H
