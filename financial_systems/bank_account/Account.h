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

    // The keyword 'virtual' means child classes can override this answer.
    virtual void deposit(double amount);
    virtual bool withdraw(double amount); //T = successful, F = insufficient funds
    virtual void display_info() const;
    virtual std::string get_type() const { return "checking"; }
    
    virtual ~BankAccount() {}

    double get_balance() const;
    std::string get_account_number () const;
    std::string get_account_holder() const { return account_holder; }
};

#endif // ACCOUNT_H