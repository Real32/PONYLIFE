#include "player.h"

Player gSpriteSheetTexture;

Player::Player()
{
    x = 0;
    y = 270;
    coordX = 0;
    coordY = 0;

    mWidth = 0;
    mHeight = 0;

	file = "";
	direction = 1;
	fly = false;
	hungry = 16;

	person = NULL;
	frame = 0;
	WALKING_ANIMATION_FRAMES = 16;
	gSpriteClips = new SDL_Rect[WALKING_ANIMATION_FRAMES];
	currentClip = &gSpriteClips[ 0 / 2 ];

    img_path = new ImgPath;
	img_path->ponyWalkRight = "PonyRightWalk.bmp";
	img_path->ponyWalkLeft = "PonyLeftWalk.bmp";
	img_path->ponyStayRight = "PonyRight.bmp";
	img_path->ponyStayLeft = "PonyLeft.bmp";
	img_path->ponyFlyRight = "PonyRightFly.bmp";
	img_path->ponyFlyLeft = "PonyLeftFly.bmp";
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
    int step = 2;
    switch(state)
		{
			case 0:
					if(direction==0)
					{
                        if(fly!=true)
							file = img_path->ponyStayLeft;
                        else
                            file = img_path->ponyFlyLeft;
					}
					if(direction==1)
                    {
						if(fly!=true)
							file = img_path->ponyStayRight;
                        else
                            file = img_path->ponyFlyRight;
                    }
					frame = 0;
					break;
			case 1:

                    if(fly!=true) file = img_path->ponyWalkLeft;
                    else file = img_path->ponyFlyLeft;
					coordX = coordX - 10;
					break;
			case 2:
                    if(fly!=true) file = img_path->ponyWalkRight;
					else file = img_path->ponyFlyRight;
					coordX = coordX + 10;
					break;
            case 3:
                    if(direction==0)
							file = img_path->ponyFlyLeft;
					if(direction==1)
							file = img_path->ponyFlyRight;
                    coordY-=5;
                    break;
            case 4:
                    if(direction==0)
							file = img_path->ponyFlyLeft;
					if(direction==1)
							file = img_path->ponyFlyRight;
                    coordY+=5;
                    break;
            case 5:
                    if(direction==0)
							file = img_path->ponyFlyLeft;
					if(direction==1)
							file = img_path->ponyFlyRight;
                    coordY+=0;
                    step = 4;
                    break;
    }
    if(!gSpriteSheetTexture.loadFromFile(file,getRenderer()))
    {
			std::cout << "Failed to load walking animation texture!\n" << std::endl;
    }
    SDL_SetRenderDrawColor(getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderCopy(getRenderer(),getBackground(), NULL, NULL);
    currentClip = &gSpriteClips[ frame / step];
    x = ( SCREEN_WIDTH - currentClip->w + coordX ) / 2;
    y = 270 + coordY;
    gSpriteSheetTexture.render(x, y , currentClip,getRenderer());
    SDL_RenderPresent(getRenderer());
    ++frame;
    hungry--;
    if(!hungry) { std::cout << "I AM HUNGRY" << std::endl; hungry = 32;}
    if( frame / step >= WALKING_ANIMATION_FRAMES )
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
		SDL_FreeSurface(loadedSurface);
	}
	person = newTexture;
	return person != NULL;
}
