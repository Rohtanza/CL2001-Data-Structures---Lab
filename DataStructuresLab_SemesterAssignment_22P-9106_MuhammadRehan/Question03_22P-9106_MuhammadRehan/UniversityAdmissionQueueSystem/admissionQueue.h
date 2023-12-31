//
// Created by rohtanza on 11/29/23.
//
//



#ifndef UNIVERSITYADMISSIONQUEUESYSTEM_ADMISSIONQUEUE_H
#define UNIVERSITYADMISSIONQUEUESYSTEM_ADMISSIONQUEUE_H

#include <memory>
#include <iostream>
#include "studentClass.h"

class admissionQueue {

    class Node {
    public:
        // Using unique to look cool.
        std::unique_ptr<Node> next;
        studentClass student;


        explicit Node(const std::string &name, double merit) : student(name, merit) {}

        [[nodiscard]] std::string getName() const { return student.getStudentName(); };

        [[nodiscard]] double getMerit() const { return student.getMerit(); };


    };

    std::unique_ptr<Node> Front;
    Node *End;
    size_t size;

public:
    explicit admissionQueue(int size = 0) : size(size), Front(nullptr), End(nullptr) {}

    bool isEmpty() { return Front == nullptr; }

    studentClass frontStudent() {
        if (isEmpty())
            throw std::underflow_error("No One is in the line for admission.");
        return Front->student;
    }

    void Enqueue(const std::string &name, double merit) {
        Node *node = new Node(name, merit);
        if (End == nullptr)
            Front.reset(node), End = node;
        else
            End->next.reset(node), End = node;
        size++;
    }

    studentClass Dequeue() {
        if (isEmpty()) { throw std::underflow_error("UnderFlow"); }
        studentClass removed = Front->student;
        Front = move(Front->next);
        if (Front == nullptr)
            End = nullptr;
        size--;
        return removed;
    }

    bool display() {
        if (isEmpty()) { return false; }
        Node *temp = Front.get();
        while (temp != nullptr) {
            temp->student.display(), std::cout << " -> ";
            temp = temp->next.get();
        }
        std::cout << "End";
        return true;
    }

    size_t &getSize() { return size; }


};

#endif //UNIVERSITYADMISSIONQUEUESYSTEM_ADMISSIONQUEUE_H
