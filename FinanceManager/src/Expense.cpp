
#include "Expense.hpp"
#include <iostream>

Expense::Expense(const std::string& description,
                 double amount,
                 const std::string& date,
                 const std::string& category)
    : Transaction(description, amount, date),
      category(category) {
}

void Expense::display() const {
    std::cout << "[EXPENSE] "
              << getDescription()
              << " | Amount: " << getAmount()
              << " | Date: " << getDate()
              << " | Category: " << category
              << '\n';
}

Transaction* Expense::clone() const {
    return new Expense(*this);
}
