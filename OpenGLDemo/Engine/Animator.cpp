#include "Animator.h"

Animator::Animator(SpriteRenderer* sr) : spriteRenderer{ sr }{}

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
    for (size_t i = 0; i <= animations.size() -1; ++i)
    {
        if (animations[i].animationName ==  animationName) {
            indexCurrentAnimation = i;
            break;
        }
    }
    currentFrameIndex = 0;
}

void Animator::Update(float deltaTime)
{
    elapsedTime += deltaTime;
    float auxx = 1 / animations[indexCurrentAnimation].fps;
    if (elapsedTime >= auxx) {
        elapsedTime = 0;

        if (currentFrameIndex >= animations[indexCurrentAnimation].frames.size()) {
            if (animations[indexCurrentAnimation].loop) {
                currentFrameIndex = 0;
            }
            else
            {
                currentFrameIndex = animations[indexCurrentAnimation].frames.size()-1;
            }
        }

        spriteRenderer->SetIndex(animations[indexCurrentAnimation].frames[currentFrameIndex]);
        currentFrameIndex++;
    }
}

void Animator::UpdateRender()
{
}

Animator::~Animator()
{
    spriteRenderer->~SpriteRenderer();
    animations.~vector();
}
