#ifndef CHARGE_RECTANGLE_H
#define CHARGE_RECTANGLE_H


#include <memory>
#include <iostream>
#include "Collidable.h"
#include "Level.h"

class Rectangle : public Collidable {

public:
    Rectangle(double x, double y, double height, double width) : x(x), y(y), height(height), width(width) {}

    [[nodiscard]] double getX() const {
        return x;
    }

    [[nodiscard]] double getY() const {
        return y;
    }

    [[nodiscard]] double getHeight() const {
        return height;
    }

    [[nodiscard]] double getWidth() const {
        return width;
    }

    void setLevel(Level *level) override {
        this->level = level;
    }

    [[nodiscard]] bool didCollide(const MovableParticle &p) const final {
        double nearestX = std::max(this->x, std::min(p.getPosition().getX(), this->x + this->width));
        double nearestY = std::max(this->y, std::min(p.getPosition().getY(), this->y + this->height));
        double dx = p.getPosition().getX() - nearestX;
        double dy = p.getPosition().getY() - nearestY;
        return (p.getRadius() * p.getRadius()) > dx * dx + dy * dy;
    }

    void save(std::ostream &os) const override {
        os << x << " " << y << " " << height << " " << width;
    }

    void load(std::istream &is) override {
        is >> x >> y >> height >> width;
    }

    friend std::ostream &operator<<(std::ostream &os, const Rectangle &rectangle) {
        os << rectangle.getX() << " " << rectangle.getY() << " " << rectangle.getHeight() << " " << rectangle.getWidth();
        return os;
    }

protected:
    double x;
    double y;
    double height;
    double width;
    Level *level = nullptr;

};


#endif //CHARGE_RECTANGLE_H
