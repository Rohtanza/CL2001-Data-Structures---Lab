#include <iostream>
#include <limits>
#include "taskList.h"

using namespace std;

int main() {
    taskList list;
    while (true) {
        char option;
        cout
                << "Enter:\n\t1.Enter 1 to add.\n\t2.Enter 2 to mask task\n\t3.Enter 3 to remove marked tasks\n\t4.Enter 4 to print tasks:\n\t5.Enter 5 to exit the code\n\t=>";
        cin >> option;
        switch (option) {
            case '1': {
                string name;
                int pos;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter task: ";
                getline(cin, name);
                cout << "Enter pos: ";
                cin >> pos;
                list.addTask(name, pos);
            }
                break;

            case '2': {
                int pos;
                cout << "Enter pos: ";
                cin >> pos;
                list.markTask(pos);
            }
                break;
            case '3': {
                list.removeTask();
            }
                break;
            case '4': {
                bool reverseOrder = false;
                int option;
                cout << "Do you want to print in reverse 1(Yes), 0(No)", cin >> option;
                if (option == 1) {
                    reverseOrder = true;
                }
                list.displayTasks(reverseOrder);
                break;
            }
            case '5': {
                exit(0);
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
