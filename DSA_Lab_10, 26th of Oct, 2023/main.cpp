#include <iostream>
#include "BST.h"

#define size 7
using namespace std;
vector<string> gemNames = {"Diamond", "Ruby", "Sapphire", "Pearl", "Opal", "Garnet", "Zircon", "Jade"};
vector<size_t> power = {50, 30, 70, 40, 10, 60, 20, 5};

void displayGems(BST<int> *gems) {
    while (true) {
        char option('0');
        cout << "\nWhich traversal do you want\n1. Pre-order\n2. In-order\n3. Post-order\n4. Exit\n=>", cin >> option;
        switch (option) {
            case '1':
                gems->preOrder();
                break;
            case '2':
                gems->inOrder();
                break;
            case '3':
                gems->postOrder();
                break;
            case '4':
                return;
            default:
                cout << "Enter valid option" << endl;
                break;
        }
    }

}

void operations(BST<int> *gems, size_t magicalPower) {
    int powerPlucked(0), totalPower(0);
    while (true) {
        char option('0');
        cout
                << "Select an option:\n1. Display the magical tree\n2. Search for a gem by its power\n3. Find the gem with the highest power\n4. Pluck a gem from the tree\n5. Exit\n=>",
                cin >> option;
        switch (option) {
            case '1':
                displayGems(gems);
                break;
            case '2': {
                int power;
                cout << "Enter the power to find a gem :", cin >> power;
                cout << gems->searchNode(power) << endl;
            }
                break;
            case '3':
                cout << gems->findMax() << endl;
                break;
            case '4': {
                int power(0);
                cout << "Magical tree : ", gems->inOrder(), cout << endl;
                cout << "which gem to pluck ? Enter the power :", cin >> power;
                powerPlucked = gems->deleteGem(power);
                totalPower += powerPlucked;
                cout << "You plucked: " << powerPlucked << endl;
                cout << "Power in the bag: " << totalPower << endl;
                if (totalPower == magicalPower) {
                    cout << "You won! Now take your bag and run from the forest" << endl;
                    return;
                }
                if (totalPower > magicalPower) {
                    cout << "You lost! You bag burst. Now run a save yourself from the witch" << endl;
                    return;
                }
            }
                break;
            case '5':
                return;
        }
    }


}


int main() {

    size_t magicalPower(0);
    cout << "How much magical power can your bag hold: ", cin >> magicalPower;

    BST<int> gems;
    for (const auto &power_gem: power) {
        auto gem_name_iter = gemNames.begin() + (&power_gem - &power.front());
        gems.insertGem(power_gem, *gem_name_iter);
    }
    operations(&gems, magicalPower);


    return 0;
}
