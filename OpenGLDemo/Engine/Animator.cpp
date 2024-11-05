#include "Animator.h"

// Functions
void Animator::Play(Animation* animation)
{
    currentAnimation = animation;
    currentFrameIndex = 0;
    elapsedTime = 0;
    isPaused = false;
}

void Animator::Pause()
{
    isPaused = true;
}

void Animator::Resume()
{
    isPaused = false;
}

void Animator::Stop()
{
    currentAnimation = nullptr;
    currentFrameIndex = 0;
    elapsedTime = 0;
    isPaused = true;
}

void Animator::Update(int deltaTime)
{
    if (isPaused || !currentAnimation) return;

    elapsedTime += deltaTime;
    if (elapsedTime >= currentAnimation->frames[currentFrameIndex].duration) {
        elapsedTime = 0;
        currentFrameIndex++;
        if (currentFrameIndex >= currentAnimation->frames.size()) {
            if (currentAnimation->loop) {
                currentFrameIndex = 0;
            }
            else {
                currentFrameIndex--;  // Stay on the last frame
            }
        }
    }
}

void Animator::Render(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y)
{
    if (!currentAnimation) return;

    AnimationFrame& frame = currentAnimation->frames[currentFrameIndex];
    SDL_Rect destRect = { x, y, frame.frameRect.w, frame.frameRect.h };
    SDL_RenderCopy(renderer, texture, &frame.frameRect, &destRect);
}

void Animator::SetLooping(bool loop)
{
    if (currentAnimation) currentAnimation->loop = loop;
}

void Animator::SetSpeed(float speedFactor)
{
    if (currentAnimation) {
        for (auto& frame : currentAnimation->frames) {
            frame.duration = static_cast<int>(frame.duration * speedFactor);
        }
    }
}
