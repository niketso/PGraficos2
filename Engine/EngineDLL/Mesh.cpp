#include "Mesh.h"
#include"ModelImporter.h"



Mesh::Mesh(Renderer *render,const char* filename,const char* texturename):Shape(render)
{
	
	vector<BMPheader> *textures = new vector<BMPheader>();
	vector<MeshEntry> *entry = new vector<MeshEntry>();
	

	ModelImporter::LoadMesh(filename,texturename,textures,entry,render);
	
	//textureBufferId = render->GenTextureBuffer(textures->at(0).width, textures->at(0).height, textures->at(0).data);
	
	

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
		material->BindTexture("myTextureSampler", ModelImporter::GetTextureBuffer());
	}

	render->BeginDraw(0);
	render->BeginDraw(1);
	for (int i = 0; i < ModelImporter::m_Entries.size(); i++) {

		render->BindBuffer(ModelImporter::m_Entries[i].vertexBuffer, 0);
		render->BindTextureBuffer(ModelImporter::m_Entries[i].uvBuffer, 1);
		render->BindMeshBuffer(ModelImporter::m_Entries[i].indexBuffer);
		render->DrawIndex(ModelImporter::m_Entries[i].count);
	}
	render->EndDraw(0);
	render->EndDraw(1);
}

