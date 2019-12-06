#ifndef CHARGE_MOVINGPARTICLE_H
#define CHARGE_MOVINGPARTICLE_H

#include <fstream>
#include "Particle.h"

class MovingParticle : public Particle {
public:
    MovingParticle() = default;
    ~MovingParticle() = default;

    MovingParticle(int x, int y, int charge, double mass, const Point &vel, const Point &acc)
                        : Particle(x, y, charge), mass_(mass), vel_(vel), acc_(acc) {}

    void move(Point F, unsigned int t) {
        this->acc_ = F / this->mass_;
        this->vel_ += this->acc_ * (double) t / 500.0;
        this->setPos(this->getPos() + this->vel_ * (double) t / 500.0);
    }


    [[nodiscard]] double getMass() const {
        return mass_;
    }

    [[nodiscard]] const Point &getVel() const {
        return vel_;
    }

    [[nodiscard]] const Point &getAcc() const {
        return acc_;
    }

    friend std::ofstream &operator<<(std::ofstream &os, const MovingParticle &particle) {
        os << static_cast<const Particle &>(particle) << " ";
        os << particle.vel_ << " ";
        os << particle.acc_ << " " << particle.mass_;
        return os;
    }

    friend std::ifstream &operator>>(std::ifstream &is, MovingParticle &particle) {
        is >> static_cast<Particle &>(particle)  >> particle.vel_ >> particle.acc_ >> particle.mass_;
        return is;
    }

private:
    double mass_{};
    Point vel_{};
    Point acc_{};
};


#endif //CHARGE_MOVINGPARTICLE_H
