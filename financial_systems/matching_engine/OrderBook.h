#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "Order.h"

class OrderBook {
    private:
        //BIDS - vector so many orders can have the same price
        //Sorts from highest to lowest bids
        std::map<double, std::vector<Order>, std::greater<double>> bids;

        //ASKS - sorts from lowest to highest price
        std::map<double, std::vector<Order>> asks;

    public:
        void add_order(Order new_order);
        void print_book() const;

    private:
        void match();
};