#ifndef ACCOUNT_H //So file is read only once
#define ACCOUNT_H
#include <string>

//CLASS DECLARATION
class BankAccount{

    private:
    std::string account_holder;
    std::string account_number;
    double balance;

    public:
    //Constructor
    BankAccount(std::string name, std::string acc_num, double initial_deposit);

    void deposit(double amount);
    bool withdraw(double amount); //T = successful, F = insufficient funds

    //Read-only
    double get_balance() const;
    void display_info() const;
};

#endif // ACCOUNT_H