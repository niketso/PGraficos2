#pragma once
#include "Exports.h"
#include "Component.h"
#include <list>

using namespace std;
class  ENGINEDLL_API Node
{
private:
public:
	list<Node> * childList;
	list<Component> * componentList;
	Node();
	~Node();
	bool start();
	void AddComponent(Component *_component);
	void RemoveComponent(Component *_component);
	void AddChild(Node _node);
	void RemoveChild(Node _node);
	bool Update();//2  for 
	void Draw();
};

