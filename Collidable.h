#ifndef CHARGE_COLLIDABLE_H
#define CHARGE_COLLIDABLE_H


#include <memory>
#include <iostream>
#include "MovableParticle.h"
#include "Level.h"

class Level;

class Collidable {
public:
    [[nodiscard]] virtual bool didCollide(const MovableParticle &p) const = 0;

    virtual void onCollide() const = 0;

    virtual void setLevel(Level *) = 0;

    virtual void save(std::ostream &os) const = 0;

    virtual void load(std::istream &is) = 0;

};


#endif //CHARGE_COLLIDABLE_H
