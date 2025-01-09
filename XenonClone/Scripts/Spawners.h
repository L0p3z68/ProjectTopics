#pragma once
#include "Engine/Object.h"

class Spawners: public Object
{
	float cooldownLoner = .0f,  cooldownRusher = 0.f;
	
	public:
		Spawners(Object nav);
		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
		void UpdateRender() override;
};

