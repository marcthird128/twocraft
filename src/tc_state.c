// tc_state.c
// tc_state struct: handles game state and core stuff

#include "tc_state.h"

int tc_state_init(struct tc_state* self) {
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
		"Initializing Twocraft...\n");
	// 1. Create window
	self->window = SDL_CreateWindow(
		"Twocraft", // Title
		SDL_WINDOWPOS_UNDEFINED, // X position
		SDL_WINDOWPOS_UNDEFINED, // Y position
		256, // Width
		256, // Height
		SDL_WINDOW_FULLSCREEN_DESKTOP // Flags
	);
	if (self->window == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"twocraft: tc_state_init: SDL_CreateWindow failed: %s",
			SDL_GetError());
		return 1;
	}

	// 2. Create renderer
	self->renderer = SDL_CreateRenderer(
		self->window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	if (self->renderer == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"twocraft: tc_state_init: SDL_CreateRenderer failed: %s",
			SDL_GetError());
		return 2;
	}

	return 0;
}

void tc_state_free(struct tc_state* self) {
	if (self->renderer != NULL) {
		SDL_DestroyRenderer(self->renderer);
	}
	if (self->window != NULL) {
		SDL_DestroyWindow(self->window);
	}
}
