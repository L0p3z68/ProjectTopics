#pragma once
#include "Engine/Object.h"
#include "Engine/SpriteRenderer.h"
#include "Engine/RigidBody2D.h"

class Boundaries : public Object
{
private:
	RigidBody2D* myRigidBody2D;
	SpriteRenderer* mySpriteRenderer;

public:
	Boundaries(Object nav);
	void Awake() override;
	void Start() override;
	void Update(float deltaTime) override;
};

