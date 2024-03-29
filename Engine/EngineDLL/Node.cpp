#include "Node.h"



Node::Node(Renderer* render)	:Entity(render)
{	
	this->render = render;
	childVec = new vector<Node*>();
	componentVec = new vector<Component*>();
	Start();
}

Node::Node(Node* parent, Renderer* render) :Entity(render)
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
	childs = 0;
}

void Node::AddComponent(Component *_component)
{
	//Necesito indicar con un enum el componente que agrego?
	componentVec->push_back(_component);
}

Node* Node::GetChild(unsigned int i)
{		
	return childVec->at(i);
}

Component * Node::GetComponent(ComponentType type)
{
	
	for (int i = 0; i < componentVec->size(); i++)
	{
		if (componentVec->at(i)->GetType() == type)
		{
			
			return componentVec->at(i);
		}
	}
	
}


void Node::AddChild(Node* _node)
{
	if(_node != NULL)
	childVec->push_back(_node);
	childs++;
}


void Node::Update()
{
	glm::mat4 actualWorldMatrix = render->GetWorldMatrix();
	glm::mat4 actualViewMatrix = render->GetViewMatrix();
	glm::mat4 actualProjectionMatrix = render->GetProjectionMatrix();

	render->MultiplyWorldMatrix(render->GetWorldMatrix());
	for (int i = 0; i < componentVec->size(); i++)
	{
		componentVec->at(i)->Update();
	}
	for (int i = 0; i < childVec->size(); i++)
	{
		childVec->at(i)->Update();
	}
	render->SetWorldMatrix(actualWorldMatrix);
	render->SetViewMatrix(actualViewMatrix);
	render->SetProjectionMatrix(actualProjectionMatrix);
}

void Node::Draw()
{
	// guardar world matrix antes de usar y al final del draw volver a poner la vieja.
	glm::mat4 actualWorldMatrix = render->GetWorldMatrix();
	glm::mat4 actualViewMatrix = render->GetViewMatrix();
	glm::mat4 actualProjectionMatrix = render->GetProjectionMatrix();

	render->MultiplyWorldMatrix(render->GetWorldMatrix());
	
	for (int i = 0;i < componentVec->size();i++)
	{
		componentVec->at(i)->Draw();
	}
	for (int i = 0;i < childVec->size(); i++)
	{
		childVec->at(i)->Draw();
	}
	render->SetWorldMatrix(actualWorldMatrix);
	render->SetViewMatrix(actualViewMatrix);	
	render->SetProjectionMatrix(actualProjectionMatrix);

}

void Node::Move(float x, float y, float z)
{
	x = transformComponent->GetPos().x + x;
	y = transformComponent->GetPos().y + y;
	z = transformComponent->GetPos().z + z;

	transformComponent->SetPos(x, y, z);


}

int Node::GetCantChild()
{
	childs = childVec->size();
	return childs;
}

TransformComponent * Node::GetTransform()
{	
	return transformComponent;
}
