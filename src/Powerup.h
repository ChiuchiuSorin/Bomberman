#pragma once

#include "Object.h"

class Powerup : public Object {
public:
	Powerup() = default;

	Powerup(int x, int y, const char* textureSheet)  : Object(textureSheet, x, y) {}
	~Powerup() {}

	void init() override {
		ColliderComponent::init();
		srcRect.h = height;
		srcRect.w = width;
		srcRect.x = 0;
		srcRect.y = 0;
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w;
		destRect.h = srcRect.h;
	}
	void update() override {

	}
	void draw() override {
		Object::draw();
	}
};