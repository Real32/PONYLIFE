#ifndef GRASS_H_INCLUDED
#define GRASS_H_INCLUDED

#include "renderer.h"

class Grass: public Renderer {
    SDL_Texture *background;
    SDL_Texture *apple;
public:
    Grass();
    ~Grass();
    SDL_Texture* getBackground() { return background; }
    SDL_Texture* getApple() { return apple; }
    void createBackground();
};

#endif // GRASS_H_INCLUDED
