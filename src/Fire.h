#pragma once
#include "Game.h"
#include "Components.h"
#include "Object.h"
#include "Collision.h"

class Fire : public Object {
public:

	Fire(const char* textureSheet, int x, int y) : Object(textureSheet, x, y) 
	{
		ColliderComponent::init();
		srcRect.h = height;
		srcRect.w = width;
		srcRect.x = 0;
		srcRect.y = 0;
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w * 1;
		destRect.h = srcRect.h * 1;
	}

	void init() override {
		ColliderComponent::init();
		srcRect.h = 32;
		srcRect.w = 32;
		srcRect.x = 0;
		srcRect.y = 0;
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w * 1;
		destRect.h = srcRect.h * 1;
	}
	void generateFireHeight(SDL_Rect src, int i) {
		destRect.x = src.x;
		destRect.y = src.y;
		destRect.w = 32;
		destRect.h = 8 * i;
	}
	void generateFireWidth(SDL_Rect src, int i) {
		destRect.x = src.x;
		destRect.y = src.y;
		destRect.w = 8 * i;
		destRect.h = 32;
	}
	void generateFireHeightNeg(SDL_Rect src, int i) {
		destRect.x = src.x;
		destRect.y = src.y - 6 * (i - 1);
		destRect.w = 32;
		destRect.h = 8 * i;
	}
	void generateFireWidthNeg(SDL_Rect src, int i) {
		destRect.x = src.x - 6*(i-1);
		destRect.y = src.y;
		destRect.w = 8 * i;
		destRect.h = 32;
	}
	void draw() override {
		Object::draw();
	}
};
