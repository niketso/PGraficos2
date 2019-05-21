#include "Mesh.h"
#include"ModelImporter.h"



Mesh::Mesh(Renderer *render,const char* filename,const char* texturename):Shape(render)
{
	//textures = new vector<BMPheader*>;
	vector<BMPheader*> *textures = new vector<BMPheader*>();
	vector<MeshEntry> *entry = new vector<MeshEntry>();
	

	ModelImporter::LoadMesh(filename,texturename,*textures,*entry,render);
	

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

