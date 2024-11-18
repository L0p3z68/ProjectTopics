#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(std::string filePath, SDL_Renderer* renderTarget)
{
	currentImage = LoadTexture(filePath, renderTarget);

	SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);
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
	return currentImage;
}

int SpriteRenderer::GetTextureWidth()
{
	return textureWidth;
}

int SpriteRenderer::GetTextureHeight()
{
	return textureHeight;
}

void SpriteRenderer::RenderImage(SDL_Renderer* renderer, const SDL_Rect* srcrect, const SDL_Rect* dstrect)
{
	SDL_RenderCopy(renderer, currentImage, srcrect, dstrect);
}

SpriteRenderer::~SpriteRenderer()
{
	SDL_DestroyTexture(currentImage);

	currentImage = nullptr;
}
