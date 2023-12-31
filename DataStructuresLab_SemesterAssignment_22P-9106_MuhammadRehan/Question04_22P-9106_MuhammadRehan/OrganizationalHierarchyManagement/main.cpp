#include <iostream>
#include <limits>
#include "hierarchyTree.h"
/**
 *  22P-9106 Muhammad Rehan.
 *
 *
 * Disclaimer:
 *      this code is LAB task 9 AVL code modified,
 *      as i don't have that much confidence of
 *      writing AVL code, so i kept it simple, no
 *      unique pointer or any other fancy coding
 *      tricks
 *
 * */


using namespace std;

int main() {
    AVL organizationalTree;
    while (true) {
        char choice('!');
        cout
                << "Organizational Hierarchy Management\n1. Add Employee\n2. Search for Employee\n3. Generate Organizational Chart\n4. Modify Employee Information\n5. Remove Employee\n6. Exit\nEnter option: "
                << endl, cin >> choice;

        switch (choice) {
            case '1': {
                int id;
                string name, designation;
                cout << "Enter ID: ", cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Name: ", getline(cin, name);
                cout << "Enter Designation: ", getline(cin, designation);
                organizationalTree.insertEmployee(Employee(id, name, designation));
                break;
            }
            case '2': {
                int searchId;
                cout << "Enter Employee ID to search: ", cin >> searchId;
                Employee *found = organizationalTree.searchEmployee(searchId);
                if (found) {
                    cout << "Employee Found:" << endl;
                    cout << "ID: " << found->ID << ", Name: " << found->name << ", Designation: "
                         << found->designation << endl;
                } else {
                    cout << "Employee not found." << endl;
                }
                break;
            }
            case '3':
                cout << "Generating Organizational Chart..." << endl;
                organizationalTree.displayTree();
                // 2nd way to display tree, but it doesn't form at tree.
//                organizationalTree.displayOrganizationalChart();
                break;
            case '4': {
                int updateId;
                string newName, newDesignation;
                cout << "Enter ID of employee to update: ", cin >> updateId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter New Name: ", getline(cin, newName);
                cout << "Enter New Designation: ", getline(cin, newDesignation);
                organizationalTree.updateEmployee(updateId, newName, newDesignation);
                break;
            }
            case '5': {
                int removeId;
                cout << "Enter ID of employee to remove: ", cin >> removeId;
                organizationalTree.removeEmployee(removeId);
                break;
            }
            case '6':
                cout << "Exiting" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}
