
#include "Component.h"
#pragma once
class TransformComponent : public Component
{
public:
	TransformComponent();
	~TransformComponent();
	void start();
	bool Update();
	void Draw();
};

