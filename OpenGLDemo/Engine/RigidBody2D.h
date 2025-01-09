#pragma once
#include "Components.h"
#include "Transform.h"

class RigidBody2D : public Components
{
	private:

		struct Aux;
		Aux* aux;

		Object* parent;

	public:
		RigidBody2D(Object* parent, bool dynamicBoby, bool sensor);

		void Start();
		void Update(float deltaTime);

		void AddVelocity(Vector2 velocity);
		void OnTriggerCollision(RigidBody2D* rb);
		std::string GetTag();
		Object* GetParent();

		~RigidBody2D() override;
};

