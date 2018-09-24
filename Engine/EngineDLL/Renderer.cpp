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

		
		ProjectionMatrix = glm::ortho(-10.0f, 10.0f, -10.0f,10.0f, 0.0f, 100.f);

		ViewMatrix = glm::lookAt(
			glm::vec3(0, 0, 3),
			glm::vec3(0, 0, 0),
			glm::vec3(0, 1, 0)
		);
		
		WorldMatrix = glm::mat4(1.0f);
		
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
																		// Los siguientes comandos le darán características especiales al 'vertexbuffer' 
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
																		// Darle nuestros vértices a  OpenGL.
	glBufferData(GL_ARRAY_BUFFER, size , buffer , GL_STATIC_DRAW);
	return vertexbuffer;
}

void Renderer::DrawBuffer(unsigned int vtxbuffer, int size) 
{
																		// 1rst attribute buffer : vértices
	glBindBuffer(GL_ARRAY_BUFFER, vtxbuffer);																			// Dibujar el triángulo !
	glDrawArrays(GL_TRIANGLES, 0, size);								// Empezar desde el vértice 0S; 3 vértices en total -> 1 triángulo
	
}

void Renderer::DestroyBuffer(unsigned int buffer) 
{
	glDeleteBuffers(1, &buffer);
}

void Renderer::BindBuffer(unsigned int atribId) 
{
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
	WorldMatrix = glm::mat4(1.0f);
}
void Renderer::UpdateWVP() 
{
	wvp = ProjectionMatrix * ViewMatrix * WorldMatrix ;
}
glm::mat4& Renderer::GetWvp()
{
	return wvp;
}
void Renderer::MultiplyWorldMatrix(glm::mat4 mat)
{
	WorldMatrix *= mat;
	UpdateWVP();
}
void Renderer::SetWorldMatrix(glm::mat4 mat) 
{
	WorldMatrix = mat;
	UpdateWVP();
}

