// tc_main.c
// Main function

#include "tc_main.h"

int main() {
	// 1. Init SDL
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
		"Starting Twocraft...");
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"twocraft: main: SDL_Init failed: %s",
			SDL_GetError());
		goto error;
	}

	// 2. Create game state
	struct tc_state state;
	if (tc_state_init(&state)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
			"twocraft: main: tc_state_init failed");
		goto error;
	}
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
		"Twocraft started.");

	// Shut down
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
		"Shutting down Twocraft...");
	tc_state_free(&state);
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
		"Goodbye!");
	return 0;

	// Error handler
	error:
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"\n");
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"===================================");
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"Twocraft encountered a fatal error.");
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"Please copy all program logs when");
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"reporting a crash.");
	return -1;
}
