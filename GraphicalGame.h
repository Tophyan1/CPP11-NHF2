#ifndef CHARGE_GRAPHICALGAME_H
#define CHARGE_GRAPHICALGAME_H


#include <SDL_render.h>
#include "Game.h"

class GraphicalGame {
public:
    explicit GraphicalGame(Game g);

    virtual ~GraphicalGame();

private:
    Game g;
    SDL_Window *window;
    SDL_Renderer *renderer;
    Uint32 flags = 0;
};


#endif //CHARGE_GRAPHICALGAME_H
