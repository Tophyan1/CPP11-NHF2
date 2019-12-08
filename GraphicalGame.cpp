#include "GraphicalGame.h"

#include <utility>
#include <SDL.h>

GraphicalGame::GraphicalGame(Game g)
        : g(std::move(g)) {

    SDL_CreateWindowAndRenderer(1280, 720, flags, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

}

GraphicalGame::~GraphicalGame() {
    SDL_Delay(2500);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

