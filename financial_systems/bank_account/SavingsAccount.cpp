#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>

//Constructor chaining: call Parent(args) -> Add Child stuff
SavingsAccount::SavingsAccount(std::string name, std::string acc_num, double initial_deposit, double rate)
    : BankAccount(name, acc_num, initial_deposit) {
        interest_rate = rate;
    }

bool SavingsAccount::withdraw(double amount){
    if((balance - amount) < 10.0){
        std::cout << "Error: Savings account must maintain at leat 10.00 EUR.\n";
        return false;
    }

    return BankAccount::withdraw(amount);
}

void SavingsAccount::apply_interest(){
    double interest = balance * interest_rate;
    deposit(interest);
    std::cout << "Interest Applied: " << std::fixed << std::setprecision(2) << interest << " EUR.\n";
}

void SavingsAccount::display_info() const{
    std::cout << "--------------------------------\n";
    std::cout << "Account: " << account_number << "\n";
    std::cout << "Holder: " << account_holder << "\n";
    std::cout << "Balance: " << std::fixed << std::setprecision(2) << balance << " EUR\n";
    std::cout << "Account Type: Savings\n";
    std::cout << "Interest Rate: " << (interest_rate*100) << "%\n";
    std::cout << "--------------------------------\n";
}