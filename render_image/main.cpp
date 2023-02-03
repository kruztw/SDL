#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

using namespace std;

SDL_Texture *loadTexture(string file, SDL_Renderer *renderer) {
	SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());
	if (texture == nullptr) {
		printf("IMG_LoadTexture failed\n");
	}

	return texture;
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *renderer, int x, int y, int w, int h) {
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(renderer, tex, NULL, &dst);
}

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		return -1;
	}

	SDL_Window *win = SDL_CreateWindow("SDL2_Window", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		SDL_DestroyWindow(win);
		return 1;
	}

	SDL_Texture *logo = loadTexture("./logo.png", renderer);
	if (logo == nullptr) {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(win);
		IMG_Quit();
		SDL_Quit();
		return 1;
	}

	SDL_RenderClear(renderer);
	renderTexture(logo, renderer, 100, 100, 100, 100);
	SDL_RenderPresent(renderer);

	SDL_Delay(3000);
	return 0;
}
