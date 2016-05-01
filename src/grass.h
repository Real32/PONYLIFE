#ifndef GRASS_H_INCLUDED
#define GRASS_H_INCLUDED

#include "SDL2/SDL.h"
#include "renderer.h"
#include <iostream>
#include <string>

class Grass: public Renderer {
    SDL_Texture *background;
public:
    Grass();
    ~Grass();
    SDL_Texture* getBackground() { return background; }
    bool checkGrass();
    SDL_Texture* CreateBackground(SDL_Renderer *renderer);
};

#endif // GRASS_H_INCLUDED
