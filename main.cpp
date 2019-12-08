
#include "Game.h"

int main() {
    Game g;
    std::string line;
    while (line != "exit") {
        std::cout << std::endl;
        g.printStatus();
        std::getline(std::cin, line);
        if (line == "start") {
            g.playOut();
            if (g.isGameOver())
                break;
        }
        else if (line == "part") {
            std::cout << "Please enter the X Y coordiantes and charge!" << std::endl;
            double x, y, charge;
            std::cin >> x >> y >> charge;
            std::cin.ignore(1);
            Particle p(Point(x, y), charge * 1e-5);
            g.addParticle(p);
        }
        else if (line != "exit") {
            std::cout << "Wrong command!" << std::endl;
        }
    }


    return 0;
}