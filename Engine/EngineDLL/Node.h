#pragma once
#include "Exports.h"
class  ENGINEDLL_API Node
{
public:
	Node();
	~Node();
	bool start();
	void AddComponent();
	void RemoveComponent();
	void AddChild();
	void RemoveChild();
	bool Update();
	void Draw();
};

