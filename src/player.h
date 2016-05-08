#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "renderer.h"

struct ImgPath
{
    std::string ponyWalkRight;
    std::string ponyWalkLeft;
    std::string ponyStayLeft;
    std::string ponyStayRight;
};

class Player: public Renderer {
    int frame;
    int coordX;
    std::string file;
    int direction; // 0 - left 1 - right
    int WALKING_ANIMATION_FRAMES;
    SDL_Rect *gSpriteClips;
    int hungry;
    int apple;
    ImgPath *img_path;
protected:
    SDL_Texture *person;
    int x;
public:
    Player();
    ~Player();
    void free();
    void render(int x, int y, SDL_Rect* clip,SDL_Renderer *renderer);
    void createPerson(SDL_Renderer *renderer,SDL_Texture *background, SDL_Texture *appleTexture);
    bool loadMedia(SDL_Renderer *renderer);
    bool loadMediaLeft(SDL_Renderer *renderer);
    bool loadFromFile(std::string path,SDL_Renderer *renderer);
    void animation(SDL_Renderer *renderer,SDL_Texture *background, SDL_Rect* currentClip, int state,SDL_Texture *appleTexture);
};

#endif // PLAYER_H_INCLUDED
