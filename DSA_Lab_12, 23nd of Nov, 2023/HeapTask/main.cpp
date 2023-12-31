#include "Heap.h"
#include <limits>

int main() {
    Heap priorityQueue;
    while (true) {
        char option('0');
        cout
                << "1. Enter a Patient\n2. Send a Patient to the Doc\n3. Display the Patient Queue\n4. Update Urgency\n5. Exit\n=> ",
                cin >> option;
        switch (option) {
            case '1': {
                string name;
                int urgency;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter name:", getline(cin, name);
                cout << "Enter the urgency:", cin >> urgency;
                priorityQueue.insert(Patient(name, urgency));
            }
                break;
            case '2': {
                cout << "Sending next patient to the doctor." << endl;
                priorityQueue.del();
            }
                break;
            case '3': {
                priorityQueue.display();
            }
                break;
            case '4': {
                string name;
                int urgency;
                cout << "Enter the patient's name whose urgency level needs to be updated:", cin >> name;
                cout << "Enter the new urgency level:", cin >> urgency;
                priorityQueue.updateUrgency(name, urgency);
            }
                break;
            case '5':
                return 0;
        }

    }
}