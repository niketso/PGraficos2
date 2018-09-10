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
		
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);
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
																		// Los siguientes comandos le dar�n caracter�sticas especiales al 'vertexbuffer' 
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
																		// Darle nuestros v�rtices a  OpenGL.
	glBufferData(GL_ARRAY_BUFFER, size , buffer , GL_STATIC_DRAW);
	return vertexbuffer;
}

void Renderer::DrawBuffer(unsigned int vtxbuffer, int size) 
{
																		// 1rst attribute buffer : v�rtices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vtxbuffer);
	glVertexAttribPointer(
		0,																// atributo 0. No hay raz�n particular para el 0, pero debe corresponder en el shader.
		3,																// tama�o
		GL_FLOAT,														// tipo
		GL_FALSE,														// normalizado?
		0,																// Paso
		(void*)0														// desfase del buffer
	);
																		// Dibujar el tri�ngulo !
	glDrawArrays(GL_TRIANGLES, 0, size);								// Empezar desde el v�rtice 0S; 3 v�rtices en total -> 1 tri�ngulo
	glDisableVertexAttribArray(0);
}

void Renderer::DestroyBuffer(unsigned int buffer) 
{
	glDeleteBuffers(1, &buffer);
}

