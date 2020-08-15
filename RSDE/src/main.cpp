/*Lib*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <RenderWindow.hpp>
#include <Entity.hpp>
/*Jerome Botang: Name of the engine*/

int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime; 
	/*if error get error*/
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_INIT HAS FAILED. SDL_ERROR: " << SDL_GetError () << std::endl;
	/*if error get error*/
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_INIT HAS FAILED. SDL_IMG_ERROR: " << SDL_GetError () << std::endl;
	RenderWindow window("RSDE 2.0", 424, 240);
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
			//FPS 
			frameStart = SDL_GetTicks();

			window.clear();
			window.render(grassTexture);
			window.input();
			window.display();

			//FPS
			frameTime = SDL_GetTicks() - frameStart;
			if(frameDelay > frameTime)
			{
				SDL_Delay(frameDelay - frameTime);
			}
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}