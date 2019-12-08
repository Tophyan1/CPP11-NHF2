#ifndef CHARGE_GOAL_H
#define CHARGE_GOAL_H


#include <iostream>
#include "Rectangle.h"

class Goal : public Rectangle {
public:
    Goal(double x, double y, double height, double width) : Rectangle(x, y, height, width) {}

    void save(std::ostream &os) const final {
        os << "Goal ";
        Rectangle::save(os);
    }

    void onCollide() const final {
        level->finishLevel();
    }

};


#endif //CHARGE_GOAL_H
