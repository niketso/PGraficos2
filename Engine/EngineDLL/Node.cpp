#include "Node.h"



Node::Node()	
{	
	Start();
}


Node::~Node()
{
}

void Node::Start()
{
	render = new Renderer();
	transform = glm::mat4(1.0);
	aux = glm::mat4(1.0);
	parent = nullptr;
}

void Node::AddComponent(Component *_component)
{
	//Necesito indicar con un enum el componente que agrego?
	componentVec.push_back(_component);
}

Component * Node::GetComponent()
{
	//Terminar en la facultad

	for (int i = 0; i < componentVec.size(); i++)
	{
		componentVec[i]->_type;
		return componentVec[i];
	}
	
}



void Node::AddChild(Node* _node)
{
	childVec.push_back(_node);
}

void Node::SetParent(Node * _node)
{
	parent = _node;
}

bool Node::Update()
{
	//por ahora no  
	return false;
}

void Node::Draw()
{
	// guardar world matrix antes de usar y al final del draw volver a poner la vieja.
	aux = render->GetWorldMatrix();
	if(parent == nullptr)
	render->MultiplyWorldMatrix(transform);
	
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