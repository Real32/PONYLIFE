#include "grass.h"

Grass appleObj;

Grass::Grass()
{
	background = NULL;
	apple = NULL;
}

Grass::~Grass()
{
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(apple);
}

void Grass::createBackground()
{
	background = loadImage("background.bmp", getRenderer());
	int bW, bH;
	SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
	applySurface(0, 0, background, getRenderer());

    apple = loadImage("apple.bmp", getRenderer());
    applySurface(100,100,apple,getRenderer());

	SDL_RenderPresent(getRenderer());
}
