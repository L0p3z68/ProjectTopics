#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(std::string filePath, SDL_Renderer* renderTarget, int horizontalDevisions, int verticalDevisions): renderTarget{renderTarget}
{
	currentImage = LoadTexture(filePath, renderTarget);


	SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);

	frameWidth = textureWidth / horizontalDevisions;
	frameHeight = textureHeight / verticalDevisions;

	imageRect.x = frameWidth * 3;
	imageRect.y = 0;
	imageRect.w = frameWidth;
	imageRect.h = frameHeight;

}

SpriteRenderer::SpriteRenderer(std::string filePath, SDL_Renderer* renderTarget) : renderTarget{ renderTarget }
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

void SpriteRenderer::ChangeFrame(int indexFrame)
{
	int hdiv = textureWidth / frameWidth;
	int vdiv = textureHeight / frameHeight;
	int i = 0;

	for (size_t vdivI = 0; vdivI < vdiv; ++vdivI)
	{
		for (size_t hdivI = 0; hdivI < hdiv; ++hdivI)
		{
			if (indexFrame == i++) {
				imageRect.x = frameWidth * hdivI;
				imageRect.y = frameHeight * vdivI;
				std::cout << vdivI << hdivI << "\n";
				return;
			}


		}
	}
	std::cout << ("ERROR SpriteRenderer: index given is out of SpriteSheet") << "\n";
}

void SpriteRenderer::RenderImage( const SDL_Rect* dstrect, int index)
{
	std::cout << imageRect.x << " " << imageRect.y << " " << imageRect.w << " " << imageRect.h << "\n";
	ChangeFrame(index);
	SDL_RenderCopy(renderTarget, currentImage, &imageRect, dstrect);
}

void SpriteRenderer::RenderImage()
{
	SDL_RenderCopy(renderTarget, currentImage, NULL, NULL);
}

void SpriteRenderer::Start()
{
	
}

void SpriteRenderer::Update(int deltaTime)
{
}

SpriteRenderer::~SpriteRenderer()
{
	SDL_DestroyTexture(currentImage);

	currentImage = nullptr;
}
