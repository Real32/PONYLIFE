#include "renderer.h"

Renderer::Renderer()
{
    renderer = NULL;
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
}

bool Renderer::createRenderer()
{
    renderer = SDL_CreateRenderer(getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
		{
			std::cout << "CreateRenderer. " << SDL_GetError() << std::endl;
      return false;
    }
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(renderer);
    return true;
}

SDL_Texture* Renderer::loadImage(std::string file, SDL_Renderer *renderer)
{
    SDL_Surface *loadedImage = NULL;
    SDL_Texture *texture = NULL;
    loadedImage = SDL_LoadBMP(file.c_str());
    SDL_SetColorKey(loadedImage, 24 | SDL_RLEACCEL, SDL_MapRGB(loadedImage->format, 255, 0, 210));
    if (loadedImage != NULL)
    {
        texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    else
    {
        std::cout << SDL_GetError() << std::endl;
    }
    return texture;
}

void Renderer::applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend){
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(rend, tex, NULL, &pos);
}
