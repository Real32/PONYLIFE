#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

//#include "SDL2/SDL.h"
#include "SDL.h"
#include <iostream>
#include <string>

struct Path {
    SDL_Texture *personRight;
};

class Window {
    bool game;
public:
    Window();
    ~Window();
    int  getSCREEN_WIDTH() { return SCREEN_WIDTH; }
    int  getSCREEN_HEIGHT() { return SCREEN_HEIGHT; }
    bool getGame() { return game; }
    void setGame(bool _game) { game = _game; }
    bool createWindow();
    void rendererInit();
protected:
    SDL_Window *window;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
};

#endif // WINDOW_H_INCLUDED
