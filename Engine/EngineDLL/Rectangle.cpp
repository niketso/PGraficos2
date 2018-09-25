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

void Rectangle::Draw()
{

	render->LoadIdentityMatrix();
	render->SetWorldMatrix(WorldMatrix);

	if (material != NULL) {
		material->Bind();
		material->SetMatrixProperty("WVP", render->GetWvp());
	}

	render->BeginDraw(0);
	render->BindBuffer(0);
	render->DrawBuffer(bufferId, vtxCount);
	render->EndDraw(0);
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