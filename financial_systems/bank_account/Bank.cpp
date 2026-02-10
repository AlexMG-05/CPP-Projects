#include "Bank.h"
#include "Account.h"
#include "SavingsAccount.h"
#include <iostream>
#include <algorithm>

//1. ADD and CLOSE accounts
void Bank::add_account(std::string name, std::string acc_num, double initial_dep, std::string type) {
    if (type == "savings"){
        //"make_unique" creates the object and returns a smart pointer managing it
        accounts.push_back(std::make_unique<SavingsAccount>(name, acc_num, initial_dep, 0.05));
    } else {
        accounts.push_back(std::make_unique<BankAccount>(name, acc_num, initial_dep));
    }

    std::cout << "Success: Account " << acc_num << " (" << type <<  ") opened for " << name << ".\n";
}

void Bank::close_account(std::string acc_num){
    for(auto it = accounts.begin(); it != accounts.end(); ++it) {
        if((*it)->get_account_number() == acc_num) {
            std::cout << "Closing account: " << acc_num << "...\n";
            accounts.erase(it);

            std::cout << "Account closed successfully.\n";
            return;
        }
    }
    std::cout << "Error: Account " << acc_num << "not found. Cannot close.\n";
}

//2. SHOW accounts
void Bank::show_all_accounts() const{
    std::cout << "\n=== BANK PORTFOLIO ===\n";
    std::cout << "Total accounts: " << accounts.size() << "\n";

    for(const auto& acc : accounts) {
        acc->display_info();
    }
    std::cout << "\n======================\n";
}

//3. GET total ASSETS
double Bank::get_total_assets() const {
    double total = 0.0;
    for(const auto& acc : accounts) {
        total += acc->get_balance();
    }
    return total;
}

//4. FIND account
BankAccount* Bank::find_account(std::string acc_num){
    for (const auto& acc : accounts){
        if(acc->get_account_number() == acc_num){
            return acc.get();
        }
    }
    return nullptr; //Not found
}

