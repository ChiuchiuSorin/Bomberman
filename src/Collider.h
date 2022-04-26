#pragma once
#include <string.h>
#include "SDL.h"
#include "Components.h"

class ColliderComponent : public Component {
public:
	SDL_Rect collider;
	//std::string tag;
	ColliderComponent(int x, int y) : Component(x, y) {}
	ColliderComponent(int x, int y, int h, int w, int sc) : Component(x, y, h, w, sc) {}

	void init() override {
		Component::init();
		collider.x = xpos;
		collider.y = ypos;
		collider.h = height;
		collider.w = width;
	}

	void update() override
	{
		Component::update();
		collider.x = xpos;
		collider.y = ypos;
		collider.h = height;
		collider.w = width;
	} 
};