#ifndef CHARGE_PARTICLE_H
#define CHARGE_PARTICLE_H

#include <iostream>
#include "Point.h"
#include "PointCharge.h"

class Particle : public PointCharge {
public:
    Particle(const Point &position, double charge) : position(position), charge(charge) {}

    [[nodiscard]] const Point &getPosition() const final {
        return position;
    }

    [[nodiscard]] double getCharge() const final {
        return charge;
    }

    [[nodiscard]] double getRadius() const final {
        return radius;
    }

    [[nodiscard]] Vector calculateForce(const PointCharge &p) const {
        double magnitude = this->calculateForceMagnitude(p);
        Vector force = this->position.vectorTo(p.getPosition());
        force.normalize();
        force *= magnitude;
        return force;
    }

    friend std::ostream &operator<<(std::ostream &os, const Particle &particle) {
        os << particle.position << " " << particle.charge << " " << particle.radius;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Particle &particle) {
        is >> particle.position >> particle.charge >> particle.radius;
        return is;
    }

private:

    Point position;
    double charge;
    double radius = 10;

    [[nodiscard]] double calculateForceMagnitude(const PointCharge &p) const {
        double d = this->position.distanceTo(p.getPosition());
        return 9e9 * this->charge * p.getCharge() / (d * d);
    }
};


#endif //CHARGE_PARTICLE_H
