#include "RigidBody2D.h"
#include "Engine.h"
#include "box2d.h"

struct RigidBody2D::Aux
{
	b2BodyId bodyId;
};

RigidBody2D::RigidBody2D(Object* parent, bool dynamicBoby, bool sensor) : aux(new Aux())
{
	Engine* engine = Engine::GetInstance();
	this->parent = parent;
	if (dynamicBoby) {
		b2BodyDef dynamicBodyDef = b2DefaultBodyDef();
		dynamicBodyDef.type = b2_dynamicBody;
		dynamicBodyDef.position = b2Vec2{ parent->GetTransform().GetPosition().X , parent->GetTransform().GetPosition().Y}; // Start position
		dynamicBodyDef.fixedRotation = true;
		aux->bodyId = b2CreateBody(*engine->GetWorldId(), &dynamicBodyDef);

		b2Polygon dynamicBox = b2MakeBox(parent->GetTransform().GetScale().X/2, parent->GetTransform().GetScale().Y/2); // A small box
		b2ShapeDef shapeDef = b2DefaultShapeDef();
		shapeDef.density = 1.0f; // Density for dynamic bodies
		shapeDef.friction = 0.3f;
		shapeDef.isSensor = sensor;
		shapeDef.userData = this;

		b2CreatePolygonShape(aux->bodyId, &shapeDef, &dynamicBox);
	}
	else 
	{
		b2BodyDef staticBodyDef = b2DefaultBodyDef();
		staticBodyDef.position = b2Vec2{ parent->GetTransform().GetPosition().X, parent->GetTransform().GetPosition().Y };
		aux->bodyId = b2CreateBody(*engine->GetWorldId(), &staticBodyDef);

		b2Polygon shapeBox = b2MakeBox(parent->GetTransform().GetScale().X/2, parent->GetTransform().GetScale().Y/2);
		b2ShapeDef shapeDef = b2DefaultShapeDef();
		b2CreatePolygonShape(aux->bodyId, &shapeDef, &shapeBox);
	}

	
}

void RigidBody2D::Start()
{

}

void RigidBody2D::Update(float deltaTime)
{
	b2Vec2 position = b2Body_GetPosition(aux->bodyId);
	parent->SetTransform(Transform(Vector3(position.x, position.y, .0f), parent->GetTransform().GetRotation(), parent->GetTransform().GetScale()));
}

void RigidBody2D::AddVelocity(Vector2 velocity)
{
	b2Vec2 vel = b2Vec2{ velocity.GetX(), velocity.GetY() };
	b2Body_SetLinearVelocity(aux->bodyId, vel);
}

void RigidBody2D::OnTriggerCollision(RigidBody2D* rb)
{
	parent->OnTrigger(rb->GetParent());
}

std::string RigidBody2D::GetTag()
{
	return parent->GetTag();
}

Object* RigidBody2D::GetParent()
{
	return parent;
}

RigidBody2D::~RigidBody2D()
{
	delete aux;
}
