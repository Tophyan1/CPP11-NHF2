#ifndef CHARGE_MOVABLEPARTICLE_H
#define CHARGE_MOVABLEPARTICLE_H

#include <iostream>
#include "Point.h"
#include "PointCharge.h"

class MovableParticle : public PointCharge {
public:

    MovableParticle() : position(0, 0), charge(1) {}

    MovableParticle(const Point &position, double charge) : position(position), charge(charge) {}

    MovableParticle(const Point &position, double charge, double mass, const Vector &velocity)
            : position(position), charge(charge), mass(mass), velocity(velocity) {}

    [[nodiscard]] const Point &getPosition() const final {
        return position;
    }

    [[nodiscard]] double getCharge() const final {
        return charge;
    }

    [[nodiscard]] double getRadius() const final {
        return radius;
    }

    [[nodiscard]] double getMass() const {
        return mass;
    }

    [[nodiscard]] const Vector &getVelocity() const {
        return velocity;
    }

    void move(Vector force, double deltaTime) {
        Vector acceleration = force / mass;
        this->velocity += acceleration * deltaTime;
        this->position.moveByVector(this->velocity * deltaTime);
    }

    friend std::ostream &operator<<(std::ostream &os, const MovableParticle &particle) {
        os << particle.position << " " << particle.charge << " " << particle.radius << " " << particle.mass << " " <<
           particle.velocity;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, MovableParticle &particle) {
        is >> particle.position >> particle.charge >> particle.radius >> particle.mass >> particle.velocity;
        return is;
    }

private:
    Point position;
    double charge;
    double radius = 10;
    double mass = 1;
    Vector velocity = Vector(0, 0);

};


#endif //CHARGE_MOVABLEPARTICLE_H
