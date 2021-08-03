#pragma once
#include "Exports.h"
#include "Component.h"


class ENGINEDLL_API TransformComponent : public Component
{
private:
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;

	glm::mat4 worldMatrix;
	glm::mat4 TranslationMatrix;
	glm::mat4 RotationMatrix;
	glm::mat4 ScaleMatrix;
	ComponentType _type;
public:
	TransformComponent(ComponentType type,Renderer* render);
	~TransformComponent();
	void Update()override;
	void Start();
	void Draw()override;
	void Draw(Renderer* rend);
	void SetPos(float x, float y, float z);
	void SetRot(float x, float y, float z);
	void SetScale(float x, float y, float z);
	void Translate(float x, float y, float z);
	void SetRotationMatrix(float x, float y, float z, float w);
	void convertToEulerAngles(const glm::vec4 & quaternion, float & pitch, float & yaw, float & roll);
	void clampEulerRotation();
	glm::vec3 GetPos();
	glm::vec3 GetRot();
	glm::vec3 GetScale();
	glm::mat4 GetWorldMat();
	glm::mat4 GetRotMat();
};

