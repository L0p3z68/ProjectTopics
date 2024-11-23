#include "Animator.h"

Animator::Animator(SpriteRenderer sr) : spriteRenderer{ sr }{}

void Animator::AddAnimation(std::string animationName, std::vector<int> frames, bool loop, float fps)
{
    Animation newAnimation;
    newAnimation.animationName = animationName;
    newAnimation.frames = frames;
    newAnimation.loop = loop;
    newAnimation.fps = fps;
    animations.push_back(newAnimation);
}

void Animator::Play(std::string animationName)
{
    for (size_t i = 0; i < animations.size() - 1; ++i)
    {
        if (animations[i].animationName ==  animationName) {
            indexCurrentAnimation = i;
            break;
        }
    }
    currentFrameIndex = 0;
}

void Animator::Update(int deltaTime)
{
    elapsedTime += deltaTime;
    if (elapsedTime >= 1/animations[indexCurrentAnimation].fps) {
        elapsedTime = 0;

        if (currentFrameIndex >= animations[indexCurrentAnimation].frames.size()) {
            if (animations[indexCurrentAnimation].loop) {
                currentFrameIndex = 0;
            }
            else
            {
                return;
            }
        }
        currentFrameIndex++;
    }
}

Animator::~Animator()
{
    spriteRenderer.~SpriteRenderer();
    animations.~vector();
}
