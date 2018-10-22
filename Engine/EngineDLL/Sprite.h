#pragma once
#include "Exports.h"
#include "Shape.h"
#include "Importer.h"

class ENGINEDLL_API Sprite:public Shape
{
	BMPheader header;
	const char* file;
	bool shouldDisposeTexture;
	unsigned int textureBufferId;
	float *txtrevertex;
	int textreVtxCount;
	
public:
	Sprite(Renderer * render, const char* name);
	~Sprite();
	void SetTextureVertices(float* vertices, int count);
	void DisposeTexture();
	void Draw() override;
	void DrawMesh(int drawType) override;
};

