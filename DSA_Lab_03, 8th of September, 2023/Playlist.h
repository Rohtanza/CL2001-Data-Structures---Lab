//
// Created by Rayhan on 9/8/2023.
//

#ifndef DSA_LAB_01__8TH_OF_SEPTEMBER__2023_PLAYLIST_H
#define DSA_LAB_01__8TH_OF_SEPTEMBER__2023_PLAYLIST_H


#include "SongNode.h"

class Playlist {

    SongNode* head;

public:
    Playlist();
    void addSong(const string &name, int level);
    void deleteSong(const string& name);
    void searchSong(const string& name);
    void updateSongName(int position, const string& newName);
    void printPlaylist();
    void playSong(int position, const string& newName);
    void askNextOrPrevious();
    ~Playlist();

};


#endif //DSA_LAB_01__8TH_OF_SEPTEMBER__2023_PLAYLIST_H
