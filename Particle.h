#ifndef CHARGE_PARTICLE_H
#define CHARGE_PARTICLE_H


#include <fstream>
#include "Point.h"
#include "Area.h"

class Particle {
public:
    Particle() = default;

    Particle(int x, int y, int charge, double radius = 10) : pos_(x, y), charge_(charge), radius_(radius) {}

    [[nodiscard]] const Point &getPos() const {
        return pos_;
    }

    void setPos(const Point &pos) {
        Particle::pos_ = pos;
    }

    [[nodiscard]] int getCharge() const {
        return charge_;
    }

    [[nodiscard]] double getRadius() const {
        return radius_;
    }

    [[nodiscard]] double distance(const Particle &other) const {
        return this->pos_.distance(other.pos_);
    }

    bool operator==(const Particle &rhs) const {
        return pos_ == rhs.pos_ &&
               charge_ == rhs.charge_ &&
               radius_ == rhs.radius_;
    }

    bool operator!=(const Particle &rhs) const {
        return !(rhs == *this);
    }

    [[nodiscard]] Point exertForceTo(const Particle &other) const {
        double dist = this->distance(other);
        if (dist == 0)
            return Point(0, 0);
        double mag = this->charge_ * other.charge_ / (dist * dist);
        double phi = this->pos_.angleTo(other.pos_);
        return Point(mag * cos(phi), mag * sin(phi));
    }

    bool collidedWith(Area rect) {
        int nearestX = std::max(rect.getX(), std::min(this->pos_.x, rect.getX() + rect.getWidth()));
        int nearestY = std::max(rect.getY(), std::min(this->pos_.y, rect.getY() + rect.getHeight()));
        int dx = this->pos_.x - nearestX;
        int dy = this->pos_.y - nearestY;
        return (this->radius_ * this->radius_) > dx * dx + dy * dy;
    }

    friend std::ofstream &operator<<(std::ofstream &os, const Particle &particle) {
        os << particle.pos_ << " " << particle.charge_ << " " << particle.radius_;
        return os;
    }

    friend std::ifstream &operator>>(std::ifstream &is, Particle &particle) {
        is >> particle.pos_ >> particle.charge_ >> particle.radius_;
        return is;
    }

private:
    Point pos_;
    int charge_ = 0;
    double radius_ = 10;
};

#endif //CHARGE_PARTICLE_H
