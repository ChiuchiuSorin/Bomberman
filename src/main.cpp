#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
Game* game = nullptr;
int main(int argc, const char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / 60;
	Uint32 frameStart;
	int frameTime;
	game = new Game();
	bool selected = false;
	while (game->again)
	{
		while (!selected) {
			cout << "----------------------ALEGETI NIVELUL----------------------" << endl <<
				"--------- 1 -> nivel 1; 2 -> nivel 2; 3 -> nivel 3 --------" << endl;
			game->setLvl();
			if (game->lvl == 1 || game->lvl == 2 || game->lvl == 3)
				selected = true;
		}

		switch (game->lvl)
		{
		case 1:
			game->nrInamici = 3;
			game->init("AGONY", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, "assets/lvl1.txt");


			while (game->running()) {
				frameStart = SDL_GetTicks();

				game->HandleEvents();
				game->update();
				game->render();

				frameTime = SDL_GetTicks() - frameStart;

				if (frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}

			}
			break;
		case 2:
			game->nrInamici = 5;
			game->init("AGONY", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, "assets/lvl2.txt");


			while (game->running()) {
				frameStart = SDL_GetTicks();

				game->HandleEvents();
				game->update();
				game->render();

				frameTime = SDL_GetTicks() - frameStart;

				if (frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}

			}
			break;
		case 3:
			game->nrInamici = 7;
			game->init("AGONY", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, "assets/lvl2.txt");


			while (game->running()) {
				frameStart = SDL_GetTicks();

				game->HandleEvents();
				game->update();
				game->render();

				frameTime = SDL_GetTicks() - frameStart;

				if (frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}

			}
			break;
		}

		cout << "-------------------------GAME OVER-------------------------" << endl;
		while (game->choose == 0) {
			cout << "------------------------Play again?------------------------" << endl <<
				"-------------------- 1 -> YES; 2 -> NO --------------------" << endl;
			cin >> game->choose;
			if (game->choose != 1 && game->choose != 2)
				game->choose = 0;
			if (game->choose == 1)
			{
				game->again = true;
				selected = false;
			}
			else if (game->choose == 2)
			{
				game->again = false;
			}
		}
		game->clean();
		game->choose = 0;
	}
	//game->clean();


	return 0;
}