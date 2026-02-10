#ifndef ACCOUNT_H //So file is read only once
#define ACCOUNT_H
#include <string>

//CLASS DECLARATION
class BankAccount{

    protected:
    std::string account_holder;
    std::string account_number;
    double balance;

    public:
    BankAccount(std::string name, std::string acc_num, double initial_deposit);

    virtual void deposit(double amount);
    virtual bool withdraw(double amount); //T = successful, F = insufficient funds
    virtual void display_info() const;
    virtual ~BankAccount() {}

    double get_balance() const;
    std::string get_account_number () const;
};

#endif // ACCOUNT_H