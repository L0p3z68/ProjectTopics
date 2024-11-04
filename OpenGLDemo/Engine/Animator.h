#pragma once
#include <SDL.h>
#include <vector>

// Structures needed
struct AnimationFrame
{
	SDL_Rect frameRect;
	int duration;  // Duration in milliseconds
};

struct Animation {
	std::vector<AnimationFrame> frames;
	bool loop = true;  // If true, repeat the animation
};

class Animator
{
private:
	Animation* currentAnimation = nullptr; // Animation
	int currentFrameIndex = 0;
	int elapsedTime = 0;
	bool isPaused = false;

public:
	// Basic Functions of an Animator
	void Play(Animation* animation);
	void Pause();
	void Resume();
	void Stop();
	void Update(int deltaTime);
	// Additional Functions
	void Render(SDL_Renderer* renderer, int x, int y); // Render current animation
	void SetLooping(bool loop);
	void SetSpeed(float speedFactor); // Change the speed of the animation
};

