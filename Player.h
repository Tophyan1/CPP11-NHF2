#ifndef CHARGE_PLAYER_H
#define CHARGE_PLAYER_H


#include <string>
#include <utility>
#include <fstream>

class Player {
public:
    Player() = default;
    ~Player() = default;

    explicit Player(std::string name, int score = 0) :score_(score), name_(std::move(name)) {}

    [[nodiscard]] int getScore() const {
        return score_;
    }

    [[nodiscard]] const std::string &getName() const {
        return name_;
    }

    void addScore(int score) {
        this->score_ += score;
    }

    friend std::ofstream &operator<<(std::ofstream &os, const Player &player) {
        os << player.score_ << player.name_;
        return os;
    }

    friend std::ifstream &operator>>(std::ifstream &is, Player &player) {
        is >> player.score_ >> player.name_;
        return is;
    }


private:
    int score_ = 0;
    std::string name_;
};


#endif //CHARGE_PLAYER_H
