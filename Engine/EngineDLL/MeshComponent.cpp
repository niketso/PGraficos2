#include "MeshComponent.h"
#include "ModelImporter.h"



MeshComponent::MeshComponent(ComponentType type,Renderer *render,Camera *camera)
{
	_type = type;
	_render = render;
	_camera = camera;
	this->SetType(type);
	bCube = new BoundingCube(render);
}



MeshComponent::~MeshComponent()
{
}

void MeshComponent::Update()
{
}

void MeshComponent::Draw()
{
	bool shouldDraw = true;
	//bool shouldDraw = false;
	
	
	if ( _camera->boxInFrustrum(bCube) != States::OUTSIDE)
	{
		shouldDraw = true;
	}
	
	if (shouldDraw)
	{
		_render->Draws++;
		if (_material != NULL) {
			_material->Bind();
			_material->SetMatrixProperty("WVP", _render->GetWvp());
			_material->BindTexture("myTextureSampler", textureBufferID);
		}
		_render->BeginDraw(0);
		_render->BeginDraw(1);
		_render->BindBuffer(vertexBufferID, 0);
		_render->BindTextureBuffer(uvBufferID, 1);
		_render->BindMeshBuffer(indexBufferID);
		_render->DrawIndex(_indexVec.size());
		_render->EndDraw(0);
		_render->EndDraw(1);

	}
}

void MeshComponent::UpdateData(glm::vec3 min, glm::vec3 max)
{
	glm::vec3 auxVec;
	auxVec.x = max.x;
	auxVec.y = max.y;
	auxVec.z = max.z;
	bCube->setVertex(0, auxVec);

	auxVec.x = max.x;
	auxVec.y = max.y;
	auxVec.z = min.z;
	bCube->setVertex(1, auxVec);

	auxVec.x = min.x;
	auxVec.y = max.y;
	auxVec.z = max.z;
	bCube->setVertex(2, auxVec);

	auxVec.x = min.x;
	auxVec.y = max.y;
	auxVec.z = min.z;
	bCube->setVertex(3, auxVec);

	auxVec.x = max.x;
	auxVec.y = min.y;
	auxVec.z = max.z;
	bCube->setVertex(4, auxVec);

	auxVec.x = max.x;
	auxVec.y = min.y;
	auxVec.z = min.z;
	bCube->setVertex(5, auxVec);

	auxVec.x = min.x;
	auxVec.y = min.y;
	auxVec.z = max.z;
	bCube->setVertex(6, auxVec);

	auxVec.x = min.x;
	auxVec.y = min.y;
	auxVec.z = min.z;
	bCube->setVertex(7, auxVec);
}

void MeshComponent::SetVertices(vector<float> verticesVec)
{
	_verticesVec = verticesVec;
	vertexBufferID = _render->GenBuffer(&verticesVec[0], verticesVec.size() * sizeof(float));
}

void MeshComponent::SetUv(vector<float> uvVec)
{
	_uvVec = uvVec;
	uvBufferID = _render->GenBuffer(&uvVec[0], uvVec.size() * sizeof(float));
}

void MeshComponent::SetIndex(vector<unsigned int> indexVec)
{
	_indexVec = indexVec;
	indexBufferID = _render->GenIndexBuffer(indexVec);
}

void MeshComponent::LoadMaterial()
{
	_material = new Material();
	ProgramID = _material->LoadShaders("TextureVertexShader.txt","TextureFragmentShader.txt");
}

void MeshComponent::SetTexture(const char * texturename)
{
	_texture = Importer::LoadBMP(texturename);
	textureBufferID = _render->GenTextureBuffer(_texture.width, _texture.height, _texture.data);
}


