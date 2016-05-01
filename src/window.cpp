#include "window.h"
#include "renderer.h"
#include "grass.h"

Window::Window()
{
    SCREEN_WIDTH = 800;
    SCREEN_HEIGHT = 365;
    window = NULL;
    game = 1;
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

void Window::rendererInit()
{
	Renderer render;
	render.createRenderer(window);
	render.initBackground();
}
