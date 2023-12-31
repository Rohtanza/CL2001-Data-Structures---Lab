#include <iostream>
#include "queueLinkedList.h"
#include <limits>

int attractionOption(string name) {
    int option(0);
    while (true) {
        cout << "Which attraction's ticket " << name
             << " wants \n1. Roller Coaster\n2. Motion Ride\n 3. Round Wheel\n ",
                cin >> option;
        if (option == 1 || option == 2 || option == 3)
            return option;
        else
            cout << "Enter valid attraction\n";
    }
}

void Operations() {
    auto *ticketQ = new queueLinkedList<string>();
    auto *RollerCoasterQ = new queueLinkedList<string>();
    auto *RoundWheelQ = new queueLinkedList<string>();
    auto *MotionRideQ = new queueLinkedList<string>();

    while (true) {
        int option(0);
        cout
                << " Enter your choice:\n1. Enter a visitor in the tickets purchase queue.\n2. Sell a ticket\n3. Process all queues.\n",
                cin >> option;

        if (option == 1) {
            string name;
            cout << "Enter the name of the visitor:", cin.ignore(numeric_limits<streamsize>::max(), '\n'), getline(cin,
                                                                                                                   name);
            ticketQ->Enqueue(name);
        } else if (option == 2) {
            cout << "Now selling ticket to " << ticketQ->frontItem() << endl;
            int option = attractionOption(ticketQ->frontItem());
            if (option == -1) {
                cout << "Enter valid attraction\n";
                continue;
            } else {
                switch (option) {
                    case 1: {
                        cout << "Roller Coaster ticket sold to " << ticketQ->frontItem() << endl;
                        RollerCoasterQ->Enqueue(ticketQ->Dequeue());
                    }
                        break;
                    case 2: {
                        cout << "Motion Ride ticket sold to " << ticketQ->frontItem() << endl;
                        MotionRideQ->Enqueue(ticketQ->Dequeue());
                    }
                        break;
                    case 3: {
                        cout << "Round Wheel ticket sold to " << ticketQ->frontItem() << endl;
                        RoundWheelQ->Enqueue(ticketQ->Dequeue());
                    }
                        break;
                }
            }
        } else if (option == 3) {
            if (!RollerCoasterQ->isEmpty()) {
                string name;
                while ((name = RollerCoasterQ->Dequeue()) != "-1") {
                    cout << "Visitor " << name << " now enjoying at the attraction roller coaster\n";
                }
            } else {
                cout << "Roller Coaster queue is empty.\n";
            }
            if (!RoundWheelQ->isEmpty()) {
                string name;
                while ((name = RoundWheelQ->Dequeue()) != "-1") {
                    cout << "Visitor " << name << " now enjoying at the attraction roller Wheel\n";
                }
            } else {
                cout << "Roller Wheel queue is empty.\n";
            }
            if (!MotionRideQ->isEmpty()) {
                string name;
                while ((name = MotionRideQ->Dequeue()) != "-1") {
                    cout << "Visitor " << name << " now enjoying at the attraction Motion Ride\n";
                }
            } else {
                cout << "Motion Ride queue is empty.\n";
            }
        } else {
            cout << "Enter valid option\n";
        }
    }
    delete ticketQ;
    delete RollerCoasterQ;
    delete RoundWheelQ;
    delete MotionRideQ;
}

int main() {
    Operations();
    return 0;
}
