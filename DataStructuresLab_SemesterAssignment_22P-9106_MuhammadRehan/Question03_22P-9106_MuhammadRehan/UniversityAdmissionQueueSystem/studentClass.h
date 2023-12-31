//
// Created by rohtanza on 11/29/23.
//

#ifndef UNIVERSITYADMISSIONQUEUESYSTEM_STUDENTCLASS_H
#define UNIVERSITYADMISSIONQUEUESYSTEM_STUDENTCLASS_H

#include<string>

class studentClass {

    std::string studentName;
    double merit;

public:
    studentClass(const std::string &studentName, const double merit) : studentName(studentName), merit(merit) {}

    void display() { std::cout << studentName << " " << merit; }

    const std::string &getStudentName() const { return studentName; }

    double getMerit() const { return merit; }


};


#endif //UNIVERSITYADMISSIONQUEUESYSTEM_STUDENTCLASS_H
