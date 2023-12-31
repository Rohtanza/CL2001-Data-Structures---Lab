#include <iostream>
#include <iomanip>
#include <limits>
#include "BookManagementSystem.h"

/**
 *
 *      22P-9106
 *      Muhammad rehan
 *
 *
 * this Code is written using cpp
 * fany concepts like unique and
 * shared pointers and other few
 * tricks.
 *
 * i have also added a enterDummyData
 * function for you to test this program
 * easily.
 *
 *      Why i didnt use the using namespace std?
 *      Answer:
 *             All these std:: make code look more cool
 *             and complex.
 *
 * */



// This function is added to make your testing easy ma'am.
void enterDummyData(BookManagementSystem &library) {
    std::string isbn1 = "1234567890";
    std::string author1 = "John Doe";
    std::string title1 = "Sample Book 1";
    std::string genre1 = "Fiction";
    Date publicationDate1(2020, 10, 15);
    Book book1(isbn1, author1, title1, genre1, publicationDate1);
    library.addBook(book1);

    std::string isbn2 = "0987654321";
    std::string author2 = "Jane Smith";
    std::string title2 = "Sample Book 2";
    std::string genre2 = "Non-Fiction";
    Date publicationDate2(2019, 5, 20);
    Book book2(isbn2, author2, title2, genre2, publicationDate2);
    library.addBook(book2);


    std::string isbn3 = "1112223334";
    std::string author3 = "Alice Johnson";
    std::string title3 = "Another Book";
    std::string genre3 = "Science Fiction";
    Date publicationDate3(2021, 8, 10);
    Book book3(isbn3, author3, title3, genre3, publicationDate3);
    library.addBook(book3);


    std::string isbn4 = "4445556667";
    std::string author4 = "Robert Brown";
    std::string title4 = "Adventure of Times";
    std::string genre4 = "Adventure";
    Date publicationDate4(2018, 12, 5);
    Book book4(isbn4, author4, title4, genre4, publicationDate4);
    library.addBook(book4);

    std::string isbn5 = "7778889990";
    std::string author5 = "Emily Wilson";
    std::string title5 = "Mystery Mansion";
    std::string genre5 = "Mystery";
    Date publicationDate5(2022, 3, 28);
    Book book5(isbn5, author5, title5, genre5, publicationDate5);
    library.addBook(book5);

    std::string isbn6 = "1231231230";
    std::string author6 = "Mark Turner";
    std::string title6 = "Coding Chronicles";
    std::string genre6 = "Technology";
    Date publicationDate6(2017, 7, 12);
    Book book6(isbn6, author6, title6, genre6, publicationDate6);
    library.addBook(book6);


    std::string isbn7 = "9990001112";
    std::string author7 = "Sarah Adams";
    std::string title7 = "Dreamland Adventures";
    std::string genre7 = "Fantasy";
    Date publicationDate7(2016, 9, 18);
    Book book7(isbn7, author7, title7, genre7, publicationDate7);
    library.addBook(book7);


    std::string isbn8 = "5554443332";
    std::string author8 = "Michael Clark";
    std::string title8 = "Mind Games";
    std::string genre8 = "Psychology";
    Date publicationDate8(2019, 11, 25);
    Book book8(isbn8, author8, title8, genre8, publicationDate8);
    library.addBook(book8);


    std::string isbn9 = "1212121212";
    std::string author9 = "Lucy Green";
    std::string title9 = "Nature's Beauty";
    std::string genre9 = "Nature";
    Date publicationDate9(2020, 6, 9);
    Book book9(isbn9, author9, title9, genre9, publicationDate9);
    library.addBook(book9);

    std::string isbn10 = "1010101010";
    std::string author10 = "Daniel White";
    std::string title10 = "Underwater Exploration";
    std::string genre10 = "Science";
    Date publicationDate10(2021, 2, 17);
    Book book10(isbn10, author10, title10, genre10, publicationDate10);
    library.addBook(book10);

    std::string isbn11 = "9876543210";
    std::string author11 = "Sophie Brown";
    std::string title11 = "The Art of Painting";
    std::string genre11 = "Art";
    Date publicationDate11(2018, 4, 23);
    Book book11(isbn11, author11, title11, genre11, publicationDate11);
    library.addBook(book11);
}

void printHeader(const std::string &title) {
    int width = 60;
    std::cout << std::setw(width) << std::setfill('*') << "\n";
    std::cout << std::setw((width + title.length()) / 2) << std::setfill(' ') << title << "\n";
    std::cout << std::setw(width) << std::setfill('*') << "\n";
}

int main() {
    BookManagementSystem library;
    int choice;
    while (true) {
        printHeader("Library Management System");
        std::cout
                << "\nMenu:\n1. Add a New Book\n2. Search for a Book\n3. Display Books\n4. Filter Books by Author\n5. Recommend Related Books\n6. Delete a Book\n9. Exit\n0. Enter dummy data.\nEnter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                library.addNewBook();
                break;
            case 2:
                library.searchBook();
                break;
            case 3:
                library.displayBooks();
                break;
            case 4:
                library.filterBooksByAuthor();
                break;
            case 5: {
                std::string bookTitle;
                std::cout << "Enter a book title to get recommendations: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear newline from previous input
                std::getline(std::cin, bookTitle);
                library.recommendRelatedBooks(bookTitle);
            }
                break;
            case 6:
                library.deleteBook();
                break;
            case 9:
                return 0;
            case 0:
                enterDummyData(library);
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        };

    }
}