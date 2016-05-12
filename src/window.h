#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

//#include "SDL2/SDL.h"
#include "SDL.h"
#include <iostream>
#include <string>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 365

class Renderer;
class Grass;
class Player;
class Game;

struct Path {
    SDL_Texture *personRight;
};

class Window {
    SDL_Window *window;

public:
    Window();
    ~Window();
    SDL_Window* getWindow() {return window;}
    bool createWindow();
};

#endif // WINDOW_H_INCLUDED
