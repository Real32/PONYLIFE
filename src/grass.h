#ifndef GRASS_H_INCLUDED
#define GRASS_H_INCLUDED

#include "renderer.h"

class Grass: public Renderer {
    SDL_Texture *background;
public:
    Grass();
    ~Grass();
    SDL_Texture* getBackground() { return background; }
    void createBackground();
};

#endif // GRASS_H_INCLUDED
