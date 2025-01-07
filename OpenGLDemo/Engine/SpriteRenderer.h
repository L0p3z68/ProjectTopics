#pragma once
#include "Components.h"
#include "Transform.h"
#include "Object.h"
#include "Window.h"
#include <iostream>

struct SDL_Renderer;
struct SDL_Texture;

class SpriteRenderer : public Components
{
	private:
		struct Impl;
		Impl* pImpl;
		SDL_Texture* LoadTexture(std::string filePath, SDL_Renderer* renderTarget);
		bool renderInAll = false;
		Object* obj;
		int indexAnimation;

	public:
		SpriteRenderer(std::string filePath, Window* window, int horizontalDevisions, int verticalDevisions, int starterIndex, Object* object);
		SpriteRenderer(std::string filePath, Window* window);

		SDL_Texture* GetTexture();
		int GetTextureWidth();
		int GetTextureHeight();
		void ChangeFrame(int i);
		void RenderImage(int index);
		void RenderImage();
		void SetPlayerPos();
		void SetIndex(int index);

		void Start();
		void Update(float deltaTime);

		~SpriteRenderer() override;
};

