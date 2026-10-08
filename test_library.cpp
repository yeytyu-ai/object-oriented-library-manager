#include "library_manager.h"
#include <cassert>
#include <iostream>

using namespace std;

void testAddBook() {
    Library library;

    Book book(101, "C++ Programming",
              "Bjarne Stroustrup",
              "Programming", 2013);

    library.addBook(book);

    cout << "testAddBook: PASS" << endl;
}

void testBookDetails() {
    Book book(102, "Data Structures",
              "Mark Allen Weiss",
              "Computer Science", 2014);

    assert(book.getId() == 102);
    assert(book.getTitle() == "Data Structures");
    assert(book.getAuthor() == "Mark Allen Weiss");
    assert(book.getCategory() == "Computer Science");
    assert(book.getYear() == 2014);

    cout << "testBookDetails: PASS" << endl;
}

void testBorrowAndReturn() {
    Book book(103, "Digital Electronics",
              "Morris Mano",
              "Electronics", 2017);

    assert(book.isAvailable());

    book.borrowBook();
    assert(!book.isAvailable());

    book.returnBook();
    assert(book.isAvailable());

    cout << "testBorrowAndReturn: PASS" << endl;
}

int main() {
    testAddBook();
    testBookDetails();
    testBorrowAndReturn();

    cout << "\nAll tests passed successfully." << endl;

    return 0;
}
