#include "Animation.h"

Animation::Animation(int columns, int rows):
	inicialFrame(0),
	currentFrame(0),
	lastFrame(0),
	timePerFrame(0.1f),
	currentTime(0.0f)
	
{
	sprsht = new SpriteSheet(1, 1);
}

Animation::~Animation()
{
}

void Animation::SetAnimation(int initF, int finalF, float timePerF)
{
		
}

/*float * Animation::UpdateAnimation(float deltaTime) 
{
		return;
}*/

