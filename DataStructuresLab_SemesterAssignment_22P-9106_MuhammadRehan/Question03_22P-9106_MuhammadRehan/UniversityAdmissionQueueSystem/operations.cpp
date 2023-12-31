//
// Created by rohtanza on 11/29/23.
//
// Few values i will use in the code.
#define LINES 3
#define MERIT 50

#include <vector>
#include "admissionQueue.h"
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// This function is just giving the shortest queue to send student to .
int smallest(int x, int y, int z) {
    // If all the queues has same size then send student into random line.
    if (x == y && y == z) return rand() % 3;
    else if (x <= y && x <= z) return 0;
    else if (y <= x && y <= z) return 1;
    else return 2;
}

// MENU function to operate the program
int Menu(std::vector<admissionQueue *> &officers) {
    char option('!');
    while (true) {
        std::cout
                << "Enter the option:\n0. For entering dummies values so you dont have to \n1. Add a Student in the Queue\n2. Process Admissions\n3. Check Queue Status\n4. See who is next\n5. Exit\n=> ",
                std::cin >> option;
        switch (option) {
            // Created this for your ease to test the program.
            case '0': {
                std::string Names[] = {"Ali", "Aisha", "Abdullah", "Zainab", "Hasan", "Aisha", "Omar", "Fariba",
                                       "Ibrahim", "Ismail"};
                double Merits[] = {55, 60, 70, 80, 90, 45, 30, 20, 10, 5};
                for (int i = 0; i < 9; ++i)
                    officers[smallest(officers[0]->getSize(), officers[1]->getSize(), officers[2]->getSize())]->Enqueue(
                            Names[i], Merits[i]);
            }
                break;
                // If you want to entry the values yourself.
            case '1': {
                std::string name;
                double merit;
                // Cleaning the buffer.
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter name:", getline(std::cin, name);
                std::cout << "Enter merit:", std::cin >> merit;
                officers[smallest(officers[0]->getSize(), officers[1]->getSize(), officers[2]->getSize())]->Enqueue(
                        name, merit);
            }
                break;
            case '2': {
                // First created an array to store my sizes
                size_t sizes[LINES];
                //Get sizes from the lines.
                for (int i = 0; i < LINES; ++i)
                    sizes[i] = officers[i]->getSize();
                // Now an array store the indices of the line as per ascending order to process these.
                int indices[LINES] = {0, 1, 2};
                // A cool trick to sort the indices array as per the order
                std::sort(indices, indices + LINES, [&](int a, int b) {
                    return sizes[a] < sizes[b];
                });
                // Now process each line one by one. from shortest to the longest one.
                for (int i = 0; i < LINES; ++i) {
                    for (int j = 0; j < sizes[indices[i]]; ++j) {
                        if (officers[indices[i]]->frontStudent().getMerit() > MERIT)
                            std::cout << "Student " << officers[indices[i]]->frontStudent().getStudentName()
                                      << " has been given admission." << std::endl;
                        else
                            std::cout << "Student " << officers[indices[i]]->frontStudent().getStudentName()
                                      << " has low merit of " << officers[indices[i]]->frontStudent().getMerit()
                                      << std::endl;
                        officers[indices[i]]->Dequeue();
                    }
                }

            }
                break;
            case '3': {
                // If the office is empty.
                if (officers[0]->getSize() == 0 && officers[0]->getSize() == 0 && officers[0]->getSize() == 0) {
                    std::cout << "No one is at admission office." << std::endl;
                    break;
                }
                for (auto officer = 0; officer < LINES; ++officer) {
                    if (officers[officer]->getSize() != 0)
                        officers[officer]->display(), std::cout << std::endl;
                    else // just in case line is empty.
                        std::cout << "Queue no." << officer + 1 << " is empty." << std::endl;
                }
            }
                break;
            case '4': {
                char option('!');
                std::cout << "Enter Queue Number:", std::cin >> option;
                if (option == '1' || option == '2' | option == '3') {
                    int opt = option - '0';
                    std::cout << "Student " << officers[(opt - 1)]->frontStudent().getStudentName()
                              << " with merit of " << officers[opt - 1]->frontStudent().getMerit()
                              << std::endl;
                } else
                    std::cout << "Enter a valid queue number" << std::endl;
            }
                break;
            case '5':
                return 0;
            default: // Wrong value will call the menu function again.
                return 1;
        }

    }

}


void operation() {
    // A vector to store my queues.
    std::vector<admissionQueue *> officers;
    for (int i = 0; i < LINES; ++i) // Adding lines in my vector
        officers.push_back(new admissionQueue(0));
    while (Menu(officers));

    // Deleting my dynamical allocated lines
    for (auto officer: officers)
        delete officer;


}
