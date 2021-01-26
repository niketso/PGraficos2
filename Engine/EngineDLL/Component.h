
#pragma once
#include "Exports.h"
#include "Renderer.h"
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include <vector>
#include <iostream>

enum ComponentType
{
	_defaultComponent = 0,
	_CameraComponent,
	_TransformComponent,
	_MeshComponent,
};
 class ENGINEDLL_API Component
{
	 	
public:	
	Component();
	ComponentType _type;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	void SetType(ComponentType type);
	ComponentType  GetType();
};

