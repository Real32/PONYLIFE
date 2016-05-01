#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include "SDL2/SDL.h"
#include "window.h"
#include <iostream>
#include <string>

class Renderer: public Window {
protected:
    SDL_Renderer *renderer;
public:
    Renderer();
    ~Renderer();
    SDL_Renderer* getRenderer() { return renderer; }
    bool createRenderer(SDL_Window *window);
    SDL_Texture* loadImage(std::string file, SDL_Renderer *renderer);
    void applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
    void initBackground();
    void initPerson(SDL_Texture *background);
    void Game();
};

#endif // RENDERER_H_INCLUDED
