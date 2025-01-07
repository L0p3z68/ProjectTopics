#pragma once
#include "Engine/Object.h"
#include "Engine/SpriteRenderer.h"
#include "Engine/Animator.h"
#include "Engine/Inputs.h"

class Nave: public Object
{
	private:
		SpriteRenderer* spriteNave;
		Animator* animatorNave;
		Inputs input;

		bool isMovingRight = false;
		bool isMovingLeft = false;
		float moveSpeed;

	public:
		Nave(Object nav);
		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
};

