#include "SpriteRenderer.h"
#include <SDL.h>

struct SpriteRenderer::Impl {
	SDL_Texture* currentImage = nullptr;
	SDL_Rect imageRect, imagePos;
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


SpriteRenderer::SpriteRenderer(std::string filePath, SDL_Renderer* renderTarget, int horizontalDevisions, int verticalDevisions): pImpl(new Impl())
{
	
	pImpl->currentImage = LoadTexture(filePath, renderTarget);


	SDL_QueryTexture(pImpl->currentImage, NULL, NULL, &pImpl->textureWidth, &pImpl->textureHeight);

	pImpl->frameWidth = pImpl->textureWidth / horizontalDevisions;
	pImpl->frameHeight = pImpl->textureHeight / verticalDevisions;

	pImpl->imageRect.x = pImpl->frameWidth * 3;
	pImpl->imageRect.y = 0;
	pImpl->imageRect.w = pImpl->frameWidth;
	pImpl->imageRect.h = pImpl->frameHeight;
}

SpriteRenderer::SpriteRenderer(std::string filePath, SDL_Renderer* renderTarget) 
{
	pImpl->renderTarget = renderTarget;
	pImpl->currentImage = LoadTexture(filePath, renderTarget);

	SDL_QueryTexture(pImpl->currentImage, NULL, NULL, &pImpl->textureWidth, &pImpl->textureHeight);
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
				std::cout << vdivI << hdivI << "\n";
				return;
			}
		}
	}
	std::cout << ("ERROR SpriteRenderer: index given is out of SpriteSheet") << "\n";
}

void SpriteRenderer::RenderImage( int index)
{
	ChangeFrame(index);
	std::cout << pImpl->imageRect.x << " " << pImpl->imageRect.y << " " << pImpl->imageRect.w << " " << pImpl->imageRect.h << "\n";
	SDL_Rect temp;
	temp.x = pImpl->imagePos.x;
	temp.y = pImpl->imagePos.y;
	temp.w = pImpl->imagePos.w;
	temp.h = pImpl->imagePos.h;
	SDL_Rect temp2;
	temp2.x = pImpl->imageRect.x;
	temp2.y = pImpl->imageRect.y;
	temp2.w = pImpl->imageRect.w;
	temp2.h = pImpl->imageRect.h;

	SDL_RenderCopy(pImpl->renderTarget, pImpl->currentImage, &pImpl->imageRect, &pImpl->imagePos);
	
}

void SpriteRenderer::RenderImage()
{
	SDL_RenderCopy(pImpl->renderTarget, pImpl->currentImage, NULL, NULL);
}

void SpriteRenderer::SetPlayerPos(Transform tran)
{
	pImpl->imagePos.x = tran.GetPosition().X;
	pImpl->imagePos.y = tran.GetPosition().Y;
	pImpl->imagePos.w = tran.GetScale().X;
	pImpl->imagePos.h = tran.GetScale().Y;
}

void SpriteRenderer::Start()
{
	
}

void SpriteRenderer::Update(int deltaTime)
{
	RenderImage();
}

SpriteRenderer::~SpriteRenderer()
{
	pImpl->~Impl();
}

