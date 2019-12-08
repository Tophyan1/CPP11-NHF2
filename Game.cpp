#include <fstream>
#include "Game.h"

Game::Game() {
    currentLevelIndex = 0;
    setUpLevels();
}

bool Game::isGameOver() const {
    return this->gameOver;
}

bool Game::hasMoreLevels() const {
    return currentLevelIndex < levels.size() - 1;
}

int Game::getScore() {
    return (50 / tries) * (30000 + (210 - numberOfAllParticles) * 500);
}

void Game::addTry() {
    this->tries += 1;
}

Level Game::getCurrentLevel() {
    return levels[currentLevelIndex];
}

void Game::nextLevel() {
    if (hasMoreLevels()) {
        currentLevelIndex++;
    } else {
        gameOver = true;
    }
}

void Game::addToAllParticles(unsigned int number) {
    this->numberOfAllParticles += number;
}

void Game::step(double deltaTime) {
    levels[currentLevelIndex].step(deltaTime);
}

void Game::save(const std::string &fileName) {
    std::ofstream fout(fileName);
    fout << currentLevelIndex << " " << tries << " " << numberOfAllParticles << std::endl;
    fout.close();
}

void Game::load(const std::string &fileName) {
    std::ifstream fin(fileName);
    fin >> currentLevelIndex >> tries >> numberOfAllParticles;
    setUpLevels();
    gameOver = false;
    fin.close();
}

void Game::setUpLevels() {
    Level level1("Level_1.txt");

    levels.push_back(level1);

    for (auto &item : levels) {
        item.setGame(this);
    }
}

void Game::printStatus() {
    std::cout << "Your particle is at: " << levels[currentLevelIndex].getMovableParticle().getPosition() << std::endl;
    levels[currentLevelIndex].printParts();
    std::cout << "To start the game, type [start]\n"
                 "To place a particle, type [part]\n"
                 "To exit, type [exit]\n";
}

void Game::addParticle(const Particle &p) {
    levels[currentLevelIndex].pushParticle(p);
}

void Game::playOut() {
    while(true) {
        step(0.02);
        if (levelLost || gameOver)
            break;
    }
    levelLost = false;

}

void Game::lostLevel() {
    levelLost = true;
}
