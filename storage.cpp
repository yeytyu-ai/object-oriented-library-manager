#include "storage.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<Book> Storage::loadBooks(const string& filename) {
    vector<Book> books;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return books;
    }

    string line;

    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);

        string bookId;
        string title;
        string author;
        string category;
        string year;
        string status;
        string borrowerId;
        string dueDate;

        getline(ss, bookId, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, category, ',');
        getline(ss, year, ',');
        getline(ss, status, ',');
        getline(ss, borrowerId, ',');
        getline(ss, dueDate, ',');

        try {
            int id = stoi(bookId);
            int bookYear = stoi(year);

            books.emplace_back(
                id,
                title,
                author,
                category,
                bookYear
            );
        }
        catch (...) {
            cout << "Warning: Malformed row skipped." << endl;
        }
    }

    file.close();
    return books;
}

bool Storage::saveBooks(const string& filename,
                        const vector<Book>& books) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not save file." << endl;
        return false;
    }

    file << "book_id,title,author,category,year,status,borrower_id,due_date\n";

    for (const Book& book : books) {
        file << book.getId() << ","
             << book.getTitle() << ","
             << book.getAuthor() << ","
             << book.getCategory() << ","
             << book.getYear() << ","
             << (book.isAvailable() ? "available" : "borrowed")
             << ",,\n";
    }

    file.close();
    return true;
  }
