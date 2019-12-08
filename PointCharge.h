#ifndef CHARGE_POINTCHARGE_H
#define CHARGE_POINTCHARGE_H


#include "Point.h"

class PointCharge {
public:
    [[nodiscard]] virtual const Point &getPosition() const = 0;

    [[nodiscard]] virtual double getCharge() const = 0;

    [[nodiscard]] virtual double getRadius() const = 0;
};


#endif //CHARGE_POINTCHARGE_H
