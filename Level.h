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

    void addParticle(Particle &p) {
        partList.push_back(std::move(p));
    }

    void removeParticle(const Particle &p) {
        partList.remove_if([&p](const Particle& i){
            return &p == &i;
        });
    }

    void save(std::ofstream fout) const {
        fout << part << std::endl;
        fout << goal << std::endl;
        for (const auto &item : partList) {
            fout << "Particle" << std::endl;
            fout << item << std::endl;
        }
        for (const auto &wall : walls) {
            fout << "Wall" << std::endl;
            fout << wall << std::endl;
        }

    }

    void load(std::ifstream& fin) {
        fin >> part >> goal;
        std::string line;
        while (!fin.eof()) {
            std::getline(fin, line);
            if (line == "Particle") {
                Particle p;
                fin >> p;
                partList.push_back(p);
            }
            else if (line == "Wall") {
                Area wall;
                fin >> wall;
                walls.push_back(wall);
            }
        }
    }


private:
    MovingParticle part;
    Area goal;
    std::list<Particle> partList;
    std::vector<Area> walls;
};


#endif //CHARGE_LEVEL_H
