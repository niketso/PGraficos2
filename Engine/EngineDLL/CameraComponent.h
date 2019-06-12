#pragma once
#include "Component.h"
class CameraComponent : public Component
{
public:
	CameraComponent();
	~CameraComponent();
	void Start();
	bool Update();
	void Draw();
};

