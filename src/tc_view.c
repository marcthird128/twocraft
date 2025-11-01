// tc_view.c
// Metadata for the game (client) view

#include "tc_view.h"

int tc_view_init(struct tc_view* self, struct tc_state* state) {
	self->state = state;
	self->screen = 0;
	self->screens[0] = NULL;

	return 0;
}

void tc_view_free(struct tc_view* self) {
	// TODO: Create cleanup
}

struct tc_screen* tc_view_get_screen(struct tc_view* self) {
	return self->screens[self->screen];
}
