#include "Node.h"



Node::Node()
{
	childList = new list<Node>();
	componentList = new list<Component>();

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
	componentList->push_back(*_component);
}

void Node::RemoveComponent(Component *_component)
{
	componentList->remove(*_component);
}

void Node::AddChild(Node _node)
{
	childList->push_back(_node);
}

void Node::RemoveChild(Node _node)
{
	childList->remove(_node);
}

bool Node::Update()
{
	return false;
}

void Node::Draw()
{
	// guardar world matrix antes de usar y al final del draw volver a poner la vieja.
}