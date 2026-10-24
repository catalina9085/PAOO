
#include "Income.hpp"
#include <iostream>

Income::Income(const std::string& description,
               double amount,
               const std::string& date,
               const std::string& source)
    : Transaction(description, amount, date),
      source(source) {
}

void Income::display() const {
    std::cout << "[INCOME] "
              << getDescription()
              << " | Amount: " << getAmount()
              << " | Date: " << getDate()
              << " | Source: " << source
              << '\n';
}

Transaction* Income::clone() const {
    return new Income(*this);
}
