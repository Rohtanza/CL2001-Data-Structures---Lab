//
// Created by Rayhan on 9/14/2023.
//

#ifndef DSA_LAB_04__14TH_OF_SEPTEMBER__2023_TASKNODE_H
#define DSA_LAB_04__14TH_OF_SEPTEMBER__2023_TASKNODE_H

#include<iostream>

using namespace std;

class TaskNode {
    friend class taskList;

    string taskName;
    bool finished;
    TaskNode *next;
    TaskNode *prev;
public:
    TaskNode(string taskName);


};


#endif //DSA_LAB_04__14TH_OF_SEPTEMBER__2023_TASKNODE_H
