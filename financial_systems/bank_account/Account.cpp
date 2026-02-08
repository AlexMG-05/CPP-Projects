#include "Account.h"
#include <iostream>
#include <iomanip>

BankAccount::BankAccount(std::string name, std::string acc_num, double initial_deposit){
    account_holder = name;
    account_number = acc_num;
    
    if(initial_deposit >= 0){
        balance = initial_deposit;
    } else {
        balance = 0;
    }
}

void BankAccount::deposit(double amount){
    if(amount > 0){
        balance += amount;
        std::cout << "Success: Deposited " << std::fixed << std::setprecision(2) << amount << " EUR. \n";
    } else {
        std::cout << "Error: Deposit amount must be positive. \n";
    }
}

bool BankAccount::withdraw(double amount){
    if (amount <= 0) {
        std::cout << "Error: Withdrawal amount must be positive. \n";
        return false;
    }

    if (amount > balance) {
        std::cout << "Failure: Insufficient funds. Balance is " << std::fixed << std::setprecision(2) << balance << " EUR. \n";
        return false;
    }

    balance -= amount;
    std::cout << "Success: Withdrew " << std::fixed << std::setprecision(2) << amount << " EUR. \n";
    return true;
}

double BankAccount::get_balance() const{
    return balance;
}

void BankAccount::display_info() const{
    std::cout << "--------------------------------\n";
    std::cout << "Account: " << account_number << "\n";
    std::cout << "Holder: " << account_holder << "\n";
    std::cout << "Balance: " << std::fixed << std::setprecision(2) << balance << " EUR\n";
    std::cout << "--------------------------------\n";
}