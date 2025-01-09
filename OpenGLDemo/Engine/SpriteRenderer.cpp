#include "SpriteRenderer.h"
#include <SDL.h>

struct SpriteRenderer::Impl {
	SDL_Texture* currentImage = nullptr;
	SDL_Rect imageRect , imagePos;
	SDL_Renderer* renderTarget = nullptr;
	int frameWidth = 0;
	int frameHeight = 0;
	int textureWidth = 0;
	int textureHeight = 0;

	~Impl() {
		if (currentImage) {
			SDL_DestroyTexture(currentImage);
			SDL_DestroyRenderer(renderTarget);
			currentImage = nullptr;
			renderTarget = nullptr;
		}
	}
};


SpriteRenderer::SpriteRenderer(std::string filePath, Window* window, int horizontalDevisions, int verticalDevisions, int starterIndex, Object* object) : pImpl(new Impl()), obj(object), indexAnimation(starterIndex)
{
	pImpl->renderTarget = window->GetRenderTarget();
	pImpl->currentImage = LoadTexture(filePath, pImpl->renderTarget);


	SDL_QueryTexture(pImpl->currentImage, NULL, NULL, &pImpl->textureWidth, &pImpl->textureHeight);

	pImpl->frameWidth = pImpl->textureWidth / horizontalDevisions;
	pImpl->frameHeight = pImpl->textureHeight / verticalDevisions;

	pImpl->imageRect.x = pImpl->frameWidth * 3;
	pImpl->imageRect.y = 0;
	pImpl->imageRect.w = pImpl->frameWidth;
	pImpl->imageRect.h = pImpl->frameHeight;
}

SpriteRenderer::SpriteRenderer(std::string filePath, Window* window) : pImpl(new Impl())
{
	pImpl->renderTarget = window->GetRenderTarget();
	pImpl->currentImage = LoadTexture(filePath, pImpl->renderTarget);

	SDL_QueryTexture(pImpl->currentImage, NULL, NULL, &pImpl->textureWidth, &pImpl->textureHeight);

	renderInAll = true;
}

SDL_Texture* SpriteRenderer::LoadTexture(std::string filePath, SDL_Renderer* renderTarget)
{
	SDL_Texture* texture = nullptr;
	SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
	if (surface == NULL)
		std::cout << "Error" << std::endl;
	else
	{
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 0, 255));
		texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		if (texture == NULL)
			std::cout << "Error" << std::endl;
	}

	SDL_FreeSurface(surface);

	return texture;
}

SDL_Texture* SpriteRenderer::GetTexture()
{
	return pImpl->currentImage;
}

int SpriteRenderer::GetTextureWidth()
{
	return pImpl->textureWidth;
}

int SpriteRenderer::GetTextureHeight()
{
	return pImpl->textureHeight;
}

void SpriteRenderer::ChangeFrame(int indexFrame)
{
	int hdiv = pImpl->textureWidth / pImpl->frameWidth;
	int vdiv = pImpl->textureHeight / pImpl->frameHeight;
	int i = 0;

	for (size_t vdivI = 0; vdivI < vdiv; ++vdivI)
	{
		for (size_t hdivI = 0; hdivI < hdiv; ++hdivI)
		{
			if (indexFrame == i++) {
				pImpl->imageRect.x = pImpl->frameWidth * hdivI;
				pImpl->imageRect.y = pImpl->frameHeight * vdivI;
				return;
			}
		}
	}
	std::cout << ("ERROR SpriteRenderer: index given is out of SpriteSheet") << "\n";
}

void SpriteRenderer::RenderImage( int index)
{
	ChangeFrame(index);
	SetPlayerPos();
	SDL_RenderCopy(pImpl->renderTarget, pImpl->currentImage, &pImpl->imageRect, &pImpl->imagePos);
	
}

void SpriteRenderer::RenderImage()
{
	SDL_RenderCopy(pImpl->renderTarget, pImpl->currentImage, NULL, NULL);
}

void SpriteRenderer::SetPlayerPos()
{
	pImpl->imagePos.x = obj->GetTransform().GetPosition().X - obj->GetTransform().GetScale().X / 2;
	pImpl->imagePos.y = obj->GetTransform().GetPosition().Y - obj->GetTransform().GetScale().Y / 2;
	pImpl->imagePos.w = obj->GetTransform().GetScale().X;
	pImpl->imagePos.h = obj->GetTransform().GetScale().Y;
}

void SpriteRenderer::SetIndex(int index)
{
	indexAnimation = index;
}

void SpriteRenderer::Start()
{
	
}

void SpriteRenderer::UpdateRender()
{
	if (renderInAll) {
		RenderImage();
	}
	else {
		RenderImage(indexAnimation);
	}
}

SpriteRenderer::~SpriteRenderer()
{
	pImpl->~Impl();
}

