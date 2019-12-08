#include "Level.h"
#include "Wall.h"
#include "Goal.h"

#include <utility>
#include <fstream>


Level::Level(std::string fileName) : fileName(std::move(fileName)) {
    load(fileName);
}

Level::Level(MovableParticle movableParticle, std::vector<std::shared_ptr<Collidable>> collidables) : movableParticle
                                                                                                              (std::move(
                                                                                                                      movableParticle)),
                                                                                                      collidables(
                                                                                                              std::move(
                                                                                                                      collidables)) {}

void Level::initCollidables() {
    std::shared_ptr<Level> toThis(this);
    for (auto &collidable : collidables) {
        collidable->setLevel(this);
    }
}

void Level::pushParticle(const Particle &p) {
    particleList.push_back(p);
}

void Level::popParticle() {
    if (!particleList.empty())
        particleList.pop_back();
}

Vector Level::SumForces() {
    Vector force(0, 0);
    for (const auto &particle : particleList) {
        force += particle.calculateForce(movableParticle);
    }
    return force;
}

void Level::checkCollisions() const {
    for (const auto &collidable : collidables) {
        if (collidable->didCollide(this->movableParticle)) {
            collidable->onCollide();
        }
    }
}

void Level::save(const std::string &fileName) {
    std::ofstream fout(fileName);
    fout << this->movableParticle << std::endl;
    for (const auto &collidable : collidables) {
        collidable->save(fout);
        fout << std::endl;
    }
    fout.close();
    this->fileName = fileName;
}

void Level::load(const std::string &fileName) {
    std::ifstream fin(fileName);
    fin >> movableParticle;
    std::string line;
    while (!fin.eof()) {
        fin >> line;
        if (line == "Wall") {
            std::shared_ptr<Collidable> p = std::make_shared<Wall>(0, 0, 0, 0);
            p->load(fin);
            collidables.push_back(p);
        } else if (line == "Goal") {
            std::shared_ptr<Collidable> p = std::make_shared<Goal>(0, 0, 0, 0);
            p->load(fin);
            collidables.push_back(p);
        }
    }
    fin.close();
    initCollidables();
}

const MovableParticle &Level::getMovableParticle() const {
    return movableParticle;
}

void Level::reset() {
    load(fileName);
    game->addTry();
    game->addToAllParticles(particleList.size());
}

void Level::finishLevel() {
    game->addTry();
    game->addToAllParticles(particleList.size());
    game->nextLevel();
}

void Level::ensureMovableParticliIsInside() {
    if (movableParticle.getPosition().getX() > 1280 || movableParticle.getPosition().getX() < 0 ||
        movableParticle.getPosition().getY() > 640 || movableParticle.getPosition().getY() < 0) {
        reset();
    }
}

void Level::step(double deltaTime) {
    Vector force = SumForces();
    movableParticle.move(force, deltaTime);
    checkCollisions();
    ensureMovableParticliIsInside();
}

void Level::setGame(Game *game) {
    this->game = game;
}



