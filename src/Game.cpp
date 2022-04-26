#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Object.h"
#include "Collision.h"
#include"Enemy.h"
#include "Fire.h"
#include "Powerup.h"

Player* Player2;
Enemy* Enemy1[7];
Enemy* Enemy2;
SDL_Event Game::e;
Map* map2;
bool Game::isRunning = true;
int Game::lvl = 0;
int Game::nrInamici = 0;
//int Game::cnt = 0;
SDL_Renderer* Game::renderer = nullptr;
Object* powup;
Game::Game(){}
Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, const char* nivel) {

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Sys initialised" << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			cout << "window created" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 10, 120,180, 255);
			cout << "renderer created" << endl;
		}
		isRunning = true;
	}
	else
		isRunning = false;
	if (lvl == 1)
	{
		Player2 = new Player("/assets/bomberman.png", 200, 350, true);
		Enemy1[0] = new Enemy("/assets/base.png", 450, 200, 1, 0);
		Enemy1[1] = new Enemy("/assets/NPC.png", 350, 400, 0, 1);
		Enemy1[2] = new Enemy("/assets/NPC.png", 40, 60, 0, 1);
		powup = new Powerup(50, 50, "/assets/speedBoot.png");
	
		for (int i = 0; i < 3; i++)
		{
			Enemy1[i]->init();
		}
		Player2->init();
		powup->init();
		map2 = new Map(nivel);
	}
	if (lvl == 2)
	{
		Player2 = new Player("assets/bomberman.png", 200, 350, true);
		powup = new Powerup(50, 50, "assets/speedBoot.png");
		Enemy1[0] = new Enemy("assets/base.png", 450, 200, 1, 0);
		Enemy1[1] = new Enemy("assets/NPC.png", 350, 400, 0, 1);
		Enemy1[2] = new Enemy("assets/NPC.png", 40, 60, 0, 1);
		Enemy1[3] = new Enemy("assets/NPC.png", 400, 300, 0, 1);
		Enemy1[4] = new Enemy("assets/NPC.png", 120, 60, 1, 1);
		for (int i = 0; i < 5; i++)
		{
			Enemy1[i]->init();
		}
		Player2->init();
		powup->init();
		map2 = new Map(nivel);
	}
	if (lvl == 3)
	{
		Player2 = new Player("assets/bomberman.png", 200, 350, true);
		powup = new Powerup(50, 50, "assets/speedBoot.png");
		Enemy1[0] = new Enemy("assets/base.png", 450, 200, 1, 0);
		Enemy1[1] = new Enemy("assets/NPC.png", 350, 400, 0, 1);
		Enemy1[2] = new Enemy("assets/NPC.png", 40, 60, 0, 1);
		Enemy1[3] = new Enemy("assets/NPC.png", 600, 500, -1, 1);
		Enemy1[4] = new Enemy("assets/NPC.png", 120, 60, 1, 1);
		Enemy1[5] = new Enemy("assets/NPC.png", 400, 300, 0, 1);
		Enemy1[6] = new Enemy("assets/NPC.png", 120, 120, 0, 1);
		for (int i = 0; i < 7; i++)
		{
			Enemy1[i]->init();
		}
		Player2->init();
		powup->init();
		map2 = new Map(nivel);
	}
	try {
		if (nrInamici == 0)
			throw(nrInamici);
		else
			cout << "inamici initializati" << endl;
	}
	catch (int x)
	{
		cout << "0 inamici";
	}
}



void Game::HandleEvents() {
	SDL_PollEvent(&e);
	switch (e.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	/*case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			b[0] = 1;
			break;
		case SDLK_LEFT:
			b[1] = 1;
			break;
		case SDLK_DOWN:
			b[2] = 1;
			break;
		case SDLK_RIGHT:
			b[3] = 1;
			break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			b[0] = 0;
			Player2->velocity.y = 0;
			break;
		case SDLK_LEFT:
			b[1] = 0;
			Player2->velocity.x = 0;
			break;
		case SDLK_DOWN:
			b[2] = 0;
			Player2->velocity.y = 0;
			break;
		case SDLK_RIGHT:
			b[3] = 0;
			Player2->velocity.x = 0;
			break;
		}
		break;*/
	default:
		break;
	}
	Player2->Controller();
}
void destroyEnemy(Player* Player2, Enemy* Enemy1)
{
	if (Player2->bomb1->fireCollision(Enemy1->collider))
	{
		SDL_DestroyTexture(Enemy1->ObjTexture);
		Enemy1->speed = 0;
		Enemy1->destRect.x = -499;
		Enemy1->destRect.y = -300;
		Enemy1->setDead();
	}
}
void destroyPlayer(Player* Player2, Enemy* Enemy1)
{
	if (collision::AABB(Player2->collider, Enemy1->collider))
	{
		SDL_DestroyTexture(Player2->ObjTexture);
		Game::isRunning = false;
	}
}
void pickUp(Player* Player2, Object* powup)
{
	if (collision::AABB(Player2->destRect, powup->destRect))
	{
		Player2->speed = Player2->speed + 1;
		SDL_DestroyTexture(powup->ObjTexture);
		powup->destRect.x = -499;
		powup->destRect.y = -300;
	}
}
SDL_Rect aux, aux2;

void Game::update() {
	//wall->update();
	//aux.x = Player2->xpos + Player2->velocity.x * Player2->speed;
	//aux.y = Player2->ypos + Player2->velocity.y * Player2->speed;
	//aux.h = Player2->collider.h;
	//aux.w = Player2->collider.w;
	//int flag = 1;
	//map2->coll.x = 0;
	//map2->coll.y = 0;
	//for (int i = 0; i < 20; i++)
	//{
	//	for (int j = 0; j < 25; j++)
	//	{
	//		map2->coll.x = j * 32 + 2;
	//		map2->coll.y = i * 30 + 2;
	//		map2->dest.x = j * 32 + 2;
	//		map2->dest.y = i * 30 + 2;
	//		switch (map2->map[i][j])
	//		{
	//		case 1:
	//			if (collision::AABB(aux, map2->coll))
	//			{
	//				//TextureManager::Draw(map2->water, map2->src, map2->dest);
	//				//map2->map[i][j] = 0;
	//				std::cout << "wall hit" << endl;
	//				flag = 0;
	//			}
	//			break;
	//		default:
	//			break;
	//		}
	//	}
	//}
	//if (flag)
	//	Player2->update();s
	Player2->playerCollision(aux, map2);
	for (int i = 0; i < nrInamici; i++)
	{
		Enemy1[i]->collisionEnemy(aux2, map2);
		destroyEnemy(Player2, Enemy1[i]);
		destroyPlayer(Player2, Enemy1[i]);
		switch (nrInamici)
		{
		case 3:
			if (Enemy1[0]->getDead() && Enemy1[1]->getDead() && Enemy1[2]->getDead())
			{
				isRunning = false;
			}
			break;
		case 5:
			if (Enemy1[0]->getDead() && Enemy1[1]->getDead() && Enemy1[2]->getDead() && Enemy1[3]->getDead() && Enemy1[4]->getDead())
			{
				isRunning = false;
			}
			break;
		case 7:
			if (Enemy1[0]->getDead() && Enemy1[1]->getDead() && Enemy1[2]->getDead() && Enemy1[3]->getDead() && Enemy1[4]->getDead() && Enemy1[5]->getDead() && Enemy1[6]->getDead())
			{
				isRunning = false;
			}
			break;
		default:
			break;
		}
	}
	pickUp(Player2, powup);
}

void Game::render() {

	
	SDL_RenderClear(renderer);
	map2->DrawMap();
	/*for (int i = 0; i < 4; i++)
	{
		wall[i]->draw();
	}*/
	powup->draw();
	Player2->draw(map2);
	for (int i = 0; i < nrInamici; i++)
	{
		if (!Enemy1[i]->getDead())
			Enemy1[i]->draw();
	}
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "game cleaned" << endl;
}

