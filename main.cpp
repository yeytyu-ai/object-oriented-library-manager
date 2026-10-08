#include "library_manager.h"
#include <iostream>

using namespace std;

int main() {
    Library library;

    library.addBook(Book(
        101,
        "C++ Programming",
        "Bjarne Stroustrup",
        "Programming",
        2013
    ));

    library.addBook(Book(
        102,
        "Data Structures",
        "Mark Allen Weiss",
        "Computer Science",
        2014
    ));

    library.addBook(Book(
        103,
        "Digital Electronics",
        "Morris Mano",
        "Electronics",
        2017
    ));

    cout << "===== LIBRARY BOOKS =====" << endl;
    library.displayBooks();

    cout << "\n===== BORROW BOOK 101 =====" << endl;
    library.borrowBook(101);

    cout << "\n===== RETURN BOOK 101 =====" << endl;
    library.returnBook(101);

    cout << "\n===== FINAL BOOK STATUS =====" << endl;
    library.displayBooks();

    return 0;
}
