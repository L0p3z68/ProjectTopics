#include "Window.h"

Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags, Scene scene) : scene{scene}
{
	window = SDL_CreateWindow(title, x, y, w, h, flags);

	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Window::Awake()
{
	scene.Awake();
}

void Window::Start()
{
	scene.Start();
}

void Window::Update(int deltaTime)
{
	scene.Update(deltaTime);
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

}
