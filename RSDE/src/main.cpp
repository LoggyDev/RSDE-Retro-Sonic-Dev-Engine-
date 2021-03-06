/*Lib*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <RenderWindow.hpp>
#include <Entity.hpp>
/*Jerome Botang: Name of the engine*/
float fadein;
bool section1 = true;
bool section2 = false;
bool fading = true;
bool fadingSonic = false;
float fadingSonicin;







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

	SDL_Texture* splashTexture = window.loadTexture("res/gfx/splash.png");
	SDL_Texture* sonicTexture = window.loadTexture("res/gfx/ground.png");
	


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
			
//               Fade in code (secstion1)
		
		if(section1)
		{
			SDL_SetTextureAlphaMod(splashTexture, fadein);
			if (fading)
			{	
				fadein = fadein + 1;
				if (fadein >= 255)
				{
					fadein = 255;
					fading = false;
				}
			}
			if (!fading)
			{
				fadein = fadein - 1;
				if (fadein == 0)
				{
					fadein = 0;
					fading = false;
					section1 = false;
					section2 = true;
				}
			}
		}
		if(section2)
		{
			SDL_SetTextureAlphaMod(sonicTexture, fadingSonicin);
			fadingSonicin = fadingSonicin + 4;
			if(fadingSonicin >= 255)
			{
				fadingSonicin = 255;
			}
		}
			if(!section2)
		{
			SDL_SetTextureAlphaMod(sonicTexture, fadingSonic);
			fadingSonicin = 0;
		}
		
		
			
			
			//FPS 
			frameStart = SDL_GetTicks();
			window.clear();
			window.render(sonicTexture);
			window.render(splashTexture);
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

