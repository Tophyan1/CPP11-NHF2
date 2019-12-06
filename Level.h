#ifndef CHARGE_LEVEL_H
#define CHARGE_LEVEL_H

#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include "MovingParticle.h"

class Level {
public:
    Level() = delete;
    Level(const Level&) = delete;
    Level(Level&&) = delete;
    ~Level() = default;

    explicit Level(const std::string& fileName) {
        std::ifstream inputFile(fileName);
        load(inputFile);
    }

    [[nodiscard]] const MovingParticle &getPart() const {
        return part;
    }

    [[nodiscard]] const Area &getGoal() const {
        return goal;
    }

    [[nodiscard]] const std::list<Particle> &getPartList() const {
        return partList;
    }

    [[nodiscard]] const std::vector<Area> &getWalls() const {
        return walls;
    }

    [[nodiscard]] unsigned int getTryNumber() const {
        return tryNumber;
    }

    [[nodiscard]] unsigned int getLevelNumber() const {
        return levelNumber;
    }

    void addParticle(Particle &p) {
        partList.push_back(std::move(p));
    }

    void removeParticle(const Particle &p) {
        partList.remove_if([&p](const Particle &i) {
            return &p == &i;
        });
    }

    [[nodiscard]] size_t numberOfParticles() const {
        return partList.size();
    }

    void addTry() {
        tryNumber++;
    }

    [[nodiscard]] int pointsUponWin() const {
        return (10 / tryNumber) * (3000 + (21 - numberOfParticles()) * 500);
    }

    [[nodiscard]] Point sumForce() const {
        Point force;
        for (const auto &item : partList) {
            force += item.exertForceTo(part);
        }
        return force;
    }

    void save(std::ofstream &fout) const {
        fout << levelNumber << " " << tryNumber << std::endl;
        fout << part << std::endl;
        fout << goal << std::endl;
        for (const auto &item : partList)
            fout << item << std::endl;
        fout << Particle(-1, -1, -1, -1) << std::endl;
        for (const auto &wall : walls)
            fout << wall << std::endl;
    }

    void load(std::ifstream& fin) {
        fin >> levelNumber >> tryNumber;
        fin >> part >> goal;
        Particle p;
        do {
            fin >> p;
            partList.push_back(p);
        } while (p != Particle(-1, -1, -1, -1));
        Area wall;
        while (!fin.eof()) {
            fin >> wall;
            walls.push_back(wall);
        }
    }

private:
    MovingParticle part;
    Area goal;
    std::list<Particle> partList;
    std::vector<Area> walls;
    unsigned int tryNumber = 0;
    unsigned int levelNumber = 0;
};

#endif //CHARGE_LEVEL_H
