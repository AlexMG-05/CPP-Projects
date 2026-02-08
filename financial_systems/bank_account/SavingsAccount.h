#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"

class SavingsAccount : public BankAccount {
    private:
        double interest_rate;
    
    public:
        SavingsAccount(std::string name, std::string acc_num, double initial_deposit, double rate);

        bool withdraw(double amount) override; //Replacing parent's logic
        void display_info() const override;
        void apply_interest();
};

#endif