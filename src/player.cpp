#include "player.h"

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
	x = 0;
	hungry = 16;
	apple = 3;
	WALKING_ANIMATION_FRAMES = 16;
	gSpriteClips = new SDL_Rect[WALKING_ANIMATION_FRAMES];
    img_path = new ImgPath;
	img_path->ponyWalkLeft = "PonyLeftWalk.bmp";
	img_path->ponyWalkRight = "PonyRightWalk.bmp";
	img_path->ponyStayLeft = "PonyLeft.bmp";
	img_path->ponyStayRight = "PonyRight.bmp";

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
		delete[] gSpriteClips;
		delete &img_path;
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

void Player::createPerson(SDL_Renderer *renderer,SDL_Texture *background, SDL_Texture *appleTexture)
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
		animation(renderer,background,currentClip,0,appleTexture);
		//applySurface(100,100,appleTexture,renderer);
		//SDL_RenderPresent( renderer );
		while( !quit )
		{

			while( SDL_PollEvent( &event ) != 0 )
			{
				switch(event.type)
				{
					case SDL_KEYUP:
					animation(renderer,background,currentClip,0,appleTexture);
					break;
					case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                            {
                                case SDLK_ESCAPE:
                                        quit = true;
                                        break;
                                case SDLK_LEFT:
                                        if(direction!=0) direction = 0;
                                        if(x-5<0) { animation(renderer,background,currentClip,0,appleTexture); break; }
                                        animation(renderer, background,currentClip,1,appleTexture);
                                        break;
                                case SDLK_RIGHT:
                                        if(direction!=1) direction = 1;
                                        if(x+84+5>800) { animation(renderer,background,currentClip,0,appleTexture); break; }
                                        animation(renderer, background,currentClip,2,appleTexture);
                                        break;
                            }
				break;
				}
			}
		}
	}
}

void Player::animation(SDL_Renderer *renderer, SDL_Texture *background,SDL_Rect* currentClip, int state, SDL_Texture *appleTexture)
{
    //SDL_RenderClear(renderer);

    switch(state)
		{
			case 0:
					if(direction==0)
							file = img_path->ponyStayLeft;
					if(direction==1)
							file = img_path->ponyStayRight;
					frame = 0;
					break;
			case 1:
					file = img_path->ponyWalkLeft;
					coordX = coordX - 10;
					break;
			case 2:
					file = img_path->ponyWalkRight;
					coordX = coordX + 10;
					break;
            case 3:
                    file = "apple.bmp";
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
    x = ( SCREEN_WIDTH - currentClip->w + coordX ) / 2;
    gSpriteSheetTexture.render(x, 270 , currentClip,renderer);
    SDL_RenderPresent( renderer );
    ++frame;
    hungry--;
    if(!hungry) { std::cout << "I AM HUNGRY" << std::endl; hungry = 32;}
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
		newTexture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
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
