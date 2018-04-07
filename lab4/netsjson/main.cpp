//
// Created by okasz on 23.03.2018.
//


#include "SimpleJson.h"
using namespace nets;

int main(){
    JsonValue j{5.876};
    cout << j.ToString();
    return 0;
}