#include <iostream>
#include <vector>
#include "Employee.h"
#include "EmployeeHeap.h"
#include <limits>

using namespace std;

int main() {

    vector<Employee> list;
    EmployeeHeap<double> heap;
    cout << "Menu:" << endl;
    while (true) {
        char option('!');
        cout
                << "1. Enter a new Employee:\n2. Get the top Employee\n3. Update the Employee ranking\n4. Display the employee ranking\n5. exit\n:",
                cin >> option;
        switch (option) {
            case '1': {
                string name, id;
                double sales, custerS, ProjectComp;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Name:", getline(cin, name);
                cout << "Id:", getline(cin, id);
                cout << "Sales:", cin >> sales;
                cout << "Customer satisfaction:", cin >> custerS;
                cout << "Project Completion:", cin >> ProjectComp;
                list.push_back(Employee(name, id, sales, custerS, ProjectComp));
                heap.insert(sales + custerS + ProjectComp);
            }
                break;
            case '2': {
                double max = heap.getMax();
                for (int i = 0; i < list.size(); ++i) {
                    double total = list[i].sales + list[i].custerS + list[i].ProjectComp;
                    if (total == max) {
                        cout << "Top:" << endl;
                        cout << "Name: " << list[i].getName() << endl;
                        cout << "ID: " << list[i].getId() << endl;
                        cout << "Sales: " << list[i].getSales() << endl;
                        cout << "Customer satisfaction: " << list[i].getCusterS() << endl;
                        cout << "Project Completion: " << list[i].getProjectComp() << endl;
                    }
                }
            }
                break;
            case '3':{
            }
                break;
            case '4': {
                for (int i = 0; i < list.size(); ++i) {
                    double total = list[i].sales + list[i].custerS + list[i].ProjectComp;
                    cout << "Name: " << list[i].getName() << endl;
                    cout << "ID: " << list[i].getName() << endl;
                    cout << "Sales: " << list[i].getName() << endl;
                    cout << "Customer satisfaction: " << list[i].getName() << endl;
                    cout << "Project Completion: " << list[i].getName() << endl;
                    cout << "Total score: " << total << endl;
                }
                cout << endl << endl;
            }

                break;
            case '5': {
            }
                return 0;

        }

    }

    return 0;
}
