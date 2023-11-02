#include "GameObject.h"

void GameObject::AddComponent(Component* _component)
{
	_component->SetOwner(this);
	components.push_back(_component);
}

void GameObject::RemoveComponent(Component* _component)
{
	components.erase(std::remove(components.begin(), components.end(), _component), components.end());
}

void GameObject::Start() {
	for (Component* const& component : components) {
		component->Start();
	}
}

void GameObject::Update(sf::Time _delta) const
{
	if (this->isActive) {
		for (Component* const& component : components)
		{
			component->Update(_delta);
		}
	}

}

void GameObject::Render(sf::RenderWindow* _window) const
{
	if (isActive) {
		for (Component* const& component : components)
		{
			component->Render(_window);
		}
	}

}

