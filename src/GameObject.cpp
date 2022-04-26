#include "GameObject.h"
#include "TextureManager.h"

Player::Player(const char* textureSheet, int x, int y) : Object(textureSheet, x, y) {}


//void Player::UpdatePlayer(bool b[4]) {
//	Uint32 ticks = SDL_GetTicks();
//	Uint32 sprite = (ticks / 100) % 2;
//	SDL_Rect rects = { sprite * 14, 0, 14, 27 };
//	SDL_Rect rects2 = { 0,610, 800, 32 };
//	srcRect.h = 27;
//	srcRect.w = 14;
//	srcRect.x = 28;
//	srcRect.y = 0;
//
//	destRect.x = xpos;
//	destRect.y = ypos;
//	destRect.w = srcRect.w * 3;
//	destRect.h = srcRect.h * 3;
//	
//	
//	if (b[1])
//	{
//		if (b[1] && b[0])
//		{
//			xpos -= 2;
//			destRect.x = xpos;
//			srcRect.x = 41;
//			if (collision(&rects2))
//				xpos += 2;
//			SDL_RenderCopy(Game::renderer, this->ObjTexture, &srcRect, &destRect);
//		}
//		else
//		{
//			xpos -= 1;
//			destRect.x = xpos;
//			//SDL_RenderClear(renderer);
//			if (collision(&rects2))
//				xpos += 1;
//			destRect.x = xpos;
//			SDL_RenderCopy(Game::renderer, this->ObjTexture, &rects, &destRect);
//			//SDL_RenderPresent(renderer);
//
//			//SDL_RenderClear(renderer);
//			xpos -= 1;
//			destRect.x = xpos;
//			if (collision(&rects2))
//				xpos += 1;
//			SDL_RenderCopy(Game::renderer, this->ObjTexture, &rects, &destRect);
//			destRect.x = xpos;
//			//	SDL_RenderPresent(renderer);
//		}
//	}
//	if (b[2])
//	{
//		ypos += 2;
//		destRect.y = ypos;
//		srcRect.x = 28;
//		if (collision(&rects2))
//			ypos -= 2;
//		SDL_RenderCopy(Game::renderer, this->ObjTexture, &srcRect, &destRect);
//
//	}
//	if (b[3])
//		if (b[3] && b[0])
//		{
//			xpos += 2;
//			srcRect.x = 41;
//			destRect.x = xpos;
//			if (collision(&rects2))
//				xpos -= 2;
//			SDL_RenderCopy(Game::renderer, this->ObjTexture, &srcRect, &destRect);
//		}
//		else
//		{
//			xpos += 1;
//			//SDL_RenderClear(renderer);
//			destRect.x = xpos;
//			if (collision(&rects2))
//				xpos -= 1;
//			destRect.x = xpos;
//			SDL_RenderCopy(Game::renderer, this->ObjTexture, &rects, &destRect);
//			//SDL_RenderPresent(renderer);
//
//		//	SDL_RenderClear(renderer);
//			xpos += 1;
//			destRect.x = xpos;
//			if (collision(&rects2))
//				xpos -= 1;
//			SDL_RenderCopy(Game::renderer, this->ObjTexture, &rects, &destRect);
//			destRect.x = xpos;
//			//	SDL_RenderPresent(renderer);
//		}
//	if (b[1] == 0 && b[2] == 0 && b[3] == 0)
//		SDL_RenderCopy(Game::renderer, this->ObjTexture, &srcRect, &destRect);
//	ypos += 2;
//	destRect.y = ypos;
//	if (collision(&rects2))
//		ypos -= 2;
//	if (collision(&rects2))
//	{
//		if (b[0])
//		{
//			ypos -= 40;
//			destRect.y = ypos;
//			srcRect.x = 41;
//			/*if (collision(&rects2))
//				ypos += 4;*/
//			SDL_RenderCopy(Game::renderer, this->ObjTexture, &srcRect, &destRect);
//		}
//	}
//}

//void Player::Update() {
//	xpos++;
//	ypos++;
//
//	srcRect.h = 64;
//	srcRect.w = 64;
//	srcRect.x = 0;
//	srcRect.y = 0;
//
//	destRect.x = xpos;
//	destRect.y = ypos;
//	destRect.w = srcRect.w * 2;
//	destRect.h = srcRect.h * 2;
//}

//bool Player::collision(SDL_Rect* rect3) {
//	if (rect3->y >= destRect.y + destRect.h)
//		return 0;
//	if (rect3->x >= destRect.x + destRect.w)
//		return 0;
//	if (rect3->y + rect3->h <= destRect.y)
//		return 0;
//	if (rect3->x + rect3->w <= destRect.x)
//		return 0;
//	return 1;
//}