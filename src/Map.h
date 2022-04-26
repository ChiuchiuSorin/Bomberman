#pragma once


#include "TextureManager.h"
#include "Game.h"

class Map {
public:
	Map();
	Map(const char* nivel);
	~Map() { SDL_DestroyTexture(wall);
	SDL_DestroyTexture(dirt);
	SDL_DestroyTexture(water);
	}

	void LoadMap(const char* nivel);
	void DrawMap();

	SDL_Rect src, dest, coll;
	SDL_Texture* dirt;
	SDL_Texture* wall;
	SDL_Texture* water;
	
	int map[20][25];
};