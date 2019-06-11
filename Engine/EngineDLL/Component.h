#pragma once
#include "Exports.h"
#include"Node.h"
 class ENGINEDLL_API Component
{
public:
	virtual void Start() = 0;
	virtual bool Update() = 0;
	virtual void Draw() = 0;

};

