#include "Account.h"
#include "SavingsAccount.h"
#include <iostream>
#include <limits>

void show_main_menu() {
    std::cout << "\n=== ACCOUNT SELECTION ===\n";
    std::cout << "[1] Checking Account\n";
    std::cout << "[2] Savings Account\n";
    std::cout << "Press any other key to exit\n";
    std::cout << "Select option: ";
}

void show_action_menu() {
    std::cout << "\n --- ACTION MENU --- \n";
    std::cout << "[0] Deposit\n";
    std::cout << "[1] Withdraw\n";
    std::cout << "[2] Check balance\n";
    std::cout << "[3] Check account information\n";
    std::cout << "Press any other number to exit\n";
    std::cout << "Select operation: ";
}

int get_valid_int() {
    int value;
    while(true) {
        std::cin >> value;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Flush buffer
            std::cout << "Invalid input. Please enter a number: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

double get_valid_double() {
    double value;
    while (true) {
        if(std::cin >> value) {
            if(value >= 0) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            } else {
                std::cout << "Amount cannot be negative. Try Again: ";
            }
        } else {
            std::cout << "Invalid input. Please enter a valid amount (e.g. 1000.50): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main() {
    std::string name_input;
    std::string acc_num_input;
    double initial_dep;
    
    std::cout << "=== WELCOME TO CREDIT ISTAR BANK ===\n";

    //1. CREATE ACCOUNT
    std::cout << "Enter account's holder name: ";
    std::getline(std::cin, name_input);
    while(name_input.empty()){
        std::cout << "Name cannot be empty. Enter name: ";
        std::getline(std::cin, name_input);
    }

    std::cout << "Enter base account number (e.g ES-1234): ";
    std::cin >> acc_num_input;
    while(acc_num_input.empty()){
        std::cout << "Account Number cannot be empty. Enter Number: ";
        std::cin >> acc_num_input;
    }

    std::cout << "Enter initial deposit (Shared split 50/50 with Savings Account): ";
    initial_dep = get_valid_double();

    BankAccount checking(name_input, acc_num_input + "-CHK", initial_dep / 2);
    SavingsAccount savings(name_input, acc_num_input + "-SAV", initial_dep / 2, 0.05); //Assign a 5% interet

    std::cout << "\nSUCCESS: Bundle created for " << name_input << ".\n";

    //2. LOOP
    bool app_running = true;

    while(app_running) {
        show_main_menu();
        int main_choice;
        if(!(std::cin >> main_choice)) break;

        //Pointer to the Parent Class
        //This pointer can hold the address of either a Checking or a Savings object
        BankAccount* active_account = nullptr;

        if(main_choice == 1){
            active_account = &checking; //Point to Checking
            std::cout << "-> Switched to CHECKING Account.\n";
        } else if (main_choice == 2){
            active_account = &savings; //Point to Savings
            std::cout << "-> Switched to SAVINGS Account.\n";
        } else {
            std::cout << "Exiting banking system... \n";
            break;
        }

        bool sub_menu = true;
        while(sub_menu) {
            show_action_menu();
            int sub_choice = get_valid_int();

            double amount = 0.0;
            switch(sub_choice){
                case 0: //Deposit
                    std::cout << "Amount to DEPOSIT: ";
                    std::cin >> amount;
                    active_account->deposit(amount);
                    break;

                case 1: //Withdraw
                    std::cout << "Amount to WITHDRAW: ";
                    std::cin >> amount;
                    active_account->withdraw(amount);
                    break;

                case 2: //Check balance
                    std::cout << "Account's balance: " << active_account->get_balance() << " EUR.\n";
                    break;
                
                case 3: //Account's info
                    active_account->display_info();
                    break;
                
                default: //Back
                    sub_menu = false;
                    break;
            }
        }
    }
    std::cout << "Thank you for banking with us.\n";
        
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
    std::cin.get();

    return 0;
}