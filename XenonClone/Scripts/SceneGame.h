#pragma once
#include "Engine/Scene.h"
#include "Engine/Window.h"

#include "Nave.h"
#include "BackGround.h"

class SceneGame : public Scene
{
	private:
		Nave* nave;
		BackGround* backGround;

	public:
		SceneGame();
		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
};

