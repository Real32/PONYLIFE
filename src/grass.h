#ifndef GRASS_H_INCLUDED
#define GRASS_H_INCLUDED

//#include "SDL2/SDL.h"
#include "SDL.h"
#include "renderer.h"
#include <iostream>
#include <string>

class Grass: public Renderer {
    SDL_Texture *background;
    SDL_Texture *apple;
public:
    Grass();
    ~Grass();
    SDL_Texture* getBackground() { return background; }
    bool checkGrass();
    SDL_Texture* CreateBackground(SDL_Renderer *renderer);
    SDL_Texture* CreateApple(SDL_Renderer *renderer);
};

#endif // GRASS_H_INCLUDED
