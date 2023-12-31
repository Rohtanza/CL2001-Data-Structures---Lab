#include <iostream>
#include "queueClass.h"
#include <limits>

void Operations(size_t listSize) {
    queueClass<string> *patientList = new queueClass<string>(++listSize);

    while (true) {
        char option('0');
        cout
                << "Enter an option:\n1. Enter a patient in the waiting Queue.\n1. Send Next Patient to the Doctor.\n3. See who's next.\n4. Display all the patients in the queue.\n5. Exit"
                << endl, cin >> option;
        switch (option) {
            case '1': {
                string name;
                cout << "Enter the name of the patient:", cin.ignore(numeric_limits<streamsize>::max(), '\n'), getline(
                        cin, name);
                patientList->Enqueue(name);
                cout << "Patient " << name << " now waiting in the queue." << endl;
            }
                break;
            case '2':
                cout << "Patient " << patientList->Dequeue() << " now with the doctor." << endl;
                break;
            case '3':
                cout << "Patient " << patientList->frontItem() << " is next." << endl;
                break;
            case '4':
                if (!patientList->display()) {
                    cout << "No more Patients" << endl;
                }
                break;
            case '5':
                return;
        }
    }
}

int main() {

    size_t listSize(0);
    cout << "Enter the number of seats in the waiting area:", cin >> listSize;

    Operations(listSize);


    return 0;
}

