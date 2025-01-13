#include "Engine.h"
#include <SDL.h>
#include <box2d.h>
#include <RigidBody2D.h>

Engine* Engine::instance = nullptr;

struct Engine::Aux
{
	SDL_Event ev;
	b2WorldId worldId;
};

Engine::Engine(Window* window, Vector2 gravity): aux(new Aux()), window(window)
{
	b2WorldDef worldDef = b2DefaultWorldDef();
	worldDef.gravity = b2Vec2{ gravity.GetX(), gravity.GetY()};
	aux->worldId = b2CreateWorld(&worldDef);

}

Engine* Engine::GetInstance(Window* window, Vector2 gravity)
{
	if (instance == nullptr)
	{
		if (window == nullptr)
		{
			throw std::runtime_error("Cannot initialize Engine without a Window instance");
		}
		instance = new Engine(window, gravity);
	}
	return instance;
}

void Engine::StartEngine()
{
	float timeStep = 1.0f / 60.0f;
	int subStepCount = 4;
	window->Awake();
	window->Start();
	while (isRunning) {
		prevTime = currentTime;
		currentTime = GetTicks();
		deltaTime = (currentTime - prevTime) / 1000.0f;
		b2World_Step(aux->worldId, timeStep, subStepCount);

		b2SensorEvents sensorEvents = b2World_GetSensorEvents(aux->worldId);
		for (int i = 0; i < sensorEvents.beginCount; ++i)
		{
			b2SensorBeginTouchEvent* beginTouch = sensorEvents.beginEvents + i;
			// Get sensor data
			RigidBody2D* sensor_body = reinterpret_cast<RigidBody2D*>(b2Shape_GetUserData(beginTouch->sensorShapeId));

			// Get the colliding body's data
			RigidBody2D* colliding_body = reinterpret_cast<RigidBody2D*>(b2Shape_GetUserData(beginTouch->visitorShapeId));
			if (sensor_body != nullptr && colliding_body != nullptr) {
				colliding_body->OnTriggerCollision(sensor_body);
			}
		}
		while (GetEventPool() != 0)
		{
			// Getting the events
			if (aux->ev.type == SDL_QUIT){
				isRunning = false;
			}
			else if (aux->ev.type == SDL_CONTROLLERDEVICEADDED) {
				std::cout << "Controller added!" << std::endl;
			}
			else if (aux->ev.type == SDL_CONTROLLERDEVICEREMOVED) {
				std::cout << "Controller removed!" << std::endl;
			}
			else if (aux->ev.type == SDL_CONTROLLERBUTTONDOWN) {
				std::cout << "Button pressed: " << (int)aux->ev.cbutton.button << std::endl;
			}
		}
		window->Update(deltaTime);
		window->UpdateRender();
	}
	this->~Engine();
}

int Engine::GetTicks()
{
	return SDL_GetTicks();
}

int Engine::GetEventPool()
{
	return SDL_PollEvent(&aux->ev);
}

b2WorldId* Engine::GetWorldId()
{
	return &aux->worldId;
}

Engine::~Engine()
{
	window->~Window();
	delete window;
	window = nullptr;

	b2DestroyWorld(aux->worldId);
	delete aux;
	aux = nullptr;

	delete instance;
	instance = nullptr;
}
