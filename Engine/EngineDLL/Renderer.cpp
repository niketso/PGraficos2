#include "Renderer.h"
#include <GL\glew.h>
#include <GLFW\glfw3.h>



Renderer::Renderer()
{
	
}
Renderer::~Renderer()
{
}
bool Renderer::Start(Window * windowPTR) {
	
	if (windowPTR != NULL) 
	{
		
		window = windowPTR;
		glfwMakeContextCurrent((GLFWwindow*)window->GetWindow());

		if (glewInit() != GLEW_OK) {
			cout<< "Fall� al inicializar GLEW\n"<<endl;
			return -1;
		}
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);
		

		//Inicializo la matriz de projeccion.
		//projectionMatrix = glm::ortho(-10.0f, 10.0f, -10.0f,10.0f, 0.0f, 100.f);
		//perspectiveProjectionMatrix = glm::perspective(45.0f, 1.06f, 0.1f, 1000.f);
		orthoProjectionMatrix  = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.f);

		perspectiveProjectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f /3.0f, 0.1f, 100.0f);

		projectionMatrix = perspectiveProjectionMatrix;

		//Inicializo la matriz de vista.
		camPos = glm::vec3(0, 0, 0);
		eyePos = glm::vec3(0, 0, 3);
		upPos = glm::vec3(0, 1, 0);
		viewMatrix = glm::lookAt(
			eyePos,
			camPos,
			upPos
		);
		//Inicializo la matriz de mundo.
		worldMatrix = glm::mat4(1.0f);
		UpdateWVP();
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		UpdateWVP();

		cout << "Renderer::Start()" << endl;
		return true;
	}
	
	return false;
	
}
bool Renderer::Stop() {
	cout << "Renderer::Stop()" << endl;
	return false;
}

void Renderer::ClearScreen() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::ClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void Renderer::SwapBuffers() 
{
	glfwSwapBuffers((GLFWwindow*)window->GetWindow());
}

unsigned int Renderer::GenBuffer(float* buffer, int size) 
{
	unsigned int vertexbuffer;
	glGenBuffers(1, &vertexbuffer);																		 
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);																		
	glBufferData(GL_ARRAY_BUFFER, size , buffer , GL_STATIC_DRAW);

	return vertexbuffer;
}

unsigned int Renderer::GenColorBuffer(float* buffer, int size)
{
	unsigned int colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);

	return colorbuffer;
}

unsigned int Renderer::GenTextureBuffer( int width, int height,unsigned char* data)
{
	// Se Crea una textura OpenGL
	unsigned int  texturebuffer;
	glGenTextures(1, &texturebuffer);

	// Se "Ata" la nueva textura : Todas las futuras funciones de texturas van a modificar esta textura
	glBindTexture(GL_TEXTURE_2D, texturebuffer);

	// Se le pasa la imagen a OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	//glGenerateMipmap(GL_TEXTURE_2D);

	return texturebuffer;
}

unsigned int Renderer::GenIndexBuffer (unsigned int* buffer, int size)
{
	unsigned int idxbuffer;
	glGenBuffers(1, &idxbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), &buffer[0], GL_STATIC_DRAW);

	return idxbuffer;
}

unsigned int Renderer::GenIndexBuffer(vector<unsigned int> index)
{
	unsigned int idxbuffer;
	glGenBuffers(1, &idxbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size() * sizeof(unsigned int), &index[0], GL_STATIC_DRAW);

	return idxbuffer;
}

void Renderer::DrawBuffer(int size, int drawType) 
{																																		
	glDrawArrays(drawType, 0, size);								
}

void Renderer::DrawIndex(int idxcount)
{
	glDrawElements(
		GL_TRIANGLES,      
		idxcount,    
		GL_UNSIGNED_INT,   
		(void*)0           
	);
}

void Renderer::DestroyBuffer(unsigned int buffer) 
{
	glDeleteBuffers(1, &buffer);
}

void Renderer::BindBuffer(unsigned int vtxbuffer, unsigned int atribId)
{
	glBindBuffer(GL_ARRAY_BUFFER, vtxbuffer);
	glVertexAttribPointer(
		atribId,														// Le paso la ubicacion de donde se guardo la mempria del vertice
		3,																// tama�o
		GL_FLOAT,														// tipo
		GL_FALSE,														// normalizado?
		0,																// Paso
		(void*)0														// desfase del buffer
	);

}
void Renderer::BindColorBuffer(unsigned int clrbuffer, unsigned int atribId)
{
	glBindBuffer(GL_ARRAY_BUFFER, clrbuffer);
	glVertexAttribPointer(
		atribId,														// Le paso la ubicacion de donde se guardo la mempria del vertice
		3,																// tama�o
		GL_FLOAT,														// tipo
		GL_FALSE,														// normalizado?
		0,																// Paso
		(void*)0														// desfase del buffer
	);

}

void Renderer::BindTextureBuffer(unsigned int txtrebuffer, unsigned int atribId) 
{
	glBindBuffer(GL_ARRAY_BUFFER, txtrebuffer);
	glVertexAttribPointer(
		atribId,														// Le paso la ubicacion de donde se guardo la mempria del vertice
		2,																// tama�o
		GL_FLOAT,														// tipo
		GL_FALSE,														// normalizado?
		0,																// Paso
		(void*)0														// desfase del buffer
	);
}

void Renderer::BindMeshBuffer(unsigned int idxbuffer)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxbuffer);
	
}

/*void Renderer::BindTexture(unsigned int Id, unsigned int txtreBuffer) 
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Id);

	glUniform1i(txtreBuffer, 0);
}*/

void Renderer::BeginDraw(unsigned int atribId )
{
	glEnableVertexAttribArray(atribId);
}
void Renderer::EndDraw(unsigned int atribId)
{
	glDisableVertexAttribArray(atribId);
}
void Renderer::LoadIdentityMatrix()
{
	worldMatrix = glm::mat4(1.0f);
}
void Renderer::UpdateWVP() 
{
	wvp = projectionMatrix * viewMatrix * worldMatrix ;
}
glm::mat4& Renderer::GetWvp()
{
	return wvp;
}
void Renderer::TranslateCamera(glm::vec3 pos)
{
	
	camPos += pos;
	//eyePos += glm::vec3(pos.x, pos.y, 0);
	eyePos += pos;
	viewMatrix = glm::lookAt(
		eyePos,
		camPos,
		upPos
	);

	UpdateWVP();
}
glm::mat4 & Renderer::GetProjectionMatrix()
{
	return projectionMatrix;
}
void Renderer::MultiplyWorldMatrix(glm::mat4 mat)
{
	worldMatrix *= mat;
	UpdateWVP();
}
void Renderer::SetWorldMatrix(glm::mat4 mat) 
{
	worldMatrix = mat;
	UpdateWVP();
}

void Renderer::SetViewMatrix(glm::mat4 mat)
{
	viewMatrix = mat;
	UpdateWVP();
}

void Renderer::SetProjectionMatrix(glm::mat4 mat)
{
	projectionMatrix = mat;
	UpdateWVP();
}

glm::mat4& Renderer::GetWorldMatrix()
{
	return worldMatrix;
}

glm::mat4 & Renderer::GetViewMatrix()
{
	return viewMatrix;
}

void Renderer::UpdateTexture(unsigned int txt) 
{
	glGenTextures(1, &txt);
	glBindTexture(GL_TEXTURE_2D, txt);
}

glm::vec3 Renderer::GetCameraPos() 
{
	return camPos;
}

void Renderer::SetOrthoProjectionMatrix(const float left, const float right, const float bottom, const float top, const float ZNear, const float ZFar)
{
	orthoProjectionMatrix = glm::ortho(left, right, bottom, top, ZNear, ZFar);
	projectionMatrix = orthoProjectionMatrix;
}
void Renderer::SetPerspectiveProjectionMatrix(const float angle, const float aspect, const float ZNear, const float ZFar) 
{
	perspectiveProjectionMatrix = glm::perspective(angle, aspect, ZNear, ZFar);
	projectionMatrix = perspectiveProjectionMatrix;
}
void Renderer::SetViewMatrix(glm::vec3 eye, glm::vec3 cam, glm::vec3 up)
{
	eyePos = eye;
	camPos = cam;
	upPos = up;
	viewMatrix = glm::lookAt(
		eyePos,
		camPos,
		upPos
	);
	
	UpdateWVP();
}
void Renderer::SwitchProjectionMatrix(ProjectionMatrixType pmt  )
{	
	switch (pmt)
	{
		case perspective:
		projectionMatrix = perspectiveProjectionMatrix;
		break;
		case orthographic:
		projectionMatrix = orthoProjectionMatrix;
		break;
	}
	
}
