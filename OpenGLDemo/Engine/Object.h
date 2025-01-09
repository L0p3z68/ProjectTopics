#pragma once
#include "BaseScript.h"
#include "Transform.h"
#include "Components.h"


#include <vector>

class Object : public BaseScript {
    private:
        std::string tag;
        std::vector<Components*> components;
        class Scene* scene = nullptr;

        

    protected:
        Transform transform;

    public:

        Object(std::string tag, Transform transform);
        Object();
        ~Object();

        void AddComponent( Components* component);
        Transform GetTransform() const;
        std::string GetTag();
        void SetTransform(Transform transform);
        void AddToPosition(Vector3 position);
        void Destroy();
        void Instantiate(Object* object);
        virtual void OnTrigger(Object* object);
        void SetScene(Scene* scene);

        void Awake();
        void Start();
        void Update(float deltaTime);
        void UpdateRender();
};
