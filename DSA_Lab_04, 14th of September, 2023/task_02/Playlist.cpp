#include <iostream>
#include "Playlist.h"

Playlist::Playlist() : head(nullptr), tail(nullptr), currentSong(nullptr) {

}

void Playlist::addSong(const string &name, int level) {
    SongNode *newNode = new SongNode(name, level);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;  // Make it circular
    } else {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void Playlist::deleteSong(const string &name) {
    if (head == nullptr) {
        cout << "Playlist is empty." << endl;
        return;
    }

    SongNode *temp = head;
    SongNode *prev = nullptr;

    while (temp != tail && temp->songName != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->songName != name) {
        cout << "Song not found." << endl;
        return;
    }

    if (temp == head) {
        head = temp->next;
    }

    if (temp == tail) {
        tail = prev;
    }

    prev->next = temp->next;
    delete temp;
}

void Playlist::searchSong(const string &name) {
    SongNode *temp = head;
    while (temp != nullptr) {
        if (temp->songName == name) {
            cout << "Song name: " << temp->songName << ", Favorite level: " << temp->favoriteLevel << endl;
            return;
        }
        temp = temp->next;
        if (temp == head) {
            break;
        }
    }
    cout << "Song not found." << endl;
}

void Playlist::updateSongName(int position, const string &newName) {
    SongNode *temp = head;
    for (int i = 0; i < position; i++) {
        temp = temp->next;
        if (temp == head) {
            break;
        }
    }
    temp->songName = newName;
}

void Playlist::printPlaylist() {
    if (head == nullptr) {
        cout << "Playlist is empty." << endl;
        return;
    }

    SongNode *temp = head;

    do {
        cout << "Song name: " << temp->songName << ", Favorite level: " << temp->favoriteLevel << endl;
        temp = temp->next;
    } while (temp != head);
}

Playlist::~Playlist() {
    while (head != nullptr) {
        SongNode *temp = head;
        head = head->next;
        delete temp;
    }
}

void Playlist::playNext() {
    if (head == nullptr) {
        cout << "Playlist is empty." << endl;
        return;
    }

    if (currentSong == nullptr) {
        currentSong = head;
    } else {
        currentSong = currentSong->next;
        if (currentSong == head) {
            currentSong = nullptr;
        }
    }

    if (currentSong != nullptr) {
        cout << "Playing song: " << currentSong->songName << endl;
    } else {
        cout << "No more songs to play." << endl;
    }
}
