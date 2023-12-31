#include<iostream>
#include <vector>
#include "PlacesQueue.h"
#include "GhostStack.h"
#include <limits>
//cin.ignore(numeric_limits<streamsize>::max(), '\n')

#define PlacesSize 6

using namespace std;
const vector<string> MansionPlaces = {"The Gateway to Darkness", "The Creeping Corridor", "The Abandoned Lounge",
                                      "The Haunted Gallery", "The Shadowed Library", "The Broken Window"};

int main() {

    PlacesQueue<string> places;
    GhostStack ghosts;
    for (auto place: MansionPlaces)
        places.Enqueue(place);

    // Testing if we got the places in our queue.
    cout << "Places:" << endl;

    places.display();

    cout << endl << endl << endl;
    //_______________
    char choice('!');
    cout << "Start exploring the mansion? \n1. Yes\n2. No\n=>", cin >> choice;

    if (choice == '2')
        return EXIT_SUCCESS;
    else
        cout << "Starting the Game...." << endl;


    while (!places.isEmpty()) {

        char option('!');

        cout << "Currently at : " << places.Dequeue() << endl;

        while (true) {
            cout << "Did you Encountered a ghost or a evil spirit? \n1. Yes\n2. No\n=>", cin >> option;

            if (option == '1') {
                string ghostName;
                cout << "What did you see:";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, ghostName);
                ghosts.push(ghostName);
                break;

            } else if (option == '2') {
                ghosts.push("-1");
                break;
            } else
                cout << "enter a valid option " << endl;
        }


    }

    cout << "Yay, you escaped and you are safe and sound!\nMost recent Ghosts and Evil Spirits Encounter:"
         << endl;
    cout << "ghosts:" << endl;
    ghosts.print();

    /*
     * Storing the result in a vector so we could use it again
     * , if we direct pop, we will use the ghosts and all.
     * a good programming practice.
     * */
    vector<string> result;
    for (int i = 0; i < PlacesSize; ++i) {
        result.push_back(ghosts.pop());
    }

    int j(5);
    for (int i = 0; i < PlacesSize; ++i) {

        if (!(result[i] == "-1"))
            cout << "Encountered :" << result[i] << " at :" << MansionPlaces[j] << std::endl;
        j--;

    }

    return EXIT_SUCCESS;

}

