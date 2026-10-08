#include "member.h"
#include <iostream>

Member::Member(const std::string& id, const std::string& n)
    : memberId(id), name(n) {}

std::string Member::getMemberId() const {
    return memberId;
}

std::string Member::getName() const {
    return name;
}

void Member::display() const {
    std::cout << "Member ID: " << memberId << std::endl;
    std::cout << "Name: " << name << std::endl;
}
