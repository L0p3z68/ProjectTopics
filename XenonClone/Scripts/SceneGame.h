#pragma once
#include "Engine/Scene.h"
#include "Engine/Window.h"

#include "Nave.h"
#include "BackGround.h"
#include "Boundaries.h"
#include "Rusher.h"
#include "Missiles.h"
#include "Loner.h"
#include "Spawners.h"
#include "BackgroundParalax.h"

class SceneGame : public Scene
{
	private:
		Nave* nave;
		BackGround* backGround;
		Boundaries* boundarie;
		Boundaries* boundarie1;
		Boundaries* boundarie2;
		Boundaries* boundarie3;
		Spawners* spawner;
		BackgroundParalax* backgroundParalax;
		BackgroundParalax* backgroundParalax2;


	public:
		SceneGame();
		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
};

