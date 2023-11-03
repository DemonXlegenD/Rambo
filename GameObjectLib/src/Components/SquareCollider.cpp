#include "Components/SquareCollider.h"
#include "GameObject.h"

bool SquareCollider::IsColliding(const SquareCollider& _colliderA, const SquareCollider& _colliderB)
{
	const Maths::Vector2f positionA = _colliderA.GetOwner()->GetPosition();
	const Maths::Vector2f positionB = _colliderB.GetOwner()->GetPosition();
	return (positionA.x - _colliderA.GetWidth() / 2  < positionB.x + _colliderB.GetWidth() / 2 && positionA.x + _colliderA.GetWidth() / 2 > positionB.x - _colliderB.GetWidth() / 2 && positionA.y < positionB.y + _colliderB.GetHeight() && positionA.y + _colliderA.GetHeight() > positionB.y);
}