#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "grass.h"

struct ImgPath
{
    std::string ponyWalkRight;
    std::string ponyWalkLeft;
    std::string ponyStayRight;
    std::string ponyStayLeft;
    std::string ponyFlyRight;
    std::string ponyFlyLeft;
};

class Player: public Grass {
    int mWidth;
    int mHeight;
    int frame;

    std::string file;
    SDL_Rect *gSpriteClips;
    int WALKING_ANIMATION_FRAMES;
    int hungry;
    ImgPath *img_path;
    SDL_Rect* currentClip;
    int direction; // 0 - left 1 - right
    bool fly; // 0 - stay 1 - fly
    int x;
    int y;
protected:
    SDL_Texture *person;
public:
    int coordX;
    int coordY;
    Player();
    ~Player();
    void free();
    int getDirection() { return direction; }
    void setDirection(int _direction) { direction = _direction; }
    int getFly() { return fly; }
    void setFly(int _fly) { fly = _fly; }
    int getX() { return x; }
    int getY() { return y; }
    void render(int x, int y, SDL_Rect* clip,SDL_Renderer *renderer);
    void createPerson();
    bool loadMedia();
    bool loadFromFile(std::string path,SDL_Renderer *renderer);
    void animation(int state);
};

#endif // PLAYER_H_INCLUDED
