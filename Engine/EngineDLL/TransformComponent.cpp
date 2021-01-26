#include "TransformComponent.h"


TransformComponent::TransformComponent(ComponentType type,Renderer * render)
{
	if (type != NULL)
	{
		_type = type;
	}

	this->SetType(type);
	
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

void TransformComponent::SetRotationMatrix(float x, float y, float z, float w)
{
	float pitch, yaw, roll;

	glm::vec4 quaternion = glm::normalize(glm::vec4(x, y, z, w));

	convertToEulerAngles(quaternion, pitch, yaw, roll);

	rot = glm::vec3(pitch, yaw, roll);

	glm::mat4 mat1 = glm::mat4
	{
		quaternion.w, quaternion.z, -quaternion.y, quaternion.x,
		-quaternion.z, quaternion.w, quaternion.x, quaternion.y,
		quaternion.y, -quaternion.x, quaternion.w, quaternion.z,
		-quaternion.x, -quaternion.y, -quaternion.z, quaternion.w
	};

	glm::mat4 mat2 = glm::mat4
	{
		quaternion.w, quaternion.z, -quaternion.y, -quaternion.x,
		-quaternion.z, quaternion.w, quaternion.x, -quaternion.y,
		quaternion.y, -quaternion.x, quaternion.w, -quaternion.z,
		quaternion.x, quaternion.y, quaternion.z, quaternion.w
	};

	RotationMatrix = mat1 * mat2;

	clampEulerRotation();
	Update();
}

void TransformComponent::convertToEulerAngles(const glm::vec4 & quaternion, float & pitch, float & yaw, float & roll)
{
	float sinPitchCosYaw = 2.0f * (quaternion.w * quaternion.x + quaternion.y * quaternion.z);
	float cosPitchCosYaw = 1.0f - 2.0f * (quaternion.x * quaternion.x + quaternion.y * quaternion.y);
	pitch = glm::atan(sinPitchCosYaw, cosPitchCosYaw);

	float sinYaw = 2.0f * (quaternion.w * quaternion.y - quaternion.z * quaternion.x);
	yaw = (glm::abs(sinYaw) >= 1.0f) ? glm::sign(sinYaw) * glm::half_pi<float>() : glm::asin(sinYaw);

	float sinRollCosYaw = 2.0f * (quaternion.w * quaternion.z + quaternion.x * quaternion.y);
	float cosRollCosYaw = 1.0f - 2.0f * (quaternion.y * quaternion.y + quaternion.z * quaternion.z);
	roll = glm::atan(sinRollCosYaw, cosRollCosYaw);

	pitch = glm::degrees(pitch);
	yaw = glm::degrees(yaw);
	roll = glm::degrees(roll);
}

void TransformComponent::clampEulerRotation()
{
	if (rot.x < 0.0f || rot.x >= FULL_ROTATION)
		rot.x = rot.x - (glm::floor(rot.x / FULL_ROTATION) * FULL_ROTATION);

	if (rot.y < 0.0f || rot.y >= FULL_ROTATION)
		rot.y = rot.y - (glm::floor(rot.y / FULL_ROTATION) * FULL_ROTATION);

	if (rot.z < 0.0f || rot.z >= FULL_ROTATION)
		rot.z = rot.z - (glm::floor(rot.z / FULL_ROTATION) * FULL_ROTATION);
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
