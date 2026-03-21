#include <iostream>
#include "OrderBook.h"

int main() {
    OrderBook nasdaq;

    std::cout << "--- MARKET OPEN ---\n";

    // Bids
    nasdaq.add_order(Order("BUYER_A", Side::BUY, 150.00, 10));
    nasdaq.add_order(Order("BUYER_B", Side::BUY, 151.00, 20)); // Best buyer!
    nasdaq.add_order(Order("BUYER_C", Side::BUY, 149.00, 50));

    std::cout << "\n[System] 3 Buyers added. Waiting for sellers...\n";
    nasdaq.print_book();

    // Asks
    std::cout << "\n[System] Seller X arrives wanting $155.00 for 5 shares.\n";
    nasdaq.add_order(Order("SELLER_X", Side::SELL, 155.00, 5));
    
    // No trade should happen here
    nasdaq.print_book();

    // A desperate Seller arrives and crosses the spread
    std::cout << "\n[System] Seller Y arrives wanting $150.00 for 30 shares!\n";
    nasdaq.add_order(Order("SELLER_Y", Side::SELL, 150.00, 30));

    // Final state of the market
    nasdaq.print_book();

    std::cout << "--- MARKET CLOSED ---\n";
    return 0;
}