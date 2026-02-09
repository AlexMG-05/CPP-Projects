#include "Utils.h"
#include <iostream>
#include <limits>

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