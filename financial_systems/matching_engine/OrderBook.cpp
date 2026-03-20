#include "OrderBook.h"
#include <algorithm>

//ADD Order
void OrderBook::add_order(Order new_order) {
    if (new_order.side == Side::BUY) {
        bids[new_order.price].push_back(new_order);
    } else {
        asks[new_order.price].push_back(new_order);
    }

    match();
}

//Matching algorithm
void OrderBook::match() {
    while(!bids.empty() && !asks.empty()){
        //Get highest bid and lowest ask
        auto best_bid = bids.begin();
        auto best_ask = asks.begin();

        if (best_bid->first < best_ask->first) {
            break;
        }

        //If we are here, we have a match
        Order& top_bid_order = best_bid->second.front();
        Order& top_ask_order = best_ask->second.front();

        //Check amount of tradeable shares
        int trade_qty = std::min(top_bid_order.quantity, top_ask_order.quantity);

        std::cout << ">>> TRADE EXECUTED: " << trade_qty << " shares at $" 
                  << best_ask->first << " (Buyer: " << top_bid_order.order_id 
                  << " | Seller: " << top_ask_order.order_id << ")\n";

        //Deduct shares from both orders
        top_bid_order.quantity -= trade_qty;
        top_ask_order.quantity -= trade_qty;

        if (top_bid_order.quantity == 0) {
            best_bid->second.erase(best_bid->second.begin());
        }
        if (top_ask_order.quantity == 0) {
            best_ask->second.erase(best_ask->second.begin());
        }

        // If the entire line for that specific price is empty, delete the price level from the map
        if (best_bid->second.empty()) {
            bids.erase(best_bid);
        }
        if (best_ask->second.empty()) {
            asks.erase(best_ask);
        }
    }
}

//SHOW Market
void OrderBook::print_book() const {
    std::cout << "\n=== ORDER BOOK ===\n";

    std::cout << "--- ASKS (Sellers) ---\n";
    for (auto it = asks.rbegin(); it != asks.rend(); ++it) {
        std::cout << "$" << it->first << " : " << it->second.size() << " order(s)\n";
    }

    std::cout << "------------------------\n";

    std::cout << "--- BIDS (Buyers) ---\n";
    for (auto& [price, orders] : bids) {
        std::cout << "$" << price << " : " << orders.size() << " order(s)\n";
    }
    std::cout << "==================\n\n";
}