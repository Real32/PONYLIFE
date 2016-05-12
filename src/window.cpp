#include "window.h"

Window::Window()
{
    window = NULL;
}

Window::~Window()
{
	SDL_DestroyWindow(window);
}

bool Window::createWindow()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		{
			std::cout << SDL_GetError() << std::endl;
			return false;
    }
    window = SDL_CreateWindow("I'm rainbow!", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
		{
			std::cout << SDL_GetError() << std::endl;
			return false;
    }
    return true;
}
