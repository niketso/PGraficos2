#include "Component.h"

void Component::SetType(ComponentType type)
{
	_type = type;
}

ComponentType  Component::GetType()
{
	return _type;
}
