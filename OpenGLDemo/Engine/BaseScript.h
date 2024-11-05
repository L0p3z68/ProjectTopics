#pragma once
class BaseScript
{
	public:
		virtual void Awake();
		virtual void Start();
		virtual void Update(int deltaTime);
};

