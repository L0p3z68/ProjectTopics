#pragma once
#include "Engine/Object.h"
#include "Engine/SpriteRenderer.h"
#include "Engine/Animator.h"
#include "Engine/RigidBody2D.h"

class Loner : public Object
{
private:
	RigidBody2D* myRigidBody2D;
	SpriteRenderer* mySpriteRenderer;
	Animator* myAnimator;
	float cooldownShoot = 0.f;

	float timeToDie = 0.f;

public:
	Loner(Object nav);
	void Awake() override;
	void Start() override;
	void Update(float deltaTime) override;
	void UpdateRender() override;
};


