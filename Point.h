#ifndef CHARGE_POINT_H
#define CHARGE_POINT_H


#include <cmath>
#include <stdexcept>
#include <fstream>

struct Point {
    int x;
    int y;

    friend std::ofstream &operator<<(std::ofstream &os, const Point &point) {
        os << point.x << point.y;
        return os;
    }

    friend std::ifstream &operator>>(std::ifstream &is, Point &point) {
        is >> point.x >> point.y;
        return is;
    }

    Point() = default;
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point &p) = default;
    ~Point() = default;

    [[nodiscard]] int distance(const Point &rhs) const noexcept {
        int dx = this->x - rhs.x;
        int dy = this->y - rhs.y;
        return dx*dx + dy*dy;
    }

    Point& operator=(const Point &rhs) noexcept {
        if (this != &rhs) {
            this->x = rhs.x;
            this->y = rhs.y;
        }
        return *this;
    }

    Point operator+(const Point &rhs) const noexcept {
        return Point(this->x + rhs.x, this->y + rhs.y);
    }

    Point& operator+=(const Point &rhs) noexcept {
        if (this != &rhs)
            *this = *this + rhs;
        return *this;
    }

    Point operator-(const Point &rhs) const noexcept {
        return Point(this->x - rhs.x, this->y - rhs.y);
    }

    Point& operator-=(const Point &rhs) noexcept {
        if (this != &rhs)
            *this = *this - rhs;
        return *this;
    }

    [[nodiscard]] double angleTo(const Point &rhs) const noexcept {
        return atan2(rhs.y - this->y, rhs.x - this->x);
    }

    Point operator*(double d) const noexcept {
        return Point(d * this->x, d * this->y);
    }

    Point &operator*=(double d) noexcept {
        *this = *this * d;
        return *this;
    }

    Point operator/(double d) const {
        if (d == 0)
            throw std::domain_error("Divison by zero!");
        return Point(this->x / d, this->y / d);
    }

    Point &operator/=(double d) {
        if (d == 0)
            throw std::domain_error("Divison by zero!");
        *this = *this/d;
        return *this;
    }
};




#endif //CHARGE_POINT_H
