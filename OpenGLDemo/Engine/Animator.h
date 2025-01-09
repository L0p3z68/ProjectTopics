#pragma once
#include <vector>
#include <iostream>
#include "Components.h"
#include "SpriteRenderer.h"

struct Animation {
	std::string animationName;
	std::vector<int> frames;
	bool loop;
	float fps;
};

class Animator : public Components
{
private:
	SpriteRenderer* spriteRenderer;
	int indexCurrentAnimation = 0;
	std::vector<Animation> animations;
	int currentFrameIndex = 0;
	float elapsedTime = 0;

public:
	Animator(SpriteRenderer* sr);
	void AddAnimation(std::string animationName, std::vector<int> frames, bool loop, float fps);
	void Play(std::string animationName);
	void Update(float deltaTime);
	void UpdateRender();
	~Animator();
};

