#include "window.h"

int main(int argc, char** argv){

    Window game;
    if (game.createWindow()==false)
	{
        return 0;
    }
		game.rendererInit();
    return 0;
}
