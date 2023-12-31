//
// Created by Rayhan on 9/8/2023.
//

#include <iostream>
#include "Playlist.h"

Playlist::Playlist() : head(nullptr) {


}

void Playlist::addSong(const string &name, int level) {
    SongNode *newNode = new SongNode(name, level);
    if (level == 1) {
        newNode->next = head;
        head = newNode;
    } else if (level == 2) {
        SongNode *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        SongNode *temp = head;
        for (int i = 0; i < level - 2; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void Playlist::deleteSong(const string &name) {
    SongNode *temp = head;
    SongNode *prev = nullptr;
    while (temp != nullptr && temp->songName != name) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
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
    }
    cout << "Song not found." << endl;

}

void Playlist::updateSongName(int position, const string &newName) {
    SongNode *temp = head;
    for (int i = 0; i < position; i++) {
        temp = temp->next;
    }
    temp->songName = newName;

}

void Playlist::printPlaylist() {
    SongNode *temp = head;
    while (temp != nullptr) {
        cout << "Song name: " << temp->songName << ", Favorite level: " << temp->favoriteLevel << endl;
        temp = temp->next;
    }

}

void Playlist::playSong(int position, const string& newName) {
    SongNode* temp = head;
    int index = 1;
    while(temp != nullptr) {
        if(index == position && temp->songName == newName) {
            cout << newName << ": playing right now" << endl;
            askNextOrPrevious();
            return;
        }
        temp = temp->next;
        index++;
    }
    cout << "Song not found." << endl;
//    if (head != nullptr) {
//        cout << "Playing: " << head->songName << endl;
//        head = head->next;
//    } else {
//        cout << "Playlist is empty." << endl;
    }

}

Playlist::~Playlist() {
    while (head != nullptr) {
        SongNode *temp = head;
        head = head->next;
        delete temp;
    }

}

void Playlist::askNextOrPrevious() {
    char choice;
    cout << "Do you want to play the (N)ext or (P)revious song? ";
    cin >> choice;

    if(toupper(choice) == 'N') {
        if(head->next != nullptr) {
            head = head->next;
            cout << "Playing: " << head->songName << endl;
        } else {
            cout << "You are at the end of the playlist." << endl;
        }
    } else if(toupper(choice) == 'P') {
        cout<<"Ma'am this requires a doubly linked list"<<endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}
