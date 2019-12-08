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
    Level level2("Level_2.txt");
    Level level3("Level_3.txt");
    Level level4("Level_4.txt");
    Level level5("Level_5.txt");
    levels.push_back(level1);
    levels.push_back(level2);
    levels.push_back(level3);
    levels.push_back(level4);
    levels.push_back(level5);
    for (auto &item : levels) {
        item.setGame(this);
    }
}

