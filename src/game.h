#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "player.h"

class Game: public Player {
	bool quit;
	int LEFT_WALL;
	int RIGHT_WALL;
public:
    Game();
    bool getQuit() { return quit; }
    void setQuit(bool _quit) { quit = _quit; }
    void action(int x);
};

#endif // GAME_H_INCLUDED
