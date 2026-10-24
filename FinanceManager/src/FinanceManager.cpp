
#include "FinanceManager.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

FinanceManager::FinanceManager()
    : transactions(new Transaction*[10]{}),
      size(0),
      capacity(10) {
}

void FinanceManager::clearTransactions() {
    for (int i = 0; i < size; ++i) {
        delete transactions[i];
    }

    delete[] transactions;

    transactions = nullptr;
    size = 0;
    capacity = 0;
}

FinanceManager::~FinanceManager() {
    clearTransactions();
}

void FinanceManager::resize(int newCapacity) {
    Transaction** newTransactions =
        new Transaction*[newCapacity]{};

    for (int i = 0; i < size; ++i) {
        newTransactions[i] = transactions[i];
    }

    delete[] transactions;

    transactions = newTransactions;
    capacity = newCapacity;
}

//copy constructor
FinanceManager::FinanceManager(const FinanceManager& other){
    capacity=other.capacity;
    size=other.size;
    transactions=new Transaction*[capacity]{};
    for(int i=0;i<size;i++){
        transactions[i]=other.transactions[i]->clone();
    }
}

// Move constructor
FinanceManager::FinanceManager(FinanceManager&& other)
    : transactions(other.transactions),
      size(other.size),
      capacity(other.capacity) {

    other.transactions = nullptr;
    other.size = 0;
    other.capacity = 0;
}

// Copy assignment operator
FinanceManager& FinanceManager::operator=(
    const FinanceManager& other) {

    if (this != &other) {
        FinanceManager temporary(other);

        std::swap(transactions, temporary.transactions);
        std::swap(size, temporary.size);
        std::swap(capacity, temporary.capacity);
    }

    return *this;
}

//move assignment operator
FinanceManager& FinanceManager::operator=(FinanceManager&& other){
    if(this!=&other){
        clearTransactions();
        size=other.size;
        capacity=other.capacity;
        transactions=other.transactions;
        other.transactions=nullptr;
        other.size=0;
        other.capacity=0;
    }
    return *this;
}


// Adauga o tranzactie
void FinanceManager::addTransaction(Transaction* transaction) {
    if (transaction == nullptr) {
        return;
    }

    if (size == capacity) {
        resize(capacity == 0 ? 2 : capacity * 2);
    }

    transactions[size] = transaction;
    ++size;
}

// Sterge tranzactia de la indexul dat
void FinanceManager::removeTransaction(int index) {
    if (index >= size) {
        std::cout << "Invalid transaction index.\n";
        return;
    }

    delete transactions[index];

    for (int i =index; i < size - 1; ++i) {
        transactions[i] = transactions[i + 1];
    }

    --size;
    transactions[size] = nullptr;
}

// Afiseaza toate tranzactiile
void FinanceManager::showTransactions() const {
    if (size == 0) {
        std::cout << "No transactions available.\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << ". ";
        transactions[i]->display();
    }
}

// Filtreaza dupa data
void FinanceManager::showTransactionsByDate(
    const std::string& date) const {

    bool found = false;

    for (int i = 0; i < size; ++i) {
        if (transactions[i]->getDate() == date) {
            transactions[i]->display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No transactions found for this date.\n";
    }
}

// Filtreaza dupa suma minima
void FinanceManager::showTransactionsByAmount(
    double minimumAmount) const {

    bool found = false;

    for (int i = 0; i < size; ++i) {
        if (transactions[i]->getAmount() >= minimumAmount) {
            transactions[i]->display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No transactions found for this amount.\n";
    }
}

// Numarul de tranzactii existente
int FinanceManager::getTransactionCount() const {
    return size;
}
