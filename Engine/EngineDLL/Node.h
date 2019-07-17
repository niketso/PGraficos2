#pragma once
#include "Exports.h"
#include "Component.h"
#include "TransformComponent.h"
#include "Renderer.h"
#include "glm/glm.hpp"
#include <vector>

using namespace std;
class  ENGINEDLL_API Node
{
private:
	
	Node *parent;
	Renderer *render;
	
	glm::mat4 transform;
	glm::mat4 aux;
public:
	TransformComponent *transformComponent;
	vector<Node*> childVec;
	vector<Component*> componentVec;
	Node();
	Node(Node*parent);
	~Node();
	void Start();
	void AddComponent(Component *_component);
	Node * GetChild(unsigned int i);
	Component * GetComponent(ComponentType type);
	void AddChild(Node *_node);
	void SetParent(Node *_node);
	bool Update();
	void Draw();
	
};

