#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
private:
    std::string memberId;
    std::string name;

public:
    Member(const std::string& id, const std::string& n);

    std::string getMemberId() const;
    std::string getName() const;

    void display() const;
};

#endif
