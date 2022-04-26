#pragma once

#include "Game.h"
#include "Components.h"

class Controller : public ComponentBase {
public:
	void init() override {}
	void update() override {
		SDL_PollEvent(&Game::e);
		switch (Game::e.type)
		{
		case SDL_KEYDOWN:
			switch (Game::e.key.keysym.sym)
			{
			case SDLK_UP:
				Game::b[0] = 1;
				break;
			case SDLK_LEFT:
				Game::b[1] = 1;
				break;
			case SDLK_DOWN:
				Game::b[2] = 1;
				break;
			case SDLK_RIGHT:
				Game::b[3] = 1;
				break;
			}
			break;
		case SDL_KEYUP:
			switch (Game::e.key.keysym.sym)
			{
			case SDLK_UP:
				Game::b[0] = 0;
				break;
			case SDLK_LEFT:
				Game::b[1] = 0;
				break;
			case SDLK_DOWN:
				Game::b[2] = 0;
				break;
			case SDLK_RIGHT:
				Game::b[3] = 0;
				break;
			}
			break;
		default:
			break;
		}
	}
};