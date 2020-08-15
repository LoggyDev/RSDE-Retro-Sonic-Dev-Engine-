/*Lib*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
/*Header Files */
#include "RenderWindow.hpp"

double x;
double y;

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "Window failed init (dev note) Error:" << SDL_GetError() <<std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		std::cout <<"Failed to load texture. Error"<< SDL_GetError() << std::endl;
	return texture;
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}
void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_tex)
{
 	
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = 29;
	src.h = 39;



	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = 29;
	dst.h = 39;


	SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

void RenderWindow::input() {

	const Uint8 *state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_UP]) {
    	printf("Up\n");
    	
	}
	if (state[SDL_SCANCODE_DOWN]) {
    	printf("Down\n");
    	
	}
	if (state[SDL_SCANCODE_LEFT]) {
    	printf("LEFT\n");
    		
	}
	
	if (state[SDL_SCANCODE_RIGHT]) {
    	printf("right\n");
    	
    		}
};