/*Lib*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <RenderWindow.hpp>
#include <Entity.hpp>
/*Jerome Botang: Name of the engine*/

int main(int argc, char *argv[])
{
	/*if error get error*/
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_INIT HAS FAILED. SDL_ERROR: " << SDL_GetError () << std::endl;
	/*if error get error*/
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_INIT HAS FAILED. SDL_IMG_ERROR: " << SDL_GetError () << std::endl;
	RenderWindow window("retro-dev-engine v0.1", 1280, 720);
	/*Loading ground texture */

	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground.png");

	/*Game is running */
	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

			window.clear();
			window.render(grassTexture);
			window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}