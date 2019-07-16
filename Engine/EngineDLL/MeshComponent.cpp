#include "MeshComponent.h"
#include "ModelImporter.h"


MeshComponent::MeshComponent(ComponentType type,Renderer *render)
{
	//start(render,filename,texturename);
	
}



MeshComponent::~MeshComponent()
{
}

void MeshComponent::Update()
{
}

void MeshComponent::Draw()
{
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


