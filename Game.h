#ifndef CHARGE_GAME_H
#define CHARGE_GAME_H


#include <memory>
#include <utility>
#include "Player.h"
#include "Level.h"

class Game {
public:
    Game(std::shared_ptr<Player> player, std::shared_ptr<Level> currentLevel)
            : player_(std::move(player)), currentLevel_(std::move(currentLevel)) {}

    ~Game() = default;

    void g() {}

private:
    std::shared_ptr<Player> player_ = nullptr;
    std::shared_ptr<Level> currentLevel_ = nullptr;
};


#endif //CHARGE_GAME_H
