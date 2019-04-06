#include "Camera.h"


Camera::Camera(Renderer *render) 
{
	r1 = render;
	camPos = glm::vec3(0.0f, 0.0f, 0.0f);
	eyePos = glm::vec3(0.0f, 0.0f, 3.0f);
	upPos = glm::vec3(0.0f, 1.0f, 0.0f);

}

Camera::~Camera()
{
}
void Camera::Walk(float dir)
{
	camPos.z += dir;
	eyePos.z += dir;
	r1->SetViewMatrix(eyePos, camPos, upPos);
}
void Camera::Strafe(float dir)
{
	camPos.x += dir;
	eyePos.x += dir;
	r1->SetViewMatrix(eyePos, camPos, upPos);
}
void Camera::Pitch(float dir) 
{
	upPos += dir;
	r1->SetViewMatrix(eyePos, camPos, upPos);
}
void Camera::yaw(float dir) 
{

}
void Camera::Roll(float dir)
{

}


