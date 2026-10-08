#include "loan.h"
#include <iostream>

Loan::Loan(const std::string& bId,
           const std::string& mId,
           const std::string& date)
    : bookId(bId), memberId(mId), dueDate(date) {}

std::string Loan::getBookId() const {
    return bookId;
}

std::string Loan::getMemberId() const {
    return memberId;
}

std::string Loan::getDueDate() const {
    return dueDate;
}

void Loan::display() const {
    std::cout << "Book ID: " << bookId << std::endl;
    std::cout << "Member ID: " << memberId << std::endl;
    std::cout << "Due Date: " << dueDate << std::endl;
}
