#ifndef CHARGE_WALL_H
#define CHARGE_WALL_H


#include <iostream>
#include "Rectangle.h"

class Wall : public Rectangle {
public:
    Wall(double x, double y, double height, double width) : Rectangle(x, y, height, width) {}

    void save(std::ostream &os) const final {
        os << "Wall ";
        Rectangle::save(os);
    }

    void onCollide() const final {
        level->reset();
    }

};


#endif //CHARGE_WALL_H
