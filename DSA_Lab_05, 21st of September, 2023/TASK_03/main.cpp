#include <iostream>
#include <string>
#include <algorithm>
#include "Stack.h"

using namespace std;
int main() {
    string InputWord;
    cout << "Enter the word: ";
    getline(cin, InputWord);
    cout << InputWord << endl;

    Stack<char> List1;

    for (int i = 0; i < InputWord.size(); ++i) {
        List1.push(InputWord[i]);
    }

    Stack<char> List2;

    while (true) {
        int option = 0;
        cout << "Enter the choice 1). Undo 2) Redo : ";
        cin >> option;
        if (option == 1) {
            if (List1.isEmpty()) {
                cout << "Nothing to undo" << endl;
                continue;
            }
            char temp = List1.pop();
            List2.push(temp);
            List1.print();
        }
        else if (option == 2) {
            if (List2.isEmpty()) {
                cout << "Nothing to redo" << endl;
                continue;
            }
            char temp2 = List2.pop();
            List1.push(temp2);
            List1.print();
        }
        else {
            cout << "Enter a valid option" << endl;
            break;
        }
    }

    return 0;
}
