#include "SDL2/SDL.h"

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		return -1;
	}

	SDL_Window *win = SDL_CreateWindow("SDL2_Window", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		SDL_Quit();
		return 1;
	}

	SDL_Delay(3000);
	return 0;
}
