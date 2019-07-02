#include "Node.h"



Node::Node()
{	
	render = new Renderer();
	transform = glm::mat4(1.0);
	aux = glm::mat4(1.0);
}


Node::~Node()
{
}

bool Node::start()
{
	
	
	
}

void Node::AddComponent(Component *_component)
{
	//Necesito indicar con un enum el componente que agrego?
	componentVec.push_back(_component);
}

void Node::AddChild(Node* _node)
{
	childVec.push_back(_node);
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
	render->MultiplyWorldMatrix(transform);
	for (int i = 0; i < childList->size(); i++)
	{
		if (true)
		{

		}
	}
	for (size_t i = 0; i < componentList->size(); i++)
	{

	}
	render->SetWorldMatrix(aux);
}