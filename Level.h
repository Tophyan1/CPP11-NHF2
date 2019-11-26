#ifndef CHARGE_LEVEL_H
#define CHARGE_LEVEL_H

#include <list>
#include <vector>
#include <fstream>
#include "MovingParticle.h"


class Level {
public:
    Level() = delete;
    Level(const Level&) = delete;
    Level(Level&&) = delete;

    Level(const std::string& fileName) {
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

    void addParticle(Particle &p) {
        partList.push_back(std::move(p));
    }

    void removeParticle(const Particle &p) {
        partList.remove_if([&p](const Particle& i){
            return &p == &i;
        });
    }

    void save(std::ofstream fout) const {
        fout >> part >>
    }

    void load(std::ifstream& fin) {
        //TODO
    }


private:
    MovingParticle part;
    Area goal;
    std::list<Particle> partList;
    std::vector<Area> walls;
};


#endif //CHARGE_LEVEL_H
