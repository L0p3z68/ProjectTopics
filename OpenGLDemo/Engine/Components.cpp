#include "Components.h"


void Components::Awake()
{
}

void Components::Start()
{
}

void Components::Update(float deltaTime)
{

}

void Components::UpdateRender()
{
}

void Components::SetParent(Object* par)
{
	parent = par;
}


Components::~Components()
{
	delete parent;
	parent = nullptr;
}
