#ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H

#include <string>
#include <vector>

class Book {
private:
    int bookId;
    std::string title;
    std::string author;
    std::string category;
    int year;
    bool available;

public:
    Book(int id, const std::string& t, const std::string& a,
         const std::string& c, int y);

    void display() const;
    int getId() const;
    bool isAvailable() const;
    void borrowBook();
    void returnBook();
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void displayBooks() const;
    void borrowBook(int id);
    void returnBook(int id);
};

#endif
