#include "Node.h"



Node::Node(Renderer* render)	
{	
	this->render = render;
	Start();
}

Node::Node(Node* parent, Renderer* render) 
{
	this->render = render;
}
Node::~Node()
{
}

void Node::Start()
{
	transformComponent = new TransformComponent(_TransformComponent,render);
	this->AddComponent(transformComponent);
	transform = glm::mat4(1.0);
	aux = glm::mat4(1.0);
}

void Node::AddComponent(Component *_component)
{
	//Necesito indicar con un enum el componente que agrego?
	componentVec.push_back(_component);
}

Node* Node::GetChild(unsigned int i)
{
	return childVec[i - 1];
}

Component * Node::GetComponent(ComponentType type)
{
	
	for (int i = 0; i < componentVec.size(); i++)
	{
		if (componentVec[i]->GetType() == type)
		{
			
			return componentVec[i];
		}
	}
	
}


void Node::AddChild(Node* _node)
{
	if(_node != NULL)
	childVec.push_back(_node);
}


void Node::Update()
{
	 
	for (int i = 0; i < componentVec.size(); i++)
	{
		componentVec[i]->Update();
	}
	for (int i = 0; i < childVec.size(); i++)
	{
		childVec[i]->Update();
	}
}

void Node::Draw()
{
	// guardar world matrix antes de usar y al final del draw volver a poner la vieja.
	aux = render->GetWorldMatrix();
	render->MultiplyWorldMatrix(transformComponent->GetWorldMat());
	
	for (int i = 0;i < componentVec.size();i++)
	{
		componentVec[i]->Draw();
	}
	for (int i = 0;i < childVec.size(); i++)
	{
		childVec[i]->Draw();
	}
	render->SetWorldMatrix(aux);
}

void Node::Move(float x, float y, float z)
{
	x = transformComponent->GetPos().x + x;
	y = transformComponent->GetPos().y + y;
	z = transformComponent->GetPos().z + z;

	transformComponent->SetPos(x, y, z);
}
