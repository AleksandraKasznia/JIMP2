//
// Created by okasz on 10.04.2018.
//

#include <iomanip>
#include <iostream>
#include "Point.h"

using ::std::ostream;
using ::std::istream;
using ::std::ws;

namespace point{
void CheckNextChar(char c, istream *is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw std::runtime_error("invalid character");
    }
    is->ignore();
}

void IgnoreWhitespace(istream *is) {
    (*is) >> ws;
}

double ReadNumber(istream *is) {
    double d;
    (*is) >> d;
    return d;
}

double Point::GetX() const {
    return this->x_;
}

double Point::GetY() const {
    return this->y_;
}

void Point::SetX(double x) {
    x_ = x;
}

void Point::SetY(double y) {
    y_ = y;
}

istream &operator>>(istream &input, Point &p) {
    CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    CheckNextChar(',', &input);
    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);
    return input;
}

ostream &operator<<(ostream &output, Point &p) {
    std::cout << "(" << p.GetX() << "," << p.GetY() << ")";
    return output;
}
}


