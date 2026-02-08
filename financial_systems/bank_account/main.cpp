#include "Account.h"
#include <iostream>
#include <limits>

void show_menu() {
    std::cout << "\n --- ACTION MENU --- \n";
    std::cout << "[0] Deposit\n";
    std::cout << "[1] Withdraw\n";
    std::cout << "[2] Check balance\n";
    std::cout << "[3] Check account information\n";
    std::cout << "Press any other key to exit\n";
    std::cout << "Select operation: ";
}

int main() {
    std::string name_input;
    std::string acc_num_input;
    double initial_dep;
    
    std::cout << "=== WELCOME TO CREDIT ISTAR BANK ===\n";

    //1. CREATE ACCOUNT
    std::cout << "Enter account's holder name: ";
    std::getline(std::cin, name_input);

    std::cout << "Enter account number (e.g ES-1234): ";
    std::cin >> acc_num_input;

    std::cout << "Enter initial deposit: ";
    std::cin >> initial_dep;

    BankAccount my_account(name_input, acc_num_input, initial_dep);

    //2. LOOP
    int choice = -1;
    bool running = true;

    while(running) {
        show_menu();

        if(!(std::cin >> choice)) break;

        double amount = 0.0;
        switch (choice) {
            case 0: //Deposit
                std::cout << "Enter amount to DEPOSIT: ";
                std::cin >> amount;
                my_account.deposit(amount);
                break;
            
            case 1: //Withdraw
                std::cout << "Enter amount to WITHDRAW: ";
                std::cin >> amount;
                my_account.withdraw(amount);
                break;

            case 2: //Check balance
                std::cout << "Current balance: " << my_account.get_balance() << " EUR.\n";
                break;
            
            case 3: //Show account info
                my_account.display_info();
                break;
            
            default: 
                std::cout << "Exiting system...\n";
                running = false;
                break;
        }
    }
    std::cout << "Thank you for banking with us.\n";
        
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
    std::cin.get();

    return 0;
}