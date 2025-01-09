#pragma once
#include "Engine/Object.h"
#include "Engine/SpriteRenderer.h"
#include "Engine/Animator.h"

class Explotion : public Object
{
private:
	SpriteRenderer* mySpriteRenderer;
	Animator* myAnimator;
	float deathTimer = 0.f;

public:
	Explotion(Object nav);
	void Awake() override;
	void Start() override;
	void Update(float deltaTime) override;
	void UpdateRender() override;
};

