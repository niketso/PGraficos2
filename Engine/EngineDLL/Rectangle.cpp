#include "Rectangle.h"
Rectangle::Rectangle(Renderer *render) :Entity(render)
{
	shouldDispose = false;
	material = NULL;
	vertex = NULL;
	bufferId = -1;

	vertex = new float[12]
	{
		-1.0f,-1.0f , 0.0f ,
		 1.0f,-1.0f , 0.0f ,
		-1.0f, 1.0f , 0.0f ,
		 1.0f, 1.0f , 0.0f
	};

	SetVertices(vertex, 4);

	colorvertex = new float[12]
	{
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f
	};
	SetColorVertices(colorvertex, 4);
}

Rectangle::~Rectangle()
{
	Dispose();
}

void Rectangle::SetVertices(float* vertices, int count)
{
	Dispose();
	vtxCount = count;
	shouldDispose = true;
	bufferId = render->GenBuffer(vertices, sizeof(float)* count * 3);

}
void Rectangle::SetColorVertices(float* vertices, int count)
{
	
	colorVtxCount = count;
	shouldDispose = true;
	colorBufferId = render->GenColorBuffer(vertices, sizeof(float)* count * 3);

}

void Rectangle::Draw()
{

	render->LoadIdentityMatrix();
	render->SetWorldMatrix(WorldMatrix);

	if (material != NULL) {
		material->Bind();
		material->SetMatrixProperty("WVP", render->GetWvp());
	}

	render->BeginDraw(0);
	render->BeginDraw(1);
	render->BindBuffer(bufferId, 0);
	render->BindColorBuffer(colorBufferId, 1);
	render->DrawBuffer(vtxCount);
	render->EndDraw(0);
	render->EndDraw(1);
}

void Rectangle::SetMaterial(Material* material)
{
	this->material = material;
}

void Rectangle::Dispose()
{
	if (shouldDispose)
	{
		render->DestroyBuffer(bufferId);
		delete[] vertex;
		shouldDispose = false;
	}
}