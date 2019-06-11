#pragma once
#include "Component.h"
class MeshComponent : public Component
{
public:
	MeshComponent();
	~MeshComponent();
	void start();
	bool Update();
	void Draw();
};

