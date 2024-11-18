#pragma once
#include "Components.h"
#include <iostream>
#include <SDL.h>

class SpriteRenderer:Components
{
	private:
		SDL_Texture* currentImage = nullptr;
		int frameWidth, frameHeight;
		int textureWidth, textureHeight;
		SDL_Texture* LoadTexture(std::string filePath, SDL_Renderer* renderTarget);

	public:
		SpriteRenderer(std::string filePath, SDL_Renderer* renderTarget);

		SDL_Texture* GetTexture();
		int GetTextureWidth();
		int GetTextureHeight();
		void RenderImage(SDL_Renderer* renderer, const SDL_Rect* srcrect, const SDL_Rect* dstrect);

		~SpriteRenderer();
};

