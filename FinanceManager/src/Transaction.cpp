
#include "Transaction.hpp"

Transaction::Transaction(const std::string& description,
                         double amount,
                         const std::string& date)
    : description(description),
      amount(amount),
      date(date) {
}

std::string Transaction::getDescription() const {
    return description;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getDate() const {
    return date;
}
