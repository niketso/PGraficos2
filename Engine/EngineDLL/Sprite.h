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
	unsigned int textureUVBufferId;
	float *txtreUVvertex;
	int textreVtxCount;
	
public:
	Sprite(Renderer * render);
	~Sprite();
	void SetTextureVertices(float* vertices, int count);
	void LoadTexture(const char* name);
	void DisposeTexture();
	void Draw() override;
	void DrawMesh(int drawType) override;
};

