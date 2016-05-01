#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include "player.h"

class Event: public Player {
    SDL_Event event;
public:
    void movePerson(SDL_Texture *background);
};

#endif // EVENT_H_INCLUDED
