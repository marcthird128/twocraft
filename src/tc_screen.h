// tc_screen.h

#ifndef _TWOCRAFT_SCREEN_H
#define _TWOCRAFT_SCREEN_H

#include <SDL2/SDL.h>

// Number of different screen types
#define TC_SCREENCOUNT 4

struct tc_screen {
	void (*free)(struct tc_screen*);
	void* void_ptr;
};

#endif
