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
	
	Renderer *render;
	
	glm::mat4 transform;
	glm::mat4 aux;
public:
	TransformComponent *transformComponent;
	vector<Node*> childVec;
	vector<Component*> componentVec;
	Node(Renderer* render);
	Node(Node*parent, Renderer* render);
	~Node();
	void Start();
	void AddComponent(Component *_component);
	Node * GetChild(unsigned int i);
	Component * GetComponent(ComponentType type);
	void AddChild(Node *_node);
	void Update();
	void Draw();
	void Move(float x, float y, float z);
	
};

