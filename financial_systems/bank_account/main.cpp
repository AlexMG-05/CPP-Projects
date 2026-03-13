#include "Account.h"
#include "Bank.h"
#include "Utils.h"
#include <iostream>
#include <limits>

void show_main_menu() {
    std::cout << "\n=== ISTAR BANK MANAGEMENT SYSTEM ===\n";
    std::cout << "[1] Open New Account\n";
    std::cout << "[2] Manage Existing Account\n";
    std::cout << "[3] Show Bank Portfolio\n";
    std::cout << "Press any other number to exit\n";
    std::cout << "Select option: ";
}

void show_action_menu() {
    std::cout << "\n --- ACTION MENU --- \n";
    std::cout << "[1] Deposit\n";
    std::cout << "[2] Withdraw\n";
    std::cout << "[3] Check account information\n";
    std::cout << "[4] Delete account\n";
    std::cout << "Press any other number to exit\n";
    std::cout << "Select operation: ";
}

int main() {
    Bank istar_bank;
    istar_bank.load_database();
    std::cout << "System initialized. Ready for customers.\n";

    bool app_running = true;
    while (app_running){
        show_main_menu();
        int choice = get_valid_int();

        switch (choice) {
            case 1:
            {
                std::cout << "\n--- NEW CUSTOMER ---\n";
                std::cout << "Enter Name: ";
                std::string name;
                std::getline(std::cin >> std::ws, name);

                std::cout << "Enter Base ID (e.g. ES-123): ";
                std::string id;
                std::cin >> id;

                std::cout << "Initial Deposit: ";
                double amount = get_valid_double();

                std::cout << "Choose type: [1] Checking, [2] Savings, [3] BUNDLE (amount to be split): ";
                int type_choice = get_valid_int();

                if(type_choice == 1) {
                    istar_bank.add_account(name, id + "-C", amount, "checking");
                } else if(type_choice == 2) {
                    istar_bank.add_account(name, id + "-S", amount, "savings");
                } else if (type_choice == 3) {
                    istar_bank.add_account(name, id + "-C", amount/2, "checking");
                    istar_bank.add_account(name, id + "-S", amount/2, "savings");
                    std::cout << "Bundle created successfully!\n";
                }
                break;
            }

            case 2:
            {
                std::cout << "Enter Account ID to manage: ";
                std::string target_id;
                std::cin >> target_id;

                BankAccount* active_account = istar_bank.find_account(target_id);

                if (active_account != nullptr) {
                    std::cout << "Accessing Account: " << target_id << "...\n";

                    bool in_account = true;
                    while (in_account) {
                        show_action_menu();
                        int op = get_valid_int();

                        switch (op) {
                            case 1:
                                std::cout << "Amount: ";
                                active_account->deposit(get_valid_double());
                                break;
                            case 2:
                                std::cout << "Amount: ";
                                active_account->withdraw(get_valid_double());
                                break;
                            case 3:
                                active_account->display_info();
                                break;
                            case 4:
                            {
                                std::cout << "Are you sure? This cannot be undone. (1 = Yes, 2 = No): ";
                                int confirm = get_valid_int();
                                if (confirm == 1) {
                                    istar_bank.close_account(active_account->get_account_number());
                                    in_account = false;
                                }
                                break;
                            }
                            default:
                                in_account = false;
                                break;
                        }
                    }
                } else {
                    std::cout << "Error: Account not found.\n";
                }
                break;
            }

            case 3:
            {
                istar_bank.show_all_accounts();
                std::cout << "Total Bank Assets: " << istar_bank.get_total_assets() << " EUR\n";
                break;
            }

            default:
            {
                app_running = false;
                break;
            }
        }
    }

    std::cout << "Banking System shutting down...\n";

    istar_bank.save_database();

    return 0;
}