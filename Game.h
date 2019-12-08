#ifndef CHARGE_GAME_H
#define CHARGE_GAME_H


#include <string>
#include "Level.h"

class Game {
public:
    Game();

    [[nodiscard]] bool isGameOver() const;

    [[nodiscard]] bool hasMoreLevels() const;

    int getScore();

    void addTry();

    Level getCurrentLevel();

    void nextLevel();

    void addToAllParticles(unsigned int number);

    void step(double deltaTime);

    void save(const std::string &fileName);

    void load(const std::string &fileName);

    void printStatus();

    void addParticle(const Particle &p);

    void lostLevel();

    void playOut();

private:
    std::vector<Level> levels;
    size_t currentLevelIndex;
    bool gameOver = false;
    bool levelLost = false;
    unsigned int tries = 0;
    unsigned int numberOfAllParticles = 0;


    void setUpLevels();
};


#endif //CHARGE_GAME_H
