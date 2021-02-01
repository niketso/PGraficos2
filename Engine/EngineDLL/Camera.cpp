#include "Camera.h"

Camera::Camera(ComponentType type,Renderer *render)
{
	this->render = render;
	this->type = type;
	this->SetType(type);

	eyePos = glm::vec3(0.0f, 0.0f, 10.0f);
	upVec = glm::vec3(0.0f, 1.0f, 0.0f);


	forward = glm::vec4(0.0f, 0.0f, -1.0f,0.0f);
	right = glm::vec4(1.0f, 0.0f, 0.0f,0.0f);
	upDir = glm::vec4(0.0f, 1.0f, 0.0f,0.0f);

	camPos = eyePos + (glm::vec3)forward;

	nearD = 0.1f;
	farD = 100.0f;
	ratio = 4.0f / 3.0f;
	angle = glm::radians(45.0f);
	SetCamInternals();
	SetCamDef();
	
}

Camera::~Camera()
{
}

void Camera::Update() 
{
	render->SetViewMatrix(eyePos, camPos, upVec);
	
	//std::cout << camPos.x << " , "<< camPos.y << " , "<<camPos.z << std::endl;

}
void Camera::Draw()
{
}
void Camera::Walk(float dir)
{
	camPos += (glm::vec3)forward * dir;
	eyePos += (glm::vec3)forward * dir;

	SetCamDef();
	Update();
}
void Camera::Strafe(float dir)
{
	camPos += (glm::vec3)right * dir;
	eyePos += (glm::vec3)right * dir;
	SetCamDef();
	Update();
}
void Camera::Pitch(float dir) 
{
	//multiplicar por una matriz de rotacion a el eje x (right).
	 forward =  glm::rotate(glm::mat4(1.0f), dir, glm::vec3(right.x, right.y, right.z)) * forward;
	 upDir = glm::rotate(glm::mat4(1.0f), dir, glm::vec3(right.x, right.y, right.z)) * upDir;
	
	 upVec = (glm::vec3)upDir;
	 camPos = eyePos + (glm::vec3)forward;
	 SetCamDef();
	 Update();
}
void Camera::yaw(float dir) 
{
	//fijo up
	forward = glm::rotate(glm::mat4(1.0f), dir, glm::vec3(upVec.x, upVec.y, upVec.z)) * forward;
	right = glm::rotate(glm::mat4(1.0f), dir, glm::vec3(upVec.x, upVec.y, upVec.z)) * right;

	upVec = (glm::vec3)upDir;
	camPos = eyePos + (glm::vec3)forward;
	SetCamDef();
	Update();
}
void Camera::Roll(float dir)
{
	//fijo forward
	glm::mat4 rot = glm::rotate(glm::mat4(1.0f), dir, glm::vec3(forward.x, forward.y, forward.z));
	right = rot * right;
	upDir = rot * upDir;

	upVec = (glm::vec3)upDir;
	camPos = eyePos + (glm::vec3)forward;
	SetCamDef();
	Update();
}

void Camera::SetCamInternals()
{
	tang = glm::tan(angle * 0.5f);
	nh = nearD * tang;
	nw = nh * ratio;
}

void Camera::SetCamDef() {

	glm::vec3 right = (glm::vec3)this->right;
	glm::vec3 up = (glm::vec3)upDir;
	
	glm::vec3 nearCenter = (glm::vec3)camPos + (glm::vec3)upDir * nearD;
	glm::vec3 farCenter = (glm::vec3)camPos + (glm::vec3)upDir * farD;

	glm::vec3 leftPlaneVec = (nearCenter - right * nw) - (glm::vec3)camPos;
	glm::vec3 rightPlaneVec = (nearCenter + right * nw) - (glm::vec3)camPos;
	glm::vec3 topPlaneVec = (nearCenter + up * nh) - (glm::vec3)camPos;
	glm::vec3 bottomPlaneVec = (nearCenter - up * nh) - (glm::vec3)camPos;

	glm::vec3 normalLeft = glm::normalize(glm::cross(leftPlaneVec, up));
	glm::vec3 normalRight = -glm::normalize(glm::cross(rightPlaneVec, up));
	glm::vec3 normalTop = glm::normalize(glm::cross(topPlaneVec, right));
	glm::vec3 normalBottom = -glm::normalize(glm::cross(bottomPlaneVec, right));

	
	pl[NEARP] = generatePlane(-(glm::vec3)upDir, nearCenter);
	pl[FARP] = generatePlane((glm::vec3)upDir, farCenter);	
	pl[LEFT] = generatePlane(normalLeft, (glm::vec3)camPos);
	pl[RIGHT] = generatePlane(normalRight, (glm::vec3)camPos);
	pl[TOP] = generatePlane(normalTop, (glm::vec3)camPos);
	pl[BOTTOM] = generatePlane(normalBottom, (glm::vec3)camPos);
	

	
}

glm::vec4 Camera::generatePlane(glm::vec3 normal, glm::vec3 point)
{
	glm::vec4 plane;

	plane.x = normal.x;
	plane.y = normal.y;
	plane.z = normal.z;
	plane.w = -glm::dot(normal, point);

	return plane;
}

int Camera::boxInFrustrum(BoundingCube * boundingCube)
{
	bool isInsideFrustum = true;
	
	for (int i = 0; i < CUBE_VERTEX; i++) 
	{
		float dist;
		glm::vec3 vertexPosition = boundingCube->GetVertex(i);

		for (int j = 0; j < (int)Planes::COUNT; j++) 
		{
			glm::vec3 planeNormal = glm::vec3(pl[j]);
			dist = (glm::dot(planeNormal, vertexPosition)  + pl[j].w);

			if (dist <= 0.0f)
			{
				isInsideFrustum = false;
				break;
			}
										
		}		
		
		if (isInsideFrustum)
		{
			break;
		}
		
		//cout << dist << endl;
	}
	if (isInsideFrustum)
		return States::INSIDE;
		
	else	
		return States::OUTSIDE;
		
}

