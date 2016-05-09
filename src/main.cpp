#include "game.h"

int main(int argc, char** argv)
{
    Game game;
    SDL_Event event;

    if (!game.createWindow())
	{
	    std::cout << game.getDirection()<< "Error create window!" << std::endl;
        return 0;
    }
    game.createRenderer();
    game.createBackground();

    game.createPerson();

    game.animation(0);
    while(!game.getQuit())
    {if(game.getY()-5<0) { game.animation(0); break; }
        while(SDL_PollEvent(&event)!= 0)
        {
            //game.action(game.getX());
            switch(event.type)
            {
                case SDL_KEYUP:
                game.animation(0);
                break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                        {
                            case SDLK_ESCAPE:
                                game.setQuit(true);
                                break;
                            case SDLK_UP:
                                if(game.getY()<=0) { game.animation(0); break; }
                                game.animation(3);
                                break;
                            case SDLK_DOWN:
                                if(game.getY()==270) { game.animation(0); break; }
                                game.animation(4);
                                break;
                            case SDLK_LEFT:
                                if(game.getDirection()!=0) game.setDirection(0);
                                if(game.getX()-5<0) { game.animation(0); break; }
                                game.animation(1);
                                break;
                            case SDLK_RIGHT:
                                if(game.getDirection()!=1) game.setDirection(1);
                                if(game.getX()+84+5>800) { game.animation(0); break; }
                                game.animation(2);
                                break;
                        }
            break;
            }
        }
    }
    return 0;
}
