#include <iostream>
#include <vector>
#include <map>
#include <cassert>  // For "Unit Tests"

std::map<int, int> get_change(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Amount cannot be negative");
    }

    const std::vector<int> coins = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    std::map<int, int> result;

    for (int coin : coins) {
        int count = amount / coin; // Integer division (The optimization!)
        if (count > 0) {
            result[coin] = count;
            amount = amount % coin;
        }
    }
    return result;
}

//Test unit
void run_tests() {
    std::cout << "Running system checks... ";
    
    // Test Case 1: 87 cents -> 50+20+10+5+2 (5 coins)
    std::map<int, int> res1 = get_change(87);
    assert(res1[50] == 1);
    assert(res1[20] == 1);
    assert(res1[2] == 1);

    // Test Case 2: 200 cents -> 1x 200
    std::map<int, int> res2 = get_change(200);
    assert(res2[200] == 1);
    assert(res2[50] == 0);

    std::cout << "PASS [OK]\n";
}

//Main
int main() {
    // 1. Run internal tests first
    run_tests();

    // 2. The Main Application
    int amount;
    std::cout << "\n--- SWISS COIN ENGINE v1.0 ---\n";
    std::cout << "Enter amount in cents: ";
    if (!(std::cin >> amount)) {
        std::cerr << "Error: Invalid input.\n";
        return 1;
    }

    try {
        std::map<int, int> change = get_change(amount);
        
        int total_coins = 0;
        std::cout << "\nResult:\n";
        
        // Iterate through the map to print results
        // 'pair.first' is the coin value, 'pair.second' is the count
        for (auto const& [coin, count] : change) {
            std::cout << count << " x [ " << coin << " ]\n";
            total_coins += count;
        }
        std::cout << "Total coins: " << total_coins << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "\nPress ENTER to exit...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}