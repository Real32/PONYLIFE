#include "grass.h"

Grass::Grass()
{
	background = NULL;
}

Grass::~Grass()
{
	SDL_DestroyTexture(background);
}

void Grass::createBackground()
{
	background = loadImage("background.bmp", getRenderer());
	int bW, bH;
	SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
	applySurface(0, 0, background, getRenderer());
	SDL_RenderPresent(getRenderer());
}
