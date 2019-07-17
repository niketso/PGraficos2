#include "TransformComponent.h"


TransformComponent::TransformComponent(ComponentType type,Renderer * render)
{
	_type = type;
	pos = glm::vec3(0,0,0);
	rot = glm::vec3(0,0,0);
	scale = glm::vec3(1,1,1);

	worldMatrix = glm::mat4(1.0f);
	TranslationMatrix = glm::mat4(1.0f);
	RotationMatrix = glm::mat4(1.0f);
	ScaleMatrix = glm::mat4(1.0f);
}

TransformComponent::~TransformComponent()
{
}

void TransformComponent::Update()
{
	worldMatrix = TranslationMatrix * RotationMatrix * ScaleMatrix;
}

void TransformComponent::Start()
{
}

void TransformComponent::Draw()
{
}

void TransformComponent::Draw(Renderer * rend)
{
}

void TransformComponent::SetPos(float x, float y, float z)
{
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;
	TranslationMatrix = glm::translate(glm::mat4(1.0f), pos);
	Update();
}

void TransformComponent::SetRot(float x, float y, float z)
{
	rot[0] = x;
	rot[1] = y;
	rot[2] = z;

	RotationMatrix = glm::rotate(glm::mat4(1.0f), x, glm::vec3(1.0f, 0.0f, 0.0f));
	RotationMatrix *= glm::rotate(glm::mat4(1.0f), y, glm::vec3(0.0f, 1.0f, 0.0f));
	RotationMatrix *= glm::rotate(glm::mat4(1.0f), z, glm::vec3(0.0f, 0.0f, 1.0f));
	Update();
}

void TransformComponent::SetScale(float x, float y, float z)
{
	scale[0] = x;
	scale[1] = y;
	scale[2] = z;

	ScaleMatrix = glm::scale(glm::mat4(1.0f), scale);

	Update();
}

glm::vec3 TransformComponent::GetPos()
{
	return pos;
}

glm::vec3 TransformComponent::GetRot()
{
	return rot;
}

glm::vec3 TransformComponent::GetScale()
{
	return scale;
}

glm::mat4 TransformComponent::GetWorldMat()
{
	return worldMatrix;
}
