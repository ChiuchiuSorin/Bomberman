#pragma once
#include "SDL.h"
#include "Game.h"
#include "vector.h"

class ComponentBase {
public:
	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}
	virtual ~ComponentBase() {}
};

class Component : public ComponentBase {
public:
	int xpos;
	int ypos; 
	int height = 32;
	int width = 32;
	int scale = 2;
	Vector velocity;
	int speed;

	Component() { xpos = 0; ypos = 0; }
	Component(int x, int y){ xpos = x; ypos = y; }
	Component(int x, int y, int h, int w) {
		xpos = x;
		ypos = y;
		height = h;
		width = w;
	}
	Component(int x, int y, int h, int w, int sc) {
		xpos = x; 
		ypos = y; 
		height = h;
		width = w;
		scale = sc;
	}

	void init() {
		velocity.x = 0;
		velocity.y = 0;
		speed = 3;
	}

	void update() override
	{
		xpos += velocity.x * speed;
		ypos += velocity.y * speed;
	}	
};