#ifndef CHARGE_POINT_H
#define CHARGE_POINT_H


#include <cmath>
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

    Point &moveBy(const Vector &v) {
        this->x += v.getX();
        this->y += v.getY();
        return *this;
    }

    [[nodiscard]] Vector vectorTo(const Point &p) const {
        return Vector(p.x - this->x, p.y - this->y);
    }

private:
    double x;
    double y;
};


#endif //CHARGE_POINT_H
