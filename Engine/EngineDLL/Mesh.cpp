#include "Mesh.h"



Mesh::Mesh(Renderer *render):Shape(render)
{
	vertex = new float[24]
	{
		//front
		-1.0, -1.0, 1.0,
		1.0, -1.0, 1.0,
		1.0, 1.0, 1.0,
		-1.0, 1.0, 1.0,
		// back
		-1.0, -1.0, -1.0,
		1.0, -1.0, -1.0,
		1.0, 1.0, -1.0,
		-1.0, 1.0, -1.0
	};
	SetVertices(vertex, 8);

	clrvertex = new float[24]
	{
		// front colors
	 1.0, 0.0, 0.0,
	 0.0, 1.0, 0.0,
	 0.0, 0.0, 1.0,
	 1.0, 1.0, 1.0,
	// back colors
	 1.0, 0.0, 0.0,
	 0.0, 1.0, 0.0,
	 0.0, 0.0, 1.0,
	1.0, 1.0, 1.0
	};
	SetColorVertices(clrvertex, 8);

	indxvertex = new unsigned int[36] 
	{
			0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};
	SetIndexVertices(indxvertex, 8);

}


Mesh::~Mesh()
{
}

void Mesh::Draw()
{
	DrawMesh(GL_TRIANGLES);
}

void Mesh::DrawMesh(int drawType)
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
	render->BindMeshBuffer(indexBufferId);
	render->DrawIndex(idxVtxCount);
	render->EndDraw(0);
	render->EndDraw(1);
}

