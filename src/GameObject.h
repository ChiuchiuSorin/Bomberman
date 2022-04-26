#pragma once


#include "SDL.h"
#include "SDL_image.h"
#undef main
#include "Map.h"
#include <stdio.h>
#include<iostream>
using namespace std;
#include "Game.h"
#include "Object.h"
#include "Bomb.h"
#include "Fire.h"

#include "Collision.h"

class Player : public Object {
	//int counter;
	
public:
	bool flag = false;
	
	Bomb* bomb1;
	Player(const char* textureSheet, int x, int y);
	Player(const char* textureSheet, int x, int y, bool isAnimated) : Object(textureSheet, x, y, isAnimated) {}
	~Player() {}
	void UpdatePlayer(bool b[4]);
	void update() override
	{
	
		Object::update();
		bomb1->update();
		/*Uint32 ticks = SDL_GetTicks();
		Uint32 sprite = (ticks / 100) % 2;
		SDL_Rect rects = { sprite * 14, 0, 14, 27 };
		SDL_Rect rects2 = { 0,610, 800, 32 };*/
		
		/*if (Game::b[0])
		{
			velocity.y = -1;
			srcRect.x = 41;
			if (collision(&rects2))
				velocity.y = 1;
			Object::update();
			SDL_RenderCopy(Game::renderer, this->ObjTexture, &srcRect, &destRect);
		}
		if (Game::b[1])
		{
			if (Game::b[1] && Game::b[0])
			{
				velocity.x = -1;
				srcRect.x = 41;
				if (collision(&rects2))
					velocity.x = 1;
				Object::update();
				SDL_RenderCopy(Game::renderer, this->ObjTexture, &srcRect, &destRect);
			}
			else
			{
				speed = 1;
				velocity.x = -1;
				Object::update();
				if (collision(&rects2))
					velocity.x = 1;
				Object::update();
				SDL_RenderCopy(Game::renderer, this->ObjTexture, &rects, &destRect);
				velocity.x = -1;
				Object::update();
				if (collision(&rects2))
					velocity.x = 1;
				Object::update();
				SDL_RenderCopy(Game::renderer, this->ObjTexture, &rects, &destRect);
			}
		}
		if (Game::b[2])
		{
			velocity.y = 1;
			Object::update();
			srcRect.x = 28;
			if (collision(&rects2))
				velocity.y = -1;
			SDL_RenderCopy(Game::renderer, this->ObjTexture, &srcRect, &destRect);

		}
		if (Game::b[3])
			if (Game::b[3] && Game::b[0])
			{
				velocity.x = 1;
				Object::update();
				srcRect.x = 41;
				if (collision(&rects2))
					velocity.x = -1;
				SDL_RenderCopy(Game::renderer, this->ObjTexture, &srcRect, &destRect);
			}
			else
			{
				speed = 1;
				velocity.x = 1;
				Object::update();
				if (collision(&rects2))
					velocity.x = -1;
				Object::update();
				SDL_RenderCopy(Game::renderer, this->ObjTexture, &rects, &destRect);
				velocity.x = 1;
				Object::update();
				if (collision(&rects2))
					velocity.x = -1;
				SDL_RenderCopy(Game::renderer, this->ObjTexture, &rects, &destRect);
				destRect.x = xpos;
			}
		if (Game::b[1] == 0 && Game::b[2] == 0 && Game::b[3] == 0)
		{
			srcRect.x = 28;
			SDL_RenderCopy(Game::renderer, this->ObjTexture, &srcRect, &destRect);
		}*/
	}
	void draw(Map* map2) {
		Object::draw();
		if(flag)
			bomb1->delay++;
		if (bomb1->delay > 150)
		{
			//SDL_DestroyTexture(bomb1->ObjTexture);
			flag = false;
			bomb1->exploded = true;
			if (bomb1->exploded)
			{
				bomb1->placeFire(map2);
				bomb1->fDelay++;
				if (bomb1->fDelay > 75)
				{
					SDL_DestroyTexture(bomb1->ObjTexture);
					for (int i = 0; i < 4; i++)
					{
						SDL_DestroyTexture(bomb1->fires[i]->ObjTexture);
						bomb1->fires[i]->destRect.x = -199;
						bomb1->fires[i]->destRect.y = 200;
						bomb1->exist = false;
					}
				}
				else
				{
					for (int i = 0; i < 4; i++)
					{
						bomb1->fires[i]->draw();
					}
					if (bomb1->fireCollision(destRect))
					{
						SDL_DestroyTexture(ObjTexture);
						Game::isRunning = false;
					}
				}
			}

		}
		else
			bomb1->draw();
		
	
	}
	void init() override {
		Object::init();
		bomb1 = new Bomb("assets/bomb.png", 0,0);
		/*for (int i = 0; i < 4; i++)
			bomb1->fires[i]->init();*/
	}
	
	void Controller() {
		if (Game::e.type == SDL_KEYDOWN)
		{
			switch (Game::e.key.keysym.sym)
			{
			case SDLK_SPACE:
				cout << "space" << endl;
				if (!bomb1->exist)
				{
					bomb1->setTex("assets/bomb.png");
					bomb1->placeBomb(destRect);
					flag = true;
					bomb1->exploded = false;
					bomb1->delay = 0;
					bomb1->fDelay = 0;
					bomb1->exist = true;
					bomb1->flagf1 = true;
					bomb1->flagf2 = true;
					bomb1->flagf3 = true;
					bomb1->flagf4 = true;
				}
				break;
			case SDLK_w:
				velocity.y = -1;
				Play("up");
				break;
			case SDLK_a:
				velocity.x = -1;
				Play("left");

				break;
			case SDLK_d:
				velocity.x = 1;
				Play("right");
				break;
			case SDLK_s:
				velocity.y = 1;
				Play("down");
				break;
			default:
				break;
			}
		}

		if (Game::e.type == SDL_KEYUP)
		{
			switch (Game::e.key.keysym.sym)
			{
			case SDLK_SPACE:
				break;
			case SDLK_w:
				velocity.y = 0;
				Play("Idle");
				break;
			case SDLK_a:
				velocity.x = 0;
				Play("Idle");
				break;
			case SDLK_d:
				velocity.x = 0;
				Play("Idle");
				break;
			case SDLK_s:
				velocity.y = 0;
				Play("Idle");
				break;
			case SDLK_ESCAPE:
				Game::isRunning = false;
			default:
				break;
			}
		}
	}

	void playerCollision(SDL_Rect aux, Map* map2) {
		aux.x = xpos + velocity.x * speed;
		aux.y = ypos + velocity.y * speed;
		aux.h = collider.h;
		aux.w = collider.w;
		int flag = 1;
		map2->coll.x = 0;
		map2->coll.y = 0;
		//map2->coll.h = 28;
		//map2->coll.y = 28;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				map2->coll.x = j * 31 + 2;
				map2->coll.y = i * 30 + 2;
				/*map2->dest.x = j * 32 + 2;
				map2->dest.y = i * 30 + 2;*/
				switch (map2->map[i][j])
				{
				case 1:
					if (collision::AABB(aux, map2->coll))
					{
						//std::cout << "wall hit" << endl;
						flag = 0;
					}
					break;
				case 2:
					if (collision::AABB(aux, map2->coll))
					{
						//std::cout << "wall hit" << endl;
						flag = 0;
					}
					break;
				default:
					break;
				}
			}
		}
		if (flag)
			update();
		
	}

	/*bool fireCollision(SDL_Rect pl) {

		for (int z = 0; z < 4; z++)
		{
			if (collision::AABB(bomb1->fires[z]->destRect, pl))
			{
				return true;
			}
		}
		return false;
	}*/
};

