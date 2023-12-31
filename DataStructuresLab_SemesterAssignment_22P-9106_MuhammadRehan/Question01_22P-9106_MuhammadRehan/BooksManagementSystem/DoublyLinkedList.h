#ifndef BOOKSMANAGEMENTSYSTEM_DOUBLYLINKEDLIST_H
#define BOOKSMANAGEMENTSYSTEM_DOUBLYLINKEDLIST_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Book.h"


template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> prev;
        std::shared_ptr<Node> next;

        explicit Node(const T &value) : data(value), prev(nullptr), next(nullptr) {}
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    size_t size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insertBook(const T &value) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            std::shared_ptr<Node> current = head;
            while (current && current->data.publicationDate.year > value.publicationDate.year) {
                current = current->next;
            }
            if (!current) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else if (current == head) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
        ++size;
    }


    void deleteBook(const std::string &isbn) {
        std::shared_ptr<Node> current = head;
        while (current) {
            if (current->data.isbn == isbn) {
                if (current == head && current == tail) {
                    head = tail = nullptr;
                } else if (current == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                --size;
                return;
            }
            current = current->next;
        }
        std::cout << "Book with ISBN " << isbn << " not found.\n";
    }

    void displayBooks() const {
        std::shared_ptr<Node> current = head;
        while (current) {
            std::cout << "ISBN: " << current->data.isbn << "\n" << "Title: " << current->data.title << "\n"
                      << "Author: " << current->data.author << "\n" << "Genre: " << current->data.genre << "\n"
                      << "Publication Date: " << current->data.publicationDate.day << "/"
                      << current->data.publicationDate.month << "/" << current->data.publicationDate.year << "\n\n";
            current = current->next;
        }
    }

    std::vector<Book> filterByAuthor(const std::string &authorName) const {
        std::vector<Book> filteredBooks;
        std::shared_ptr<Node> current = head;
        while (current) {
            if (current->data.author == authorName) {
                filteredBooks.push_back(current->data);
            }
            current = current->next;
        }
        return filteredBooks;
    }

    void searchBook(const std::string &searchTerm) const {
        std::shared_ptr<Node> current = head;
        bool found = false;

        while (current) {
            if (current->data.isbn == searchTerm || current->data.title == searchTerm ||
                current->data.author == searchTerm) {
                std::cout << "Book found:\n";
                std::cout << "ISBN: " << current->data.isbn << "\n" << "Title: " << current->data.title << "\n"
                          << "Author: " << current->data.author << "\n" << "Genre: " << current->data.genre << "\n"
                          << "Publication Date: " << current->data.publicationDate.day << "/"
                          << current->data.publicationDate.month << "/" << current->data.publicationDate.year << "\n\n";
                found = true;
            }
            current = current->next;
        }

        if (!found) {
            std::cout << "Book not found.\n";
        }
    }

    void recommendRelatedBooks(const std::string &bookTitle) const {
        std::shared_ptr<Node> current = head;
        std::vector<Book> relatedBooks;
        while (current && relatedBooks.size() < 3) {
            if (current->data.title == bookTitle) {
                const std::string genre = current->data.genre;
                std::shared_ptr<Node> temp = head;
                while (temp) {
                    if (temp->data.title != bookTitle && temp->data.genre == genre) {
                        relatedBooks.push_back(temp->data);
                    }
                    temp = temp->next;
                }
                break;
            }
            current = current->next;
        }

        if (relatedBooks.empty()) {
            std::cout << "No related books found.\n";
        } else {
            std::cout << "Related books:\n";
            for (const auto &book: relatedBooks) {
                std::cout << "Title: " << book.title << "\n" << "Author: " << book.author << "\n" << "Genre: "
                          << book.genre << "\n" << "Publication Date: " << book.publicationDate.day << "/"
                          << book.publicationDate.month << "/" << book.publicationDate.year << "\n\n";
            }
        }
    }
};


#endif //BOOKSMANAGEMENTSYSTEM_DOUBLYLINKEDLIST_H
