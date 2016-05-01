#include "event.h"

void Event::movePerson(SDL_Texture *background)
{
   bool on = true;
	SDL_Event event;
	while(on)
	{
		while ( SDL_PollEvent(&event) )
		{ // начинаем обработку событий
			switch(event.type)
			{ // смотрим:
				case SDL_KEYDOWN:
						switch(event.key.keysym.sym)
						{
							case SDLK_ESCAPE:
									on = false;
							break;
							case SDLK_UP:
									//xrf -= 5;
							break;
							case SDLK_DOWN:
									//xrf += 5;
							break;
							case SDLK_LEFT:
									if(x==0)
										break;
									if(x<50)
									{
										std::cout << "left wall" << std::endl;
										x = 0;
									}
									else
									{
										x-=50;
									}
									SDL_RenderCopy(renderer,background, NULL, NULL);
									applySurface(x, y, person, renderer);
									std::cout << "x - " << x << std::endl;
									SDL_RenderPresent(renderer);
							break;
							case SDLK_RIGHT:
									if(x==800)
											break;
									if(800-x-92<50)
									{
										std::cout << "right wall" << std::endl;
										x = 800-92;
									}
									else
									{
										x+=50;
									}
									SDL_RenderCopy(renderer,background, NULL, NULL);
									applySurface(x, y, person, renderer);
									std::cout << "x - " << x + 92 << std::endl;
									SDL_RenderPresent(renderer);
							break;
						}
				break;
			}
		}
	}
}
