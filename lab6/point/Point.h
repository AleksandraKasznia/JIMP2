//
// Created by okasz on 10.04.2018.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#ifndef POINT_H
#define POINT_H
#include <iostream>

namespace point{
    class Point {
    public:
        void SetX(double x);

        void SetY(double y);

        double GetX() const;

        double GetY() const;

    private:
        double x_, y_;
    };

    std::istream &operator>>(std::istream &is, Point &point);

    std::ostream &operator<<(std::ostream &output, Point &p);

}
#endif


#endif //JIMP_EXERCISES_POINT_H
