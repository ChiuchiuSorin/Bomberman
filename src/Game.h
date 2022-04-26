#pragma once


#include "SDL.h"
#include "SDL_image.h"
#undef main
#include <stdio.h>
#include<iostream>
using namespace std;


class Game {
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, const char* nivel);
	void HandleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }
	void setLvl() { cin >> lvl; }
	int whatLvl() { return lvl; }

	static SDL_Renderer* renderer;
	static SDL_Event e;
	static bool isRunning;
	static int lvl;
	static int nrInamici;
	int choose = 0;
	bool again = true;
private:
	SDL_Window* window;
};

