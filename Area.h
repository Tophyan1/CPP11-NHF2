#ifndef CHARGE_AREA_H
#define CHARGE_AREA_H


#include <fstream>

class Area {
public:
    Area() = default;

    Area(int x, int y, int height, int width) : x_(x), y_(y), height_(height), width_(width) {}

    [[nodiscard]] int getX() const {
        return x_;
    }

    [[nodiscard]] int getY() const {
        return y_;
    }

    [[nodiscard]] int getHeight() const {
        return height_;
    }

    [[nodiscard]] int getWidth() const {
        return width_;
    }

    friend std::ofstream &operator<<(std::ofstream &os, const Area &area) {
        os << area.x_ << area.y_ << area.height_ << area.width_;
        return os;
    }

    friend std::ifstream &operator>>(std::ifstream &is, Area &area) {
        is >> area.x_ >> area.y_ >> area.height_ >> area.width_;
        return is;
    }

private:
    int x_ = 0;
    int y_ = 0;
    int height_ = 0;
    int width_ = 0;

};


#endif //CHARGE_AREA_H
