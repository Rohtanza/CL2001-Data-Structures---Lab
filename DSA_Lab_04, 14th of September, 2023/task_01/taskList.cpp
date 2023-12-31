#include "taskList.h"
#include <iostream>
#include <limits>

using namespace std;

taskList::~taskList() {
    TaskNode *curr = head;
    while (head != nullptr) {
        head = head->next;
        delete curr;
        curr = head;
    }
}

taskList::taskList() : head(nullptr), length(0) {}

void taskList::addTask(const string &name, int pos) {
    TaskNode *n = new TaskNode(name);
    if (pos < 1) {
        cout << "Pos is Invalid\n";
        return;
    }
    if (pos == 1) {
        n->next = head;
        if (head != nullptr)
            head->prev = n;
        head = n;
        cout << "created\n";
    } else {
        if(pos < 1 || pos > length+1)
        {
            cout<<"Pos is invalid\n";
            return;
        }
        TaskNode *curr = head;
        for (int i = 1; i < pos - 1; ++i) {
            curr = curr->next;
        }
        n->prev = curr;
        n->next = curr->next;
        if (curr->next != nullptr)
            curr->next->prev = n;
        curr->next = n;

    }
    length++;
    cout << "length :" << length << endl;
}

void taskList::markTask(int pos) {
    TaskNode *curr = head;
    for (int i = 0; i < pos; ++i) {
        curr = curr->next;
    }
    curr->finished = true;
}

void taskList::removeTask() {
    TaskNode *curr = head;
    size_t count = 0;
    while (count < length) {
        if (curr->finished == true) {
            TaskNode *temp = curr;
            curr = curr->next;
            if (temp == head) {
                head = head->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            } else {
                temp->prev->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                }
            }
            delete temp;
            length--;
        } else {
            curr = curr->next;
        }
        count++;
    }
}

void taskList::displayTasks(bool reverseOrder) {
    TaskNode* curr;
    if (reverseOrder) {
        curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        while (curr != nullptr) {
            cout << "Task: " << curr->taskName << ", Completed: " << (curr->finished ? "Yes" : "No") << endl;
            curr = curr->prev;
        }
    } else {
        curr = head;
        while (curr != nullptr) {
            cout << "Task: " << curr->taskName << ", Completed: " << (curr->finished ? "Yes" : "No") << endl;
            curr = curr->next;
        }
    }
}
