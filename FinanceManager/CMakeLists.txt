
cmake_minimum_required(VERSION 3.16)

project(FinanceManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(fm
    src/main.cpp
    src/Transaction.cpp
    src/Income.cpp
    src/Expense.cpp
    src/FinanceManager.cpp
)
