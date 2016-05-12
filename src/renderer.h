#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include "window.h"

class Renderer: public Window {
    SDL_Renderer *renderer;
public:
    Renderer();
    ~Renderer();
    SDL_Renderer* getRenderer() { return renderer; }
    bool createRenderer();
    SDL_Texture* loadImage(std::string file, SDL_Renderer *renderer);
    void applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
};

#endif // RENDERER_H_INCLUDED
