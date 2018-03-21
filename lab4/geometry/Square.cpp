//
// Created by okasz on 21.03.2018.
//

#include "Square.h"
#include <cmath>
#include <ostream>
#include <iostream>

namespace geometry{
    Square::Square(Point p1, Point p2, Point p3, Point p4) {
        if (p1.Distance(p2) == p2.Distance(p4) && p1.Distance(p4) == p2.Distance(p3)){
            p1_ = p1;
            p2_ = p2;
        }
        else{
            p1_ = Point(0,0);
            p2_ = Point(0,0);
        }
    }

    Square::~Square(){

    }

    double Square::Circumference() const {
        return p1_.Distance(p2_)*4;
    }

    double Square::Area() const {
        return p1_.Distance(p2_)*p1_.Distance(p2_);
    }
}