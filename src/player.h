#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "renderer.h"


class Player: public Renderer {
    int frame;
    int coordX;
    std::string file;
    int direction; // 0 - left 1 - right
    int directionNew;
protected:
    SDL_Texture *person;
    int x;
    int y;
public:
    Player();
    ~Player();
    void free();
    void render(int x, int y, SDL_Rect* clip,SDL_Renderer *renderer);
    void setX(int _x) { x = _x; }
    void setY(int _y) { y = _y; }
    int getX() { return x; }
    int getY() { return y; }
    void createPerson(SDL_Renderer *renderer,SDL_Texture *background);
    bool loadMedia(SDL_Renderer *renderer);
    bool loadMediaLeft(SDL_Renderer *renderer);
    bool loadFromFile(std::string path,SDL_Renderer *renderer);
    void animation(SDL_Renderer *renderer,SDL_Texture *background, SDL_Rect* currentClip, int state);
};

#endif // PLAYER_H_INCLUDED
