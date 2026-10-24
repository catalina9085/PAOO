
#ifndef INCOME_HPP
#define INCOME_HPP

#include "Transaction.hpp"
#include <string>

class Income : public Transaction {
private:
    std::string source;

public:
    Income(const std::string& description,
           double amount,
           const std::string& date,
           const std::string& source);

    void display() const override;
    Transaction* clone() const override;
};

#endif
