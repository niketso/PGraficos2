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
			cout<< "Falló al inicializar GLEW\n"<<endl;
			return -1;
		}
		
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);

		//Inicializo la matriz de projeccion.
		projectionMatrix = glm::ortho(-10.0f, 10.0f, -10.0f,10.0f, 0.0f, 100.f);
		//Inicializo la matriz de vista.
		viewMatrix = glm::lookAt(
			glm::vec3(0, 0, 3),
			glm::vec3(0, 0, 0),
			glm::vec3(0, 1, 0)
		);
		//Inicializo la matriz de mundo.
		worldMatrix = glm::mat4(1.0f);
		
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

void Renderer::DrawBuffer(int size) 
{																																		
	glDrawArrays(GL_TRIANGLE_STRIP, 0, size);								
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
		3,																// tamaño
		GL_FLOAT,														// tipo
		GL_FALSE,														// normalizado?
		0,																// Paso
		(void*)0														// desfase del buffer
	);

}
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

