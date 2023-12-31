//
// Created by Rayhan on 9/14/2023.
//

#ifndef DSA_LAB_04__14TH_OF_SEPTEMBER__2023_TASKLIST_H
#define DSA_LAB_04__14TH_OF_SEPTEMBER__2023_TASKLIST_H


#include "TaskNode.h"

class taskList {

    TaskNode *head;
    TaskNode *prev;
    size_t length;

public:
    taskList();

    void addTask(const string &name, int pos);

    void markTask(int pos);

    void removeTask();

    void displayTasks(bool reverseOrder);

    ~taskList();


};


#endif //DSA_LAB_04__14TH_OF_SEPTEMBER__2023_TASKLIST_H
