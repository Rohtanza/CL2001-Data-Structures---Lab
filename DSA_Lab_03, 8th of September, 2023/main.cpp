#include <iostream>
#include "Playlist.h"

int main() {
    Playlist playlist;
    int option;
    string name;
    int level;
    do {
        cout
                << "1. Add a Song\n2. Delete a Song\n3. Search for a Song\n4. Update a song name\n5. Print Playlist\n6. Play Song\n7. Exit\n";
        cin >> option;
        switch (option) {
            case 1:
                cout << "Enter song name: ";
                cin >> name;
                cout << "Enter favorite level: ";
                cin >> level;
                playlist.addSong(name, level);
                break;
            case 2:
                cout << "Enter song name to delete: ";
                cin >> name;
                playlist.deleteSong(name);
                break;
            case 3:
                cout << "Enter song name to search: ";
                cin >> name;
                playlist.searchSong(name);
                break;
            case 4:
                int position;
                cout << "Enter song position to update: ";
                cin >> position;
                cout << "Enter new song name: ";
                cin >> name;
                playlist.updateSongName(position, name);
                break;
            case 5:
                playlist.printPlaylist();
                break;
            case 6:
                int pos;
                cout << "Enter song position to play: ";
                cin >> pos;
                cout << "Enter song name: ";
                cin >> name;

                playlist.playSong(pos, name);
                break;
            case 7:
                exit(0);
        }
    } while (true);
    return 0;


}