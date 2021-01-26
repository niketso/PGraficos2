#include "Component.h"


Component::Component()
{
	_type = ComponentType::_defaultComponent;
}

void Component::SetType(ComponentType type)
{
	_type = type;
}


ComponentType  Component::GetType()
{
	return _type;
}
