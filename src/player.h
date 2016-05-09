#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "grass.h"

struct ImgPath
{
    std::string ponyWalkRight;
    std::string ponyWalkLeft;
    std::string ponyStayLeft;
    std::string ponyStayRight;
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
    int x;
protected:
    SDL_Texture *person;
public:
    int coordX;
    Player();
    ~Player();
    void free();
    int getDirection() { return direction; }
    void setDirection(int _direction) { direction=_direction; }
    int getX() { return x; }
    void render(int x, int y, SDL_Rect* clip,SDL_Renderer *renderer);
    void createPerson();
    bool loadMedia();
    bool loadFromFile(std::string path,SDL_Renderer *renderer);
    void animation(int state);
};

#endif // PLAYER_H_INCLUDED
