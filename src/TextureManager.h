#pragma once

#include "Game.h"

class TextureManager {
public:
	static SDL_Texture* LoadText(const char* fileName)
	{
		SDL_Surface* tempSurface = IMG_Load(fileName);
		SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 0, 0, 0));
		SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
		SDL_FreeSurface(tempSurface);

		return tex;
	}
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
	{
		SDL_RenderCopy(Game::renderer, tex, &src, &dest);
	}
};