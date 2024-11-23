#pragma once
#include "Components.h"
#include <iostream>
#include <SDL.h>

class SpriteRenderer : Components
{
	private:
		SDL_Texture* currentImage = nullptr;
		SDL_Renderer* renderTarget;
		SDL_Rect imageRect;
		int frameWidth, frameHeight;
		int textureWidth, textureHeight;
		bool background;
		SDL_Texture* LoadTexture(std::string filePath, SDL_Renderer* renderTarget);

	public:
		SpriteRenderer(std::string filePath, SDL_Renderer* renderTarget, int horizontalDevisions, int verticalDevisions);
		SpriteRenderer(std::string filePath, SDL_Renderer* renderTarget);

		SDL_Texture* GetTexture();
		int GetTextureWidth();
		int GetTextureHeight();
		void ChangeFrame(int i);
		void RenderImage( const SDL_Rect* dstrect, int index);
		void RenderImage();

		void Start();
		void Update(int deltaTime);

		~SpriteRenderer();
};

