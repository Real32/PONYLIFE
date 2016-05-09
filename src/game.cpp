#include "game.h"

Game::Game()
{
    quit = false;
    LEFT_WALL = 0;
    RIGHT_WALL = SCREEN_WIDTH;
}

void Game::action(int x)
{
    std::cout << x << std::endl;
}
