
#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>

class Transaction {
private:
    std::string description;
    double amount;
    std::string date;

public:
    Transaction(const std::string& description,
                double amount,
                const std::string& date);
    
    virtual ~Transaction() = default;

    std::string getDescription() const;
    double getAmount() const;
    std::string getDate() const;

    virtual void display() const = 0;
    virtual Transaction* clone() const = 0;
};

#endif
