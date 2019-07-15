#pragma once
#include "Exports.h"
#include "Component.h"
#include "Renderer.h"
#include "glm/glm.hpp"
#include <vector>

using namespace std;
class  ENGINEDLL_API Node
{
private:
	Renderer *render;
	Node *parent;
	glm::mat4 transform;
	glm::mat4 aux;
public:
	vector<Node*> childVec;
	vector<Component*> componentVec;
	Node();
	~Node();
	void Start();
	void AddComponent(Component *_component);
	Component * GetComponent();
	void AddChild(Node *_node);
	void SetParent(Node *_node);
	bool Update();
	void Draw();
};

