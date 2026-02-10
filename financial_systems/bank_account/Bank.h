#ifndef BANK_H
#define BANK_H

#include <vector>
#include <memory>
#include <string>
#include "Account.h"


class Bank {
    private:
        // unique_ptr<BankAccount> means "the bank owns this memory"
        std::vector<std::unique_ptr<BankAccount>> accounts;
    
    public:
        //1. Core management
        void add_account(std::string name, std::string acc_num, double initial_dep, std::string type);
        void close_account(std::string acc_num);

        //2. Reporting
        void show_all_accounts() const;
        double get_total_assets() const;

        //3. Operations
        BankAccount* find_account(std::string acc_num);
};

#endif