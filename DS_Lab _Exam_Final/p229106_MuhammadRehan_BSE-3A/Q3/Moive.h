//
// Created by rohtanza on 12/12/23.
//

#ifndef Q3_MOIVE_H
#define Q3_MOIVE_H

#include <string>

using namespace std;

class Moive {
    string Movie;
    int ID;
    string Title;
    string Genre;
    int Ratings;

public:
    Moive(const string &movie, int id, const string &title, const string &genre, int ratings) : Movie(movie), ID(id),
                                                                                                Title(title),
                                                                                                Genre(genre),
                                                                                                Ratings(ratings) {}
};


#endif //Q3_MOIVE_H
