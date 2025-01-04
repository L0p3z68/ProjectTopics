#include <iostream>
#include "Engine\Animator.h"
#include "Engine\Window.h"
#include "Engine\SpriteRenderer.h"
#include "Engine\Inputs.h"
#include "Engine\Engine.h"

#undef main

int main(int argc, char* argv[])
{
	std::cout << "isRunnin" << std::endl;
	int indexAnim = 0;

	float frameTime = 0;
	int prevTime = 0;
	int currentTime = 0;
	float deltaTime = 0;

	float moveSpeed = 200.0f;
	Engine engine;
	Scene scene;
	Window window = Window("SDL window", 640, 480, &scene);
	Object nave = Object(Transform(Vector3(16.f, 420.f , 0.f), Vector3(), Vector3(32.f, 32.f, 1.f)));
	SpriteRenderer spriteNave = SpriteRenderer("graphics/Ship1.bmp", window.GetRenderTarget(), 7, 1);
	nave.AddComponent( &spriteNave);
	scene.AddObject(nave); // PASSAR COM PONTEIRO??
	Object backgroun = Object();
	SpriteRenderer background = SpriteRenderer("graphics/galaxy2.bmp", window.GetRenderTarget());
	backgroun.AddComponent(&background);

	indexAnim = 3;


	bool isRunning = true;
	Inputs input;

	window.Awake();
	window.Start();

	while (isRunning)
	{
		std::cout << "hhh" << std::endl;
		prevTime = currentTime;
		currentTime = engine.GetTicks();
		deltaTime = (currentTime - prevTime) / 1000.0f;

		while (engine.GetEventPool() != 0)
		{
			// Getting the events
			if (engine.IsGameQuit())
				isRunning = false;
			
		}
		
		if (input.GetKeyState(input.right)) {
			nave.SetTransform(Transform(Vector3(nave.GetTransform().GetPosition().X + moveSpeed * deltaTime, nave.GetTransform().GetPosition().Y, nave.GetTransform().GetPosition().Z)));
			
			if (frameTime >= 0.1f)
			{
				frameTime = 0;
				if (indexAnim <= 5) {
					indexAnim++;
				}
			}

		}
		else if (input.GetKeyState(input.left)) {
			nave.SetTransform(Transform(Vector3(nave.GetTransform().GetPosition().X - moveSpeed * deltaTime, nave.GetTransform().GetPosition().Y, nave.GetTransform().GetPosition().Z)));
			if (frameTime >= 0.1f)
			{
				frameTime = 0;
				if (indexAnim >= 1) {
					indexAnim--;
				}
			}

		}

		if (input.GetKeyState(input.up))
		{
			nave.SetTransform(Transform(Vector3(nave.GetTransform().GetPosition().X, nave.GetTransform().GetPosition().Y + moveSpeed * deltaTime, nave.GetTransform().GetPosition().Z)));
		}
		else if (input.GetKeyState(input.down))
		{
			nave.SetTransform(Transform(Vector3(nave.GetTransform().GetPosition().X, nave.GetTransform().GetPosition().Y - moveSpeed * deltaTime, nave.GetTransform().GetPosition().Z)));
		}

		frameTime += deltaTime;
		
		
		window.Update(deltaTime);
		
	}

	background.~SpriteRenderer();

	window.~Window(); // MAKE SURE QUE TODAS AS CLASSES ESTAM A SER DESTRUIDAS AQUI

	return 0;
}