// main.c
// Main function

#include "main.h"

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Error initializing SDL: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Window* window = SDL_CreateWindow(
		"Twocraft", // Window title
		SDL_WINDOWPOS_UNDEFINED, // X Position
		SDL_WINDOWPOS_UNDEFINED, // Y Position
		256, // Width
		256, // Height
		SDL_WINDOW_FULLSCREEN_DESKTOP // Flags
	);
	if (window == NULL) {
		printf("Error creating window: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(
		window, // Window reference
		-1, // Index: -1 = choose default
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC // Flags
	);
	if (renderer == NULL) {
		printf("Error creating renderer: %s\n", SDL_GetError());
		printf("Trying to use software fallback...\n");
		renderer = SDL_CreateRenderer(
			window,
			-1, // Keep trying to not fail
			SDL_RENDERER_SOFTWARE // Software might work better
		);
		if (renderer == NULL) {
			printf("Error creating software renderer: %s\n",
				SDL_GetError());
			printf("Your computer does not seem to support Twocraft.\n");
			return -1;
		} else {
			printf("WARNING!! Using Software rendering mode!\n");
			printf("This will likely be very slow.\n");
			printf("If possible, enable acceleration.\n");
		}
		return -1;
	} else {
		SDL_Log("Setup succeeded. Using hardware acceleration.\n");
	}

	SDL_Log("Shutting down...\n");
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
