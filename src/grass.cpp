#include "grass.h"

Grass::Grass()
{
	background = NULL;
}

Grass::~Grass()
{
	SDL_DestroyTexture(background);
}

bool Grass::checkGrass()
{
	if (background == NULL)
	{
		return false;
	}
	return true;
}

SDL_Texture* Grass::CreateBackground(SDL_Renderer *renderer)
{
	background = loadImage("background.bmp", renderer);
	int bW, bH;
	SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
	applySurface(0, 0, background, renderer);
	return background;
}

SDL_Texture* Grass::CreateApple(SDL_Renderer *renderer)
{
	apple = loadImage("apple.bmp", renderer);
	int bW, bH;
	SDL_QueryTexture(apple, NULL, NULL, &bW, &bH);
	applySurface(100, 100, apple, renderer);
	return apple;
}
