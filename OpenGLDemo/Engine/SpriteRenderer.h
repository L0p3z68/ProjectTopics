#pragma once
#include "Components.h"
#include "Transform.h"
#include <iostream>

struct SDL_Renderer;
struct SDL_Texture;

class SpriteRenderer : public Components
{
	private:
		struct Impl;
		Impl* pImpl;
		SDL_Texture* LoadTexture(std::string filePath, SDL_Renderer* renderTarget);

	public:
		SpriteRenderer(std::string filePath, SDL_Renderer* renderTarget, int horizontalDevisions, int verticalDevisions);
		SpriteRenderer(std::string filePath, SDL_Renderer* renderTarget);

		SDL_Texture* GetTexture();
		int GetTextureWidth();
		int GetTextureHeight();
		void ChangeFrame(int i);
		void RenderImage(int index);
		void RenderImage();
		void SetPlayerPos(Transform tran);

		void Start();
		void Update(int deltaTime) override;

		~SpriteRenderer() override;
};

