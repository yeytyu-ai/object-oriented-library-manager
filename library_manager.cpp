#include "library_manager.h"
#include <iostream>

using namespace std;

Book::Book(int id, const string& t, const string& a,
           const string& c, int y)
    : bookId(id),
      title(t),
      author(a),
      category(c),
      year(y),
      available(true) {}

void Book::display() const {
    cout << "Book ID: " << bookId << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Category: " << category << endl;
    cout << "Year: " << year << endl;
    cout << "Status: "
         << (available ? "Available" : "Borrowed") << endl;
    cout << "--------------------------" << endl;
}

int Book::getId() const {
    return bookId;
}

bool Book::isAvailable() const {
    return available;
}

void Book::borrowBook() {
    if (available) {
        available = false;
        cout << "Book borrowed successfully." << endl;
    } else {
        cout << "Book is already borrowed." << endl;
    }
}

void Book::returnBook() {
    available = true;
    cout << "Book returned successfully." << endl;
}

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::displayBooks() const {
    if (books.empty()) {
        cout << "No books available." << endl;
        return;
    }

    for (const Book& book : books) {
        book.display();
    }
}

void Library::borrowBook(int id) {
    for (Book& book : books) {
        if (book.getId() == id) {
            book.borrowBook();
            return;
        }
    }

    cout << "Book not found." << endl;
}

void Library::returnBook(int id) {
    for (Book& book : books) {
        if (book.getId() == id) {
            book.returnBook();
            return;
        }
    }

    cout << "Book not found." << endl;
}#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    string category;
    int year;
    bool available;

public:
    Book(int id, string t, string a, string c, int y)
        : bookId(id), title(t), author(a), category(c),
          year(y), available(true) {}

    void display() const {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Category: " << category << endl;
        cout << "Year: " << year << endl;
        cout << "Status: "
             << (available ? "Available" : "Borrowed") << endl;
        cout << "--------------------------" << endl;
    }

    int getId() const {
        return bookId;
    }

    bool isAvailable() const {
        return available;
    }

    void borrowBook() {
        if (available) {
            available = false;
            cout << "Book borrowed successfully.\n";
        } else {
            cout << "Book is already borrowed.\n";
        }
    }

    void returnBook() {
        available = true;
        cout << "Book returned successfully.\n";
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }

        for (const Book& book : books) {
            book.display();
        }
    }

    void borrowBook(int id) {
        for (Book& book : books) {
            if (book.getId() == id) {
                book.borrowBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int id) {
        for (Book& book : books) {
            if (book.getId() == id) {
                book.returnBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library library;

    library.addBook(Book(101, "C++ Programming", "Bjarne Stroustrup",
                         "Programming", 2013));

    library.addBook(Book(102, "Data Structures", "Mark Allen Weiss",
                         "Computer Science", 2014));

    library.addBook(Book(103, "Digital Electronics", "Morris Mano",
                         "Electronics", 2017));

    cout << "===== LIBRARY BOOKS =====\n";
    library.displayBooks();

    cout << "\n===== BORROW BOOK 101 =====\n";
    library.borrowBook(101);

    cout << "\n===== BOOKS AFTER BORROWING =====\n";
    library.displayBooks();

    cout << "\n===== RETURN BOOK 101 =====\n";
    library.returnBook(101);

    cout << "\n===== FINAL BOOK STATUS =====\n";
    library.displayBooks();

    return 0;
}
