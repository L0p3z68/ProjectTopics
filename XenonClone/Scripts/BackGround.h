#pragma once
#include "Engine/Object.h"
#include "Engine/SpriteRenderer.h"

class BackGround : public Object
{
	private:
		SpriteRenderer* mySpriteRenderer;
	public:
		BackGround(Object background);

		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
};

