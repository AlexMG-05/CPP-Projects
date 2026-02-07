#include "Account.h"
#include <iostream>

int main() {
    //1. Create an Account
    BankAccount my_account("Alejandro", "ES-2505", 1000.0);

    //2. Display info
    my_account.display_info();

    //3. Test Deposit
    std::cout <<"\n [TEST] Depositing salary... \n";
    my_account.deposit(500.0);

    //4. Test Withdrawal
    std::cout <<"\n [TEST] Buying new laptop... \n";
    
    if(my_account.withdraw(1200.0)){
        std::cout << "-> TRANSACTION APPROVED. \n";
    } else {
        std::cout << "-> TRANSACTION DENIED. \n";
    }

    //5. Test invalid withdrawal
    std::cout <<"\n [TEST] Buying a Ferrari... \n";
    
    if(my_account.withdraw(500000.0)){
        std::cout << "-> TRANSACTION APPROVED. \n";
    } else {
        std::cout << "-> TRANSACTION DENIED. \n";
    }

    //6. Final State
    std::cout <<"\n--- END OF DAY ---\n";
    my_account.display_info();

    std::cin.get();
    return 0;
}