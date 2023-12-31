#include <iostream>
#include <string>
#include "CirucularLinkedList.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
// Witches names to fill the nodes.
const string Witches[] = {" Luna Lovegood", " Bellatrix Lestrange", "Hermione Granger", "Lily Evans-Potter",
                          "Ginny Weasley"};

int main() {
    srand(time(NULL));
    cout << "Task 01 \"Champion of Potion\"" << endl;
    cout << "                  .\n"
            "\n"
            "                   .\n"
            "         /^\\     .\n"
            "    /\\   \"V\"\n"
            "   /__\\   I      O  o\n"
            "  //..\\\\  I     .\n"
            "  \\].`[/  I\n"
            "  /l\\/j\\  (]    .  O\n"
            " /. ~~ ,\\/I          .\n"
            " \\\\L__j^\\/I       o\n"
            "  \\/--v}  I     o   .\n"
            "  |    |  I   _________\n"
            "  |    |  I c(`       ')o\n"
            "  |    l  I   \\.     ,/\n"
            "_/j  L l\\_!  _//^---^\\\\_        " << endl;


    //Creating a list
    auto *list = new CircularLinkedList<string>();

    // Filling the list
    for (int i = 0; i < 5; ++i) {
        list->insertFirst(Witches[i]);
    }
    // Loop for main menu.
    while (true) {
        char option('0');
        cout << "Enter a choice:\n1. Traverse Wizards one by one.\n2. Start game.\n3. Exit.=>", cin >> option;
        switch (option) {
            case '1': {
                // Showing the first witch
                int i = 0;
                cout << "\t", list->print(0);
                bool check = true;
                while (check) {
                    char option('0');
                    cout << "1. Next.\n2. Go to main menu=>",
                            cin >> option;
                    switch (option) {
                        case '1': {
                            i++;
                            cout << "\t", list->print(i);
                            if (i > 3) {
                                i = 0;
                            };
                            break;
                        }
                        case '2': {
                            check = false;
                            break;
                        }
                        default:
                            cout << "Enter a valid option" << endl;
                            break;
                    }
                }
            }
                break;
            case '2': {
                //removing witches now.
                int j = 5; // a number which will keep decreasing for random number generation.
                // for loop is till 4, so it removes first four witches
                for (int i = 0; i < 4; ++i) {
                    // Generating number and removing
                    int random_number = (rand() % j) + 1;
                    cout << "Random Number : " << random_number << endl;
                    // Deleting at random index.
                    list->deleteIndex(random_number);
                    //Now decreasing the random number parameter.
                    j--;
                }
                // Just printing the witch which is at the end. Left alone.
                cout << "The Winner Witch is :", list->print(0), cout << endl;
            }
                break;
            case '3': {
                // Exiting the Program.
                return 0;
            }
            default:
                cout << "Enter a valid option" << endl;
                break;
        }
    }
}
