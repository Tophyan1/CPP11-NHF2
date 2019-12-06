#ifndef CHARGE_VECTOR_H
#define CHARGE_VECTOR_H


#include <cmath>

class Vector {

public:
    Vector(double x, double y) : x(x), y(y) {}

    [[nodiscard]] double getX() const {
        return x;
    }

    [[nodiscard]] double getY() const {
        return y;
    }

    double length() {
        return sqrt(x * x + y * y);
    }

    Vector &operator+=(const Vector &rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    Vector operator*(double d) const {
        return Vector(this->x * d, this->y * d);
    }

    Vector &operator*=(double d) {
        *this = *this * d;
        return *this;
    }

    Vector &normalize() {
        this->x /= this->length();
        this->y /= this->length();
        return *this;
    }

private:
    double x;
    double y;

};


#endif //CHARGE_VECTOR_H
