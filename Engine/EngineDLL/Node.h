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
	glm::mat4 transform;
	glm::mat4 aux;
public:
	vector<Node*> childVec;
	vector<Component*> componentVec;
	Node();
	~Node();
	bool start();
	void AddComponent(Component *_component);
	void AddChild(Node *_node);
	bool Update();
	void Draw();//2 for
};

