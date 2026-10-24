
#ifndef EXPENSE_HPP
#define EXPENSE_HPP

#include "Transaction.hpp"
#include <string>

class Expense : public Transaction {
private:
    std::string category;

public:
    Expense(const std::string& description,
            double amount,
            const std::string& date,
            const std::string& category);

    void display() const override;
    Transaction* clone() const override;
};

#endif
