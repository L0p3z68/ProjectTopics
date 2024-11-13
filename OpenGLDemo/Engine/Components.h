#pragma once
#include "BaseScript.h" 
class Components : BaseScript
{
	public:
		Components();

		virtual void Awake();
		virtual void Start();
		virtual void Update(int deltaTime);

		~Components();
};

