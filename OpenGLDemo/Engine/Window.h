#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "Scene.h"


class Window : public BaseScript
{
	private:
		static Window* instance;

		struct SDL_Window* window = nullptr;
		struct SDL_Renderer* renderTarget = nullptr;
		Scene* scene;

		Window(const char* title, int w, int h);

	public:
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		static Window* GetInstance(const char* title = "SDL window", int w = 800, int h = 600);

		void Awake();
		void Start();
		void Update(float deltaTime);
		void UpdateRender();


		void AddScene(Scene* sceneToAdd);
		SDL_Renderer* GetRenderTarget();

		~Window();
};

