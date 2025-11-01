// tc_state.h

#ifndef _TWOCRAFT_STATE_H
#define _TWOCRAFT_STATE_H

#include <SDL2/SDL.h>

struct tc_state {
	SDL_Window* window;
	SDL_Renderer* renderer;
};

int tc_state_init(struct tc_state* self); // Returns 0 on success
void tc_state_free(struct tc_state* self);

#endif
