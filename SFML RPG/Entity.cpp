#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.f,50.f));
	this->shape.setFillColor(sf::Color::Green);
	this->movementSpeed = 100.f;
}

Entity::~Entity()
{
}

void Entity::Move(const float& dt, const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
}

void Entity::Update(const float& dt)
{

}

void Entity::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
