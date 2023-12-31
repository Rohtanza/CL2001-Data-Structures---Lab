//
// Created by rohtanza on 11/27/23.
//

#ifndef BOOKSMANAGEMENTSYSTEM_BOOKMANAGEMENTSYSTEM_H
#define BOOKSMANAGEMENTSYSTEM_BOOKMANAGEMENTSYSTEM_H


#include "Book.h"
#include "DoublyLinkedList.h"
#include <string>
#include <iostream>

class BookManagementSystem {
private:
    DoublyLinkedList<Book> bookList;

public:

    void addBook(Book newBook) {
        bookList.insertBook(newBook);
        std::cout << "Book added successfully!\n";

    }

    void addNewBook() {
        std::string isbn, author, title, genre;
        int day, month, year;

        std::cout << "Enter ISBN: ", std::cin >> isbn, std::cin.ignore();
        std::cout << "Enter Author: ", std::getline(std::cin, author);
        std::cout << "Enter Title: ", std::getline(std::cin, title);
        std::cout << "Enter Genre: ", std::getline(std::cin, genre);
        std::cout << "Enter Publication Date (DD MM YYYY): ", std::cin >> day >> month >> year;

        Date publicationDate(day, month, year);
        Book newBook(isbn, author, title, genre, publicationDate);

        bookList.insertBook(newBook);
        std::cout << "Book added successfully!\n";
    }

    void displayBooks() const {
        bookList.displayBooks();
    }

    void recommendRelatedBooks(const std::string &bookTitle) const {
        std::cout << "\nRecommended books based on genre:\n";
        bookList.recommendRelatedBooks(bookTitle);
    }

    void filterBooksByAuthor() const {
        std::string authorName;
        std::cout << "Enter author's name: ";
        std::cin.ignore(), std::getline(std::cin, authorName);

        std::vector<Book> booksByAuthor = bookList.filterByAuthor(authorName);

        if (booksByAuthor.empty()) {
            std::cout << "No books found by author: " << authorName << "\n";
        } else {
            std::cout << "Books by author " << authorName << ":\n";
            for (const auto &book: booksByAuthor) {
                std::cout << "Title: " << book.title << "\n" << "ISBN: " << book.isbn << "\n" << "Genre: " << book.genre
                          << "\n" << "Publication Date: " << book.publicationDate.day << "/"
                          << book.publicationDate.month << "/" << book.publicationDate.year << "\n\n";
            }
        }
    }

    void deleteBook() {
        std::string isbnToDelete;
        std::cout << "Enter ISBN of the book to delete: ", std::cin >> isbnToDelete;
        bookList.deleteBook(isbnToDelete);
    }

    void searchBook() const {
        std::string searchQuery;
        std::cout << "Enter ISBN, title, or author to search: ", std::cin.ignore(), std::getline(std::cin, searchQuery);
        bookList.searchBook(searchQuery);
    }


};


#endif //BOOKSMANAGEMENTSYSTEM_BOOKMANAGEMENTSYSTEM_H
