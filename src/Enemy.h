#pragma once
#include "Game.h"
#include "Object.h"

class Enemy : public Object {
private:
	bool isDead = false;
public:
	int xvit, yvit;
	
	Enemy(const char* textureSheet, int x, int y, int xv, int yv ):Object(textureSheet, x, y) {
		xvit = xv;
		yvit = yv;
	}
	void init() override {
		Object::init();
	}
	void update() override {
		Object::update();
		velocity.x = xvit;
		velocity.y = yvit;
		srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / 300) % 2);
		if (isDead)
		{
			collider.x = -400;
			collider.y = -600;
		}
		srcRect.y = 0;
		destRect.w = srcRect.w * 2;
		destRect.h = srcRect.h * 2;

	}
	void setDead() { isDead = true; }
	bool getDead() { return isDead; }
	void draw() override {
		Object::draw();
	}
	void collisionEnemy(SDL_Rect aux, Map* map2)
	{
		update();
		aux.x = xpos + velocity.x * speed;
		aux.y = ypos + velocity.y * speed;
		aux.h = collider.h;
		aux.w = collider.w;
		int flag = 0;
		map2->coll.x = 0;
		map2->coll.y = 0;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				map2->coll.x = j * 32 + 2;
				map2->coll.y = i * 30 + 2;
				map2->dest.x = j * 32 + 2;
				map2->dest.y = i * 30 + 2;
				switch (map2->map[i][j])
				{
				case 1:
					if (collision::AABB(aux, map2->coll))
					{
						//std::cout << "wall hit" << endl;
						flag = 1;
					}
					break;
				case 2:
					if (collision::AABB(aux, map2->coll))
					{
						//std::cout << "wall hit" << endl;
						flag = 1;
					}
					break;
				default:
					break;
				}
			}
		}
		if (flag)
		{
			xvit = xvit * -1;
			yvit = yvit * -1;
		}
	}
};
