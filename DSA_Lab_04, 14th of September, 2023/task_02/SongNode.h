//
// Created by Rayhan on 9/8/2023.
//

#ifndef DSA_LAB_01__8TH_OF_SEPTEMBER__2023_SONGNODE_H
#define DSA_LAB_01__8TH_OF_SEPTEMBER__2023_SONGNODE_H

#include <string>

using namespace std;


class SongNode {


public:
    string songName;
    int favoriteLevel;
    SongNode* next;
    SongNode(string name, int level);

};


#endif //DSA_LAB_01__8TH_OF_SEPTEMBER__2023_SONGNODE_H
