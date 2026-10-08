#ifndef LOAN_H
#define LOAN_H

#include <string>

class Loan {
private:
    std::string bookId;
    std::string memberId;
    std::string dueDate;

public:
    Loan(const std::string& bId,
         const std::string& mId,
         const std::string& date);

    std::string getBookId() const;
    std::string getMemberId() const;
    std::string getDueDate() const;

    void display() const;
};

#endif
