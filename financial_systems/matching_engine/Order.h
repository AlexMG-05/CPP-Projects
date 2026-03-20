#pragma once
#include <string>

enum class Side {
    BUY,
    SELL
};

struct Order {
    std::string order_id;
    Side side;
    double price;
    int quantity;

    Order(std::string id, Side s, double p, int q){
        order_id = id;
        side = s;
        price = p;
        quantity = q;
    }
};