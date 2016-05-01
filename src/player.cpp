#include "player.h"
#include "event.h"

const int WALKING_ANIMATION_FRAMES = 16;
SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];
Player gSpriteSheetTexture;

int mWidth = 0;
int mHeight = 0;

Player::Player()
{
	person = NULL;
	frame = 0;
	coordX = 0;
	file = "";
	direction = 1;
	directionNew = 0;
	x = 0;
	y = 0;
}

Player::~Player()
{
	free();
}

void Player::free()
{
	if( person != NULL )
	{
		SDL_DestroyTexture(person);
		person = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Player::render( int x, int y, SDL_Rect* clip,SDL_Renderer *renderer)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopy( renderer, person, clip, &renderQuad );
}

void Player::createPerson(SDL_Renderer *renderer,SDL_Texture *background)
{
	SDL_Rect* currentClip = &gSpriteClips[ 0 / 2 ];
	bool quit = false;
	SDL_Event event;
	if(!loadMedia(renderer))
	{
		std::cout << "Failed to load media!" << std::endl;
	}
	else
	if(1)
	{
		animation(renderer,background,currentClip,0);
		SDL_RenderPresent( renderer );
		while( !quit )
		{
			while( SDL_PollEvent( &event ) != 0 )
			{
				switch(event.type)
				{
					case SDL_KEYUP:
					animation(renderer,background,currentClip,0);
					break;
					case SDL_KEYDOWN:
							switch(event.key.keysym.sym)
								{
									case SDLK_ESCAPE:
											quit = true;
											break;
									case SDLK_LEFT:
											//loadMedia(renderer);
											animation(renderer, background,currentClip,1);
											if(direction!=0) { direction = 0;
											std::cout << "direction - " << direction << std::endl; }
											break;
									case SDLK_RIGHT:
											//loadMedia(renderer);
											animation(renderer, background,currentClip,2);
											if(direction!=1) { direction = 1;
											std::cout << "direction - " << direction << std::endl; }
											break;
								}
				break;
				}
			}
		}
	}
}

void Player::animation(SDL_Renderer *renderer, SDL_Texture *background,SDL_Rect* currentClip, int state)
{
    switch(state)
		{
			case 0:
					std::cout << "direction " << direction << std::endl;
					if(direction==0)
							file = "C:/Users/Realism32/Documents/ExlipseProjects/IamRainbow/src/PonyLeft.bmp";
					if(direction==1)
							file = "C:/Users/Realism32/Documents/ExlipseProjects/IamRainbow/src/PonyRight.bmp";
					frame = 0;
					break;
			case 1:
					file = "C:/Users/Realism32/Documents/ExlipseProjects/IamRainbow/src/PonyLeftWalk.bmp";
					coordX = coordX - 10;
					break;
			case 2:
					file = "C:/Users/Realism32/Documents/ExlipseProjects/IamRainbow/src/PonyRightWalk.bmp";
					coordX = coordX + 10;
					break;
    }
    if( !gSpriteSheetTexture.loadFromFile( file,renderer ) )
    {
			std::cout << "Failed to load walking animation texture!\n" << std::endl;
    }
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderCopy(renderer,background, NULL, NULL);
    currentClip = &gSpriteClips[ frame / 2 ];
    gSpriteSheetTexture.render( ( SCREEN_WIDTH - currentClip->w + coordX ) / 2, 270 , currentClip,renderer);
    SDL_RenderPresent( renderer );
    ++frame;
    if( frame / 2 >= WALKING_ANIMATION_FRAMES )
    {
			frame = 0;
    }
}

bool Player::loadMedia(SDL_Renderer *renderer)
{
	bool success = true;
	int frameStep = 0;
	frameStep = 0;
	for(int i = 0; i < 16; ++i)
	{
		gSpriteClips[ i ].x =   frameStep;
		gSpriteClips[ i ].y =   0;
		gSpriteClips[ i ].w =  84;
		gSpriteClips[ i ].h =  84;
		frameStep+=84;
	}
	return success;
}

bool Player::loadFromFile( std::string path,SDL_Renderer *renderer)
{
	free();
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	if( loadedSurface == NULL )
	{
		std::cout << "Unable to load image! SDL_image Error: " << path.c_str() << std::endl;
	}
	else
	{
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 255, 0, 210 ) );
		newTexture = SDL_CreateTextureFromSurface(renderer,loadedSurface );
		if( newTexture == NULL )
		{
			std::cout << "Unable to create texture from! SDL Error: " << path.c_str() << std::endl;
			std::cout << "Renderer " << getRenderer() << std::endl;
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface( loadedSurface );
	}
	person = newTexture;
	return person != NULL;
}
