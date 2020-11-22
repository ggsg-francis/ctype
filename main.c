//#pragma comment(lib, "../libraries/sdlincl/lib/SDL2main.lib")
//#pragma comment(lib, "../libraries/sdlincl/lib/SDL2.lib")

#define SDL_MAIN_HANDLED

//#include <SDL.h>

#include "isdl\SDL.h"

#define ARCHIVER_WINDOW_W 800
#define ARCHIVER_WINDOW_H 600

SDL_Window* sdl_window;
SDL_Surface* sdl_surface;

void CTClear(int r, int g, int b, int a)
{
	SDL_FillRect(sdl_surface, 0, r + (g << 8) + (b << 16));
}

void CTDrawPixel(int x, int y, int r, int g, int b, int a)
{
	int bpp = sdl_surface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)sdl_surface->pixels + y * sdl_surface->pitch + x * bpp;

	*((Uint32*)p) = r + (g << 8) + (b << 16);
}

int main(int argc, char * argv[])
{
	//-------------------------------- INITIALIZE SDL2

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_JOYSTICK) != 0)
		return 0;

	sdl_window = SDL_CreateWindow("C-TYPE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		ARCHIVER_WINDOW_W, ARCHIVER_WINDOW_H, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN); // Create window
	if (!sdl_window) return -1; // Die if creation failed

	//-------------------------------- RENDERER SETUP

	sdl_surface = SDL_GetWindowSurface(sdl_window);

	//-------------------------------- MAIN LOOP

	CTClear(0, 0, 0, 0);

	CTDrawPixel(32, 32, 255, 255, 255, 255);
	CTDrawPixel(32, 33, 255, 255, 255, 255);
	CTDrawPixel(32, 34, 255, 255, 255, 255);

	SDL_UpdateWindowSurface(sdl_window);

	SDL_Delay(5000);

	//-------------------------------- END PROGRAM

	SDL_DestroyWindow(sdl_window);
	SDL_Quit();

	return 0; // Goodbye
}
