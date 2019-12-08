#ifndef CHARGE_LEVEL_H
#define CHARGE_LEVEL_H


#include <vector>
#include <list>
#include <string>
#include <ostream>
#include "MovableParticle.h"
#include "Collidable.h"
#include "Particle.h"
#include "Game.h"

class Game;

class Level {
public:
    explicit Level(std::string fileName);

    Level(MovableParticle particle, std::vector<std::shared_ptr<Collidable>> vector);

    [[nodiscard]] const MovableParticle &getMovableParticle() const;

    void pushParticle(const Particle &p);

    void popParticle();

    void save(const std::string &fileName);

    void load(const std::string &fileName);

    void reset();

    void finishLevel();

    void step(double deltaTime);

    void setGame(Game *game);


private:

    MovableParticle movableParticle;
    std::vector<std::shared_ptr<Collidable>> collidables;
    std::list<Particle> particleList;
    std::string fileName;
    Game *game = nullptr;

    void initCollidables();

    Vector SumForces();

    void checkCollisions() const;

    void ensureMovableParticliIsInside();
};


#endif //CHARGE_LEVEL_H
