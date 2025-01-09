#pragma once
#include "Engine/Object.h"
#include "Engine/SpriteRenderer.h"
#include "Engine/Animator.h"
#include "Engine/RigidBody2D.h"

class Missiles : public Object
{
private:
	RigidBody2D* myRigidBody2D;
	SpriteRenderer* mySpriteRenderer;
	Animator* myAnimator;

public:
	Missiles(Object nav);
	void Awake() override;
	void Start() override;
	void Update(float deltaTime) override;
	void UpdateRender() override;
	void OnTrigger(Object* object) override;
};

