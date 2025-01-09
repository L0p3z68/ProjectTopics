#pragma once
#include "BaseScript.h"

class Object;

class Components : public BaseScript {
    private:    
        Object* parent;
    public:
        virtual ~Components();

        virtual void Awake();
        virtual void Start();
        virtual void Update(float deltaTime);
        virtual void UpdateRender();
        void SetParent(Object* par);
};
