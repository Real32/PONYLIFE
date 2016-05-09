#include "player.h"

Player gSpriteSheetTexture;



Player::Player()
{
    mWidth = 0;
    mHeight = 0;
	person = NULL;
	frame = 0;
	coordX = 0;
	file = "";
	direction = 1;
	x = 0;
	hungry = 16;
	WALKING_ANIMATION_FRAMES = 16;
	currentClip = &gSpriteClips[ 0 / 2 ];
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

void Player::createPerson()
{
	if(!loadMedia())
	{
		std::cout << "Failed to load media!" << std::endl;
	}
}

void Player::animation(int state)
{
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
    }
    if( !gSpriteSheetTexture.loadFromFile(file,getRenderer()))
    {
			std::cout << "Failed to load walking animation texture!\n" << std::endl;
    }
    SDL_SetRenderDrawColor(getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderCopy(getRenderer(),getBackground(), NULL, NULL);
    currentClip = &gSpriteClips[ frame / 2 ];
    x = ( SCREEN_WIDTH - currentClip->w + coordX ) / 2;
    gSpriteSheetTexture.render(x, 270 , currentClip,getRenderer());
    SDL_RenderPresent(getRenderer());
    ++frame;
    hungry--;
    if(!hungry) { std::cout << "I AM HUNGRY" << std::endl; hungry = 32;}
    if( frame / 2 >= WALKING_ANIMATION_FRAMES )
    {
			frame = 0;
    }
}

bool Player::loadMedia()
{
	bool success = true;
	int frameStep = 0;
	frameStep = 0;
	for(int i = 0; i < 16; ++i)
	{
		gSpriteClips[i].x =   frameStep;
		gSpriteClips[i].y =   0;
		gSpriteClips[i].w =  84;
		gSpriteClips[i].h =  84;
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
