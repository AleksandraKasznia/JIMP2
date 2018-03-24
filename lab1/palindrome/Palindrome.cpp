//
// Created by okasz on 03.03.18.
//

#include "Palindrome.h"

bool is_palindrome(std::string str){
    int beg = 0;
    int end = str.size() - 1;
    while (beg < end){
        if (str[beg] == str[end]){
            end --;
            beg ++;
        }
        else{
            return false;
        }
    }
    return true;
}