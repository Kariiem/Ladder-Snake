#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

GameObject::GameObject()
{
}
void GameObject::SetPosition(CellPosition pos)
{
	position=pos;
}
CellPosition GameObject::GetPosition() const
{
	return position;
}
bool GameObject::IsOverlapping(GameObject*newObj)
{
	return false;
}
GameObject::~GameObject()
{
}