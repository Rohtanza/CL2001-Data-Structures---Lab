//
// Created by rohtanza on 11/30/23.
//

#ifndef ORGANIZATIONALHIERARCHYMANAGEMENT_EMPLOYEE_H
#define ORGANIZATIONALHIERARCHYMANAGEMENT_EMPLOYEE_H

#include <string>

class Employee {
public:
    Employee(const std::string &name, const std::string &title, const std::string &department,
             const std::string &designation, size_t id) : name(name), title(title), department(department),
                                                          designation(designation), ID(id) {}


    size_t ID;
    std::string name;
    std::string title;
    std::string department;
    std::string designation;
};


#endif //ORGANIZATIONALHIERARCHYMANAGEMENT_EMPLOYEE_H
