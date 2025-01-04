#include "Window.h"

#include <SDL.h>

Window::Window(const char* title, int w, int h, Scene* scene) : scene{scene}
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h,  SDL_WINDOW_OPENGL);

	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(renderTarget, 0xFF, 0, 0, 0xFF);
}

void Window::Awake()
{
	scene->Awake();
}

void Window::Start()
{
	scene->Start();
}

void Window::Update(int deltaTime)
{
	
	scene->Update(deltaTime);
	SDL_RenderClear(renderTarget);
	SDL_RenderPresent(renderTarget);
}

SDL_Renderer* Window::GetRenderTarget()
{
	return renderTarget;
}

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderTarget);
	window = nullptr;
	renderTarget = nullptr;
	SDL_Quit();
}
