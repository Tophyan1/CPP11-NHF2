#ifndef CHARGE_POINT_H
#define CHARGE_POINT_H


#include <cmath>
#include <iostream>
#include "Vector.h"

class Point {

public:
    Point(double x, double y) : x(x), y(y) {}

    [[nodiscard]] double getX() const {
        return x;
    }

    [[nodiscard]] double getY() const {
        return y;
    }

    [[nodiscard]] double distanceTo(const Point &p) const {
        double dx = p.x - this->x;
        double dy = p.y - this->y;
        return sqrt(dx * dx + dy * dy);
    }

    Point &moveByVector(const Vector &v) {
        this->x += v.getX();
        this->y += v.getY();
        return *this;
    }

    [[nodiscard]] Vector vectorTo(const Point &p) const {
        return Vector(p.x - this->x, p.y - this->y);
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << point.x << " " << point.y;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Point &point) {
        is >> point.x >> point.y;
        return is;
    }

private:
    double x;
    double y;
};


#endif //CHARGE_POINT_H
