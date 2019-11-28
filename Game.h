#ifndef CHARGE_GAME_H
#define CHARGE_GAME_H


#include <memory>
#include "Player.h"
#include "Level.h"

class Game {
public:
    //TODO
private:
    std::shared_ptr<Player> player = nullptr;
    std::shared_ptr<Level> currentLevel = nullptr;
};


#endif //CHARGE_GAME_H
