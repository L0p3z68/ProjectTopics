#include <iostream>
#include "Engine\Window.h"
#include "Engine\Engine.h"

#include "Scripts\SceneGame.h"

#undef main

int main(int argc, char* argv[])
{	
	Window* window = Window::GetInstance("SDL window", 1000, 700);
	Engine* engine = Engine::GetInstance(window);
	SceneGame* mainScene = new SceneGame();
	window->AddScene(mainScene);
	engine->StartEngine();
	return 0;
}