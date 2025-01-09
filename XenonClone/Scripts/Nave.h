#pragma once
#include "Engine/Object.h"
#include "Engine/SpriteRenderer.h"
#include "Engine/Animator.h"
#include "Engine/Inputs.h"
#include "Engine/RigidBody2D.h"

class Nave: public Object
{
	private:
		RigidBody2D* myRigidBody2D;
		SpriteRenderer* spriteNave;
		Animator* animatorNave;
		Inputs input;

		bool isMovingRight = false;
		bool isMovingLeft = false;
		float moveSpeed , cooldownBullet = 0;

	public:
		Nave(Object nav);
		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
		void UpdateRender() override;
		void OnTrigger(Object* object) override;
};

