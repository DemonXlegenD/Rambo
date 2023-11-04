#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "Component.h"

class SquareCollider : public Component
{
public:
	SquareCollider() = default;
	~SquareCollider() override = default;

	float GetWidth() const { return width; }
	float GetHeight() const { return height; }

	void SetWidth(const float _width) { width = _width; }
	void SetHeight(const float _height) { height = _height; }

	static bool IsColliding(const SquareCollider& _colliderA, const SquareCollider& _colliderB);

	bool IsAbove(const SquareCollider& _colliderA, const SquareCollider& _colliderB);
	bool IsLeft(const SquareCollider& _colliderA, const SquareCollider& _colliderB);
	bool IsRight(const SquareCollider& _colliderA, const SquareCollider& _colliderB);
	bool IsBelow(const SquareCollider& _colliderA, const SquareCollider& _colliderB);




private:
	float width = 1.0f;
	float height = 1.0f;
};
