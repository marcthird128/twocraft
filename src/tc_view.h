// tc_view.h

#ifndef _TWOCRAFT_VIEW_H
#define _TWOCRAFT_VIEW_H

#include <SDL2/SDL.h>
#include "tc_state.h"
#include "tc_screen.h"

struct tc_view {
	struct tc_state* state;
	struct tc_screen* screens[TC_SCREENCOUNT];
	int screen;
};

int tc_view_init(struct tc_view* self, struct tc_state* state); // 0 on fail
void tc_view_free(struct tc_view* self);
struct tc_screen* tc_view_get_screen(struct tc_view* self);

#endif
