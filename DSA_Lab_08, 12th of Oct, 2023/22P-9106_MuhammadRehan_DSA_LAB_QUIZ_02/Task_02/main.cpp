#include <iostream>
#include "Stack.h"
#include <limits>

using namespace std;

int main() {

    auto *path = new Stack<string>;
    cout << "Welcome to the cave" << endl;
    while (true) {

        char option('0');
        cout
                << "Enter a choice:\n1. Go forward in the cave.\n2. Go back.\n3. Run from the cave.\n4. Display the path\n=>",
                cin >> option;
        switch (option) {
            case '1': {
                string loc;
                cout << "Enter the name of your current location:", cin.ignore(numeric_limits<streamsize>::max(),'\n'), getline(cin, loc);
                path->push(loc);
            }
                break;
            case '2': {
                path->pop();
                optional<string> top = path->topElement();
                if (top) {
                    cout << "You are at loc : " << top.value() << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
            }
                break;
            case '3': {

                while (path->sizeStack() != 0) {
                    cout << "You are at loc : " << path->pop() << endl;
                }

            }
                break;
            case '4': {
                path->display();
            }
                break;
            default:
                cout << "Enter a valid option" << endl;
                break;
        }

    }


    return 0;
}
