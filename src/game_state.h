// game_state.h

#ifndef _TWOCRAFT_GAME_STATE_H
#define _TWOCRAFT_GAME_STATE_H

#include <SDL2/SDL.h>

struct game_state {
	SDL_Window* window;
	SDL_Renderer* renderer;
};

int game_state_init(struct game_state* self); // Returns 0 on success
void game_state_free(struct game_state* self);

#endif
