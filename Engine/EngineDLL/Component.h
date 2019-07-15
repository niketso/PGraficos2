
#pragma once
#include "Exports.h"

enum ComponentType
{
	_defaultComponent = 0,
	_CameraComponent,
	_MeshComponent,
};
 class ENGINEDLL_API Component
{
	 	
public:
	ComponentType _type;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	void SetType(ComponentType type);
};

