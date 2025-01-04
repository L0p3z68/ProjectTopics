#pragma once
#include <string>
#include "Scene.h"
#include <vector>
#include <iostream>

class Window : BaseScript
{
	private:
		struct SDL_Window* window = nullptr;
		struct SDL_Renderer* renderTarget = nullptr;
		Scene* scene;


	public:
		Window(const char* title, int w, int h, Scene* scene);

		void Awake();
		void Start();
		void Update(int deltaTime);



		SDL_Renderer* GetRenderTarget();

		~Window();
};

