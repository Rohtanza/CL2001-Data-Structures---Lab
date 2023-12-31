//
// Created by rohtanza on 11/27/23.
//

#ifndef BOOKSMANAGEMENTSYSTEM_BOOK_H
#define BOOKSMANAGEMENTSYSTEM_BOOK_H

#include <string>
#include "Date.h"

class Book {
public:
    std::string isbn;
    std::string author;
    std::string title;
    std::string genre;
    Date publicationDate;

    Book(const std::string &isbn, const std::string &author, const std::string &title, const std::string &genre,
         const Date &publicationDate)
            : isbn(isbn), author(author), title(title), genre(genre), publicationDate(publicationDate) {}

};


#endif //BOOKSMANAGEMENTSYSTEM_BOOK_H
