//
// Created by okasz on 03.03.18.
//
#include <iostream>
#include "Palindrome.h"

int main() {
    int choice;
    std::string word;
    std::cout << is_palindrome("kajaki");
    std::cout << "Wyjscie - wybierz 1" << std::endl << "Sprawdz palindrom - wybierz 2" << std::endl;
    std::cin >> choice;
    switch (choice) {
        case 2: {
            std::cout << "Podaj palindrom" << std::endl;
            std::cin >> word;
            if (is_palindrome(word) == 1) {
                std::cout << "Jest";
            } else {
                std::cout << "Nie jest";
            }
        }
            break;
        case 1: {
            return 0;
        }
            break;
        default: {
            break;
        }
    }
    return 0;
}


