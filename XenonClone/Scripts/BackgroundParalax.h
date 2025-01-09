#pragma once
#include "Engine/Object.h"
#include "Engine/SpriteRenderer.h"

class BackgroundParalax: public Object
{
	private:
		SpriteRenderer* mySpriteRenderer;
	public:
		BackgroundParalax(Object nav);
		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
		void UpdateRender() override;
};

