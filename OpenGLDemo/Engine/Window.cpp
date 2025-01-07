#include "Window.h"

#include <SDL.h>

Window* Window::instance = nullptr;

Window::Window(const char* title, int w, int h) : scene{nullptr}
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h,  SDL_WINDOW_OPENGL);

	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(renderTarget, 0xFF, 0, 0, 0xFF);
}

Window* Window::GetInstance(const char* title, int w, int h)
{
	if (instance == nullptr)
	{
		instance = new Window(title, w, h);
	}
	return instance;
}

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderTarget);
	window = nullptr;
	renderTarget = nullptr;
	SDL_Quit();
}

void Window::Awake()
{
	scene->Awake();
}

void Window::Start()
{
	scene->Start();
}

void Window::Update(float deltaTime)
{
	SDL_RenderClear(renderTarget);
	scene->Update(deltaTime);
	SDL_RenderPresent(renderTarget);
}

void Window::AddScene(Scene* sceneToAdd)
{
	this->scene = sceneToAdd;
}

SDL_Renderer* Window::GetRenderTarget()
{
	return renderTarget;
}


