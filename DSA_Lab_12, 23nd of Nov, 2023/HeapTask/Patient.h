//
// Created by test2023 on 23/11/2023.
//

#ifndef HEAPTASK_PATIENT_H
#define HEAPTASK_PATIENT_H

#include <string>
#include <iostream>

using namespace std;

class Patient {
public:
    string name;
    int urgency;

    Patient(string name, int urgency) : name(name), urgency(urgency) {}

};


#endif //HEAPTASK_PATIENT_H
