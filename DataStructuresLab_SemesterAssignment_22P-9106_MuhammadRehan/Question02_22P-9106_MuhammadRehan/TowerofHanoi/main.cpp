#include <iostream>
#include <cmath>
#include <vector>
#include "Stack.h"

/*
 *  22P-9106 Muhammad Rehan
 *
 *      Ma'am You asked to do a dry run on paper,
 *      did that, but as an extra step, this program
 *      shows its step (doing dry run) throughout
 *      the program. it shows,
 *
 *            1. Each step
 *            2. Disk Movement
 *            3. Rod with disk on it
 *            4. A Full Visual Display
 *
 *
 * */




using namespace std;
//  I need to access these to many places.
vector<Stack> Rods;
size_t steps = 0;

void print_scene() {
    for (size_t i = 0; i < 3; i++) {
        Rods[i].print();
        cout << endl << endl;
    }
    //Printing our step.
    cout << "----------------" << endl
         << "    Step    " << steps << endl
         << "----------------" << endl
         << endl;
}

// Move from one rod to another rod.
void actualMovement(int from, int to) {
    Node *moved = new Node(Rods[from].peek()->data);
    Rods[from].pop();
    Rods[to].push(moved);
    cout << "Move from" << Rods[from].getTag() << " to " << Rods[to].getTag() << endl << endl;
}

// Move the disks
void moveDisk(int from, int to) {

    if (Rods[to].getSize() == 0 && Rods[from].getSize() != 0)
        actualMovement(from, to);

    else if (Rods[from].getSize() == 0 && Rods[to].getSize() != 0)
        actualMovement(to, from);

    else if (Rods[to].peek()->data->Length > Rods[from].peek()->data->Length)
        actualMovement(from, to);

    else if (Rods[from].peek()->data->Length > Rods[to].peek()->data->Length)
        actualMovement(to, from);
}

//Function to do the moving
void towerofHanoi(int node, int from, int to, int aux) {
    steps++;
    if (node % 2 == 0)
        swap(to, aux);
    for (; steps <= (pow(2, node) - 1); steps++) {
        if (steps % 3 == 1) {
            moveDisk(from, to);
        } else if (steps % 3 == 2) {
            moveDisk(from, aux);
        } else if (steps % 3 == 0) {
            moveDisk(aux, to);
        }
        print_scene();
    }
}

int main() {
    Rods.push_back(Stack(" A"));
    Rods.push_back(Stack(" B"));
    Rods.push_back(Stack(" C"));
    size_t disk;
    cout << "Enter the Disk count:", cin >> disk;
    for (size_t i = disk; i >= 1; i--)
        Rods[0].push(new Node(new Disk(i)));
    print_scene();
    towerofHanoi(disk, 0, 2, 1);
    return 0;
}