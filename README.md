# C++ FinTech Lab

A high-performance simulation of banking systems and financial algorithms, developed to explore Object-Oriented Programming and low-level system design.

## Features
* **Core Banking Engine:** Handles deposits, withdrawals, and balance inquiries with robust error checking.
* **Algorithm Optimization:** Implemented greedy algorithms for currency exchange (Coin Change Problem).
* **Account Hierarchy:** Utilizes C++ Inheritance to model Savings and Checking accounts with distinct interest and fee logic.
* **Robust CLI:** Interactive command-line interface with input validation and stream state management.

## Tech Stack
* **Language:** C++ (GCC 15.2.0)
* **Build System:** Manual Linking / Make (Future)
* **Tools:** VS Code, Git, MSYS2

## How to Run
1.  Clone the repository.
2.  Navigate to `financial_systems/bank_account`.
3.  Compile: `g++ -static main.cpp Account.cpp SavingsAccount.cpp Utils.cpp -o bank_app.exe`
4.  Run: `./bank_app.exe`