#pragma once
#include "Components.h"

class collision {
public:
	static bool AABB(SDL_Rect& rect3, SDL_Rect& rect2) {
		if (rect3.y >= rect2.y + rect2.h)
			return 0;
		if (rect3.x >= rect2.x + rect2.w)
			return 0;
		if (rect3.y + rect3.h <= rect2.y)
			return 0;
		if (rect3.x + rect3.w <= rect2.x)
			return 0;
		return 1;
	}
};