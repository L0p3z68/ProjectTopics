#pragma once
#include "Vector3.h"
#include "Components.h"
class Transform
{
	private:
		Vector3 position;
		Vector3 rotation;
		Vector3 scale;
	public:
		Transform(Vector3 Position, Vector3 Rotation, Vector3 Scale);
		Transform();

		Vector3 GetPosition();
		Vector3 GetRotation();
		Vector3 GetScale();

		void SetPosition(Vector3 pos);
		void SetRotation(Vector3 rot);
		void SetScale(Vector3 sca);
			
};

