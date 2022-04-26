#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Components.h"
#include "TextureManager.h"
#include "Collider.h"
#include "Animation.h"
#undef main
#include <stdio.h>
#include<iostream>
#include <map>
using namespace std;

class Object : public ColliderComponent {
public:
	SDL_Texture* ObjTexture;
	SDL_Rect srcRect, destRect;
	bool animated;
	int frames = 0;
	int animSpeed = 100;


	int animIn = 0;
	
	std::map<const char*, Animation> animations;

	Object() = default;
	~Object() { SDL_DestroyTexture(ObjTexture); }
	Object(const char* textureSheet, int x, int y) : ColliderComponent(x, y)
	{
		setTex(textureSheet);
	}
	Object(const char* textureSheet, int x, int y, bool isAnimated) : ColliderComponent(x, y)
	{
		animated = isAnimated;

		Animation idle = Animation(2, 1, 100);
		Animation walkRight = Animation(1, 7, 200);
		Animation walkLeft = Animation(3, 7, 200);
		Animation walkUp = Animation(0, 7, 200);
		Animation walkDown = Animation(2,7, 200);

		animations.emplace("Idle", idle);
		animations.emplace("right", walkRight);
		animations.emplace("left", walkLeft);
		animations.emplace("up", walkUp);
		animations.emplace("down", walkDown);

		Play("Idle");

		setTex(textureSheet);
	}
	Object(const char* textureSheet, int x, int y, int h, int w, int sc) : ColliderComponent(x, y, h, w, sc)
	{
		setTex(textureSheet);
	}

	void setTex(const char* textureSheet) {
		ObjTexture = TextureManager::LoadText(textureSheet);
	}

	void init() override{
		ColliderComponent::init();
		srcRect.h = height;
		srcRect.w = width;
		srcRect.x = 28;
		srcRect.y = 0;
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w * scale;
		destRect.h = srcRect.h * scale;
	
	}
	void update() override {
		ColliderComponent::update();
		if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / animSpeed) % frames);
		}
		
		srcRect.y = animIn * height;

		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w * scale;
		destRect.h = srcRect.h * scale;
	}
	void draw() override {
		TextureManager::Draw(ObjTexture, srcRect, destRect);
	}
	void Play(const char* animName) {
		frames = animations[animName].frames;
		animIn = animations[animName].index;
		animSpeed = animations[animName].speed;
	}
};