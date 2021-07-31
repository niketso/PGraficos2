#pragma once
#include "Exports.h"
#include "Window.h"
#include "Definitions.h"
#include<glm/glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include <vector>
#include <iostream>
using namespace std;
class ENGINEDLL_API Renderer
{
private:
	unsigned int VertexArrayID;
	Window * window;
	glm::mat4 worldMatrix;
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	glm::mat4 wvp;

	glm::mat4 orthoProjectionMatrix;
	glm::mat4 perspectiveProjectionMatrix;


	glm::vec3 camPos;
	glm::vec3 eyePos;
	glm::vec3 upPos;

public:
	Renderer();
	~Renderer();
	bool Start(Window *windowPTR);
	bool Stop();
	void ClearScreen();
	void ClearColor(float r, float g, float b, float a);
	void SwapBuffers();
	unsigned int  GenBuffer(float* buffer, int size);
	unsigned int  GenColorBuffer(float* buffer, int size);
	unsigned int GenTextureBuffer(int width, int height, unsigned char* data);
	unsigned int GenIndexBuffer( unsigned int* buffer, int size);
	unsigned int GenIndexBuffer(vector<unsigned int> index);
	void BindBuffer(unsigned int vtxbuffer, unsigned int name);
	void BindColorBuffer(unsigned int clrbuffer, unsigned int name);
	void BindTextureBuffer(unsigned int txtrebuffer, unsigned int name);
	void BindMeshBuffer(unsigned int idxbuffer);
	void BeginDraw(unsigned int name);
	void EndDraw(unsigned int name);
	void DrawBuffer( int size,int drawType);
	void DrawIndex(int idxcount);
	void DestroyBuffer(unsigned int buffer);
	void UpdateWVP();
	glm::mat4&  GetWvp();
	void TranslateCamera(glm::vec3 pos);
	void LoadIdentityMatrix();
	void SetWorldMatrix(glm::mat4 mat);
	glm::mat4& GetWorldMatrix();
	void MultiplyWorldMatrix(glm::mat4 mat);
	void UpdateTexture(unsigned int txt);
	void SetOrthoProjectionMatrix(const float left, const float right, const float bottom, const float top, const float ZNear, const float ZFar);
	void SetPerspectiveProjectionMatrix(const float angle, const float aspect, const float ZNear, const float ZFar);
	void SwitchProjectionMatrix(ProjectionMatrixType pmt);
	void SetViewMatrix(glm::vec3 eye, glm::vec3 cam, glm::vec3 up);
	glm::vec3 GetCameraPos();
	int Draws = 0;
};
