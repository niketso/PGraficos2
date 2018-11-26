#include "Sprite.h"

Sprite::Sprite(Renderer* render,int column, int rows): Shape (render)
{
	
	txtreUVvertex = NULL;
	UVBufferId = - 1;
	textureBufferId = - 1;
	
	shouldDisposeTexture = false;

	vertex = new float[12]
	{
		-1.0f,-1.0f , 0.0f ,
		-1.0f,1.0f , 0.0f ,
		1.0f, -1.0f , 0.0f ,
		1.0f, 1.0f , 0.0f
	};

	SetVertices(vertex, 4);

	txtreUVvertex = new float[8]
	{
		0.0f,0.0f,
		0.0f,1.0f,
		1.0f,0.0f,
		1.0f,1.0f	
	};

	SetTextureVertices(txtreUVvertex, 4);
	
}


Sprite::~Sprite()
{
	DisposeTexture();
}

void Sprite::SetTextureVertices(float* vertices, int count)
{
	DisposeTexture();
	textreVtxCount = count;
	shouldDisposeTexture = true;
	
	UVBufferId = render->GenBuffer(vertices, sizeof(float)* count * 2);
}

void Sprite::LoadTexture(const char* name)
{
	header = Importer::LoadBMP(name);
	textureBufferId = render->GenTextureBuffer(header.width,header.height,header.data);
	//material->BindTexture("myTextureSampler", textureUVBufferId);
}

void Sprite::DisposeTexture()
{
	if (shouldDisposeTexture)
	{
		render->DestroyBuffer(UVBufferId);
		shouldDispose = false;
	}
}


void Sprite::DrawMesh(int drawType)
{
	render->LoadIdentityMatrix();
	render->SetWorldMatrix(WorldMatrix);

	if (material != NULL) {
		material->Bind();
		material->SetMatrixProperty("WVP", render->GetWvp());
		material->BindTexture("myTextureSampler", textureBufferId);
	}
	
	//render->BindTexture(textureBufferId,textureUVBufferId);	
	render->BeginDraw(0);	
	render->BeginDraw(1);
	render->BindBuffer(bufferId, 0);
	render->BindTextureBuffer(UVBufferId, 1);
	render->DrawBuffer(vtxCount, drawType);
	render->EndDraw(0);
	render->EndDraw(1);
}

void Sprite::Draw() 
{
	DrawMesh(GL_TRIANGLE_STRIP);
}
