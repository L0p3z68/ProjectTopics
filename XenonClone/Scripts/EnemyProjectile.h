#pragma once
#include "Engine/Object.h"
#include "Engine/SpriteRenderer.h"
#include "Engine/Animator.h"
#include "Engine/RigidBody2D.h"

class EnemyProjectile : public Object
{
private:
	RigidBody2D* myRigidBody2D;
	SpriteRenderer* mySpriteRenderer;
	Animator* myAnimator;
	float timeToDie = 0.f;

public:
	EnemyProjectile(Object nav);
	void Awake() override;
	void Start() override;
	void Update(float deltaTime) override;
	void UpdateRender() override;
	void OnTrigger(Object* object) override;
};