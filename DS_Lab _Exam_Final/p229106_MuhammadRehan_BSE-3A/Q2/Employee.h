//
// Created by rohtanza on 12/12/23.
//

#ifndef Q2_EMPLOYEE_H
#define Q2_EMPLOYEE_H


using namespace std;

#include <string>

class Employee {
public:
    string name;
    string Id;
    double sales;
    double custerS;
    double ProjectComp;

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Employee::name = name;
    }

    const string &getId() const {
        return Id;
    }

    void setId(const string &id) {
        Id = id;
    }

    double getSales() const {
        return sales;
    }

    void setSales(double sales) {
        Employee::sales = sales;
    }

    double getCusterS() const {
        return custerS;
    }

    void setCusterS(double custerS) {
        Employee::custerS = custerS;
    }

    double getProjectComp() const {
        return ProjectComp;
    }

    void setProjectComp(double projectComp) {
        ProjectComp = projectComp;
    }

public:
    Employee(const string &name, const string &id, double sales, double custerS, double projectComp) : name(name),
                                                                                                       Id(id),
                                                                                                       sales(sales),
                                                                                                       custerS(custerS),
                                                                                                       ProjectComp(
                                                                                                               projectComp) {}
};


#endif //Q2_EMPLOYEE_H
