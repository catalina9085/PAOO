
#ifndef FINANCE_MANAGER_HPP
#define FINANCE_MANAGER_HPP

#include "Transaction.hpp"
#include <cstddef>
#include <string>

class FinanceManager {
private:
    Transaction** transactions;
    int size;
    int capacity;

    void clearTransactions();
    void resize(int newCapacity);

public:
    FinanceManager();
    ~FinanceManager();

    FinanceManager(const FinanceManager& other);
    FinanceManager& operator=(const FinanceManager& other);

    FinanceManager(FinanceManager&& other);
    FinanceManager& operator=(FinanceManager&& other);

    void addTransaction(Transaction* transaction);
    void removeTransaction(int index);

    void showTransactions() const;
    void showTransactionsByDate(const std::string& date) const;
    void showTransactionsByAmount(double minimumAmount) const;

    int getTransactionCount() const;
};

#endif
