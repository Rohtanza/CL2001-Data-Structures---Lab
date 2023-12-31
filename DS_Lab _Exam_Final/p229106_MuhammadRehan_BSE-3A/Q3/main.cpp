#include <iostream>
#include <vector>
#include "Moive.h"
#include "MovieTree.h"
#include <limits>

void bubbleSort(std::vector<Moive> &array);

using namespace std;

int main() {

    vector<Moive> list;
    MOVIETREE<int> tree;
    cout << "Menu:" << endl;
    while (true) {
        char option('!');
        cout
                << "1.Add a movie :\n2. Delete a movie\n3. Recommend movies\n4. Display Movies\n5. exit\n:",
                cin >> option;
        switch (option) {
            case '1': {
                string Moviename;
                int ID;
                string Title;
                string Genre;
                int Ratings;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Name:", getline(cin, Moviename);
                cout << "Movie ID:", cin >> ID;
                cout << "Tilted:", getline(cin, Title);
                cout << "Genre:", getline(cin, Genre);
                cout << "Rating :", cin >> Ratings;
                list.push_back(Moive(Moviename, ID, Title, Genre, Ratings));
                tree.insert(ID);
                bubbleSort(list);

            }
                break;
            case '2': {
                int id;
                cout << "Enter Id to remove your moive:", cin >> id;
                int listsize = list.size();
                for (int i = 0; i < listsize; ++i) {
                    if (list[i].getId() == id)
                        list.pop_back();
                }
            }
            case '3': {
                string genre;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter genre to get your favorite movies:", getline(cin, genre);
                int listsize = list.size();
                for (int i = 0; i < listsize; ++i) {
                    if (list[i].getGenre() == genre)
                        cout << list[i].getMovie() << endl;
                }
                cout << endl;
            }
        }
        break;
        if (option == '5') {
            return 0;
        }


    }

    return 0;
}

void bubbleSort(std::vector<Moive> &array) {
    bool swaped;
    do {
        swaped = false;
        for (auto i = 0; i < array.size() - 1; ++i)
            if (array.at(i).getId() > array.at(i + 1).getId()) {
                std::swap(array[i], array[i + 1]);
                swaped = true;
            }
    } while (swaped);
}
