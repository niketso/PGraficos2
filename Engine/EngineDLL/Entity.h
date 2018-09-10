#pragma once
#include "Exports.h"
#include "Renderer.h"
#include<iostream>
using namespace std;
class ENGINEDLL_API Entity
{
protected:
	Renderer * render;
public:
	Entity(Renderer * renderPTR);
	
	virtual void Draw() = 0;
};

