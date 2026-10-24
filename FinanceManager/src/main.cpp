
#include <iostream>
#include <utility>

#include "FinanceManager.hpp"
#include "Income.hpp"
#include "Expense.hpp"

int main() {
    FinanceManager original;

    original.addTransaction(
        new Income("Salary", 5000, "2026-10-24", "Nokia"));

    original.addTransaction(
        new Expense("Food", 100, "2026-10-24", "Groceries"));

    // 1. Copy constructor
    std::cout << "\n=== COPY CONSTRUCTOR ===\n";
    FinanceManager copied(original);
    copied.showTransactions();

    // 2. Move constructor
    std::cout << "\n=== MOVE CONSTRUCTOR ===\n";
    FinanceManager moved(std::move(copied));
    moved.showTransactions();

    // 3. Copy assignment operator
    std::cout << "\n=== COPY ASSIGNMENT ===\n";
    FinanceManager copyAssigned;
    copyAssigned = original;
    copyAssigned.showTransactions();

    // 4. Move assignment operator
    std::cout << "\n=== MOVE ASSIGNMENT ===\n";
    FinanceManager moveAssigned;
    moveAssigned = std::move(copyAssigned);
    moveAssigned.showTransactions();

    return 0;
}
