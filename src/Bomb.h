#pragma once
#include "Game.h"
#include "Components.h"
#include "Object.h"
#include "Fire.h"

class Bomb : public Object{
public:
	int delay = 0;
	int fDelay = 0;
	bool exploded = false;
	bool exist = false;
	Fire* fires[4];

	Bomb(const char* textureSheet, int x, int y) : Object(textureSheet, x, y) {
		for (int i = 0; i < 4; i++)
		{
			fires[i] = new Fire("assets/fire.png", destRect.x, destRect.y);
			fires[i]->init();
		}
	}
	~Bomb() { Object::~Object(); }

	void draw() override {
		Object::draw();

	}
	void update() override {
		srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / 300) % 3);

		srcRect.y = 0;
		destRect.w = srcRect.w * 1;
		destRect.h = srcRect.h * 1;
	}
	void placeBomb (SDL_Rect r) {
		init();
		/*srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / 300) % 3);

		srcRect.y = 0;*/

		destRect.x = r.x+12;
		destRect.y = r.y+12;
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
	

	bool flagf1 = true;
	bool flagf2 = true;
	bool flagf3 = true;
	bool flagf4 = true;
	void placeFire(Map* map2) {
		if (exploded)
		{
			map2->coll.x = 0;
			map2->coll.y = 0;
			for (int i = 0; i < 4; i++)
			{
				fires[i]->setTex ("assets/fire.png");
			}

			for (int u = 0; u < 9; u++)
			{
				if (flagf1)
					fires[0]->generateFireHeightNeg(destRect, u * 2);
				if (flagf2)
					fires[1]->generateFireHeight(destRect, u * 2);
				if (flagf3)
					fires[2]->generateFireWidthNeg(destRect, u * 2);
				if (flagf4)
					fires[3]->generateFireWidth(destRect, u * 2);
				/*if (!flagf1)
					fires[0]->generateFireHeightNeg(destRect, (u - 1) * 2);
				if (!flagf2)
					fires[1]->generateFireHeight(destRect, (u - 1) * 2);
				if (!flagf3)
					fires[2]->generateFireWidthNeg(destRect, (u - 1) * 2);
				if (!flagf4)
					fires[3]->generateFireWidth(destRect, (u - 1) * 2);*/
				
				for (int i = 0; i < 20; i++)
				{
					for (int j = 0; j < 25; j++)
					{
						map2->coll.x = j * 32 + 2;
						map2->coll.y = i * 32 + 2;
						map2->dest.x = j * 32 + 2;
						map2->dest.y = i * 30 + 2;
						switch (map2->map[i][j])
						{
						case 2:

							if (collision::AABB(map2->coll, fires[0]->destRect))
							{

								TextureManager::Draw(map2->water, map2->src, map2->dest);
								map2->map[i][j] = 0;
								std::cout << "wall hit" << endl;
								flagf1 = false;

							}

							if (collision::AABB(map2->coll, fires[1]->destRect))
							{

								TextureManager::Draw(map2->water, map2->src, map2->dest);
								map2->map[i][j] = 0;
								std::cout << "wall hit" << endl;
								flagf2 = false;

							}

							if (collision::AABB(map2->coll, fires[2]->destRect))
							{

								TextureManager::Draw(map2->water, map2->src, map2->dest);
								map2->map[i][j] = 0;
								std::cout << "wall hit" << endl;
								flagf3 = false;

							}

							if (collision::AABB(map2->coll, fires[3]->destRect))
							{

								TextureManager::Draw(map2->water, map2->src, map2->dest);
								map2->map[i][j] = 0;
								std::cout << "wall hit" << endl;
								flagf4 = false;

							}

							break;
						case 1:
							if (collision::AABB(map2->coll, fires[0]->destRect))
							{
								flagf1 = false;
							}

							if (collision::AABB(map2->coll, fires[1]->destRect))
							{
								flagf2 = false;
							}

							if (collision::AABB(map2->coll, fires[2]->destRect))
							{
								flagf3 = false;
							}

							if (collision::AABB(map2->coll, fires[3]->destRect))
							{
							flagf4 = false;
							}

							break;
			
							
						default:
							break;
						}
					}
				}
				
			}
			map2->coll.x = 0;
			map2->coll.y = 0;
		}
	}
	bool fireCollision(SDL_Rect pl) {

			for (int z = 0; z < 4; z++)
			{
				if (collision::AABB(fires[z]->destRect, pl))
				{
					/*fires[0]->generateFireHeightNeg(destRect, u * 2);
					fires[1]->generateFireHeight(destRect, u * 2);
					fires[2]->generateFireWidthNeg(destRect, u * 2);
					fires[3]->generateFireWidth(destRect, u * 2);*/
					return true;
				}
			}
			
		return false;
	}
	
};