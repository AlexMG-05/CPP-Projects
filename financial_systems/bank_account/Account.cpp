#include "Account.h"
#include <iostream>
#include <iomanip>

BankAccount::BankAccount(std::string name, std::string acc_num, double initial_deposit){
    if(name.empty()){
        std::cerr << "CRITICAL ERROR: Account created without a name! Defaulting to 'Unknown'.\n";
        account_holder = "Unknown";
    } else {
        account_holder = name;
    }

    if(acc_num.empty()){
        std::cerr << "CRITICAL ERROR: Account created without a number! Defaulting to '0000'.\n";
        account_number = "0000";
    } else {
        account_holder = acc_num;
    }
    
    if(initial_deposit < 0){
        std::cerr << "CRITICAL ERROR: Negative initial deposit! Setting to 0.0 EUR\n";
        balance = 0.0;
    } else {
        balance = initial_deposit;
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

std::string BankAccount::get_account_number() const{
    return account_number;
}

void BankAccount::display_info() const{
    std::cout << "--------------------------------\n";
    std::cout << "Account: " << account_number << "\n";
    std::cout << "Holder: " << account_holder << "\n";
    std::cout << "Balance: " << std::fixed << std::setprecision(2) << balance << " EUR\n";
    std::cout << "Account Type: Checking\n";
    std::cout << "--------------------------------\n";
}