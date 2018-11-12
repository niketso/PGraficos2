#pragma once
#include "Exports.h"
#include "Sprite.h"
class ENGINEDLL_API Animation
{
private:
	Sprite spr;
public:
	Animation(Renderer* rend);
	~Animation();
};

