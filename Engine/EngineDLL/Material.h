#pragma once
#include "Exports.h"
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
class ENGINEDLL_API Material
{
	unsigned int ProgramID;
public:
	Material();
	~Material();
	void Bind();
	unsigned int  LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
	void SetMatrixProperty(const char* name, glm::mat4& mat );
};

