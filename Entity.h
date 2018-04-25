#pragma once
#ifndef ENTITYH
#define ENTITYH

#include <SFML\Graphics.hpp>
#include "Constants.h"

struct Entity
{

public:
	Entity();
	virtual ~Entity();

	virtual void SetPosition(float, float);
	virtual void Move(float, float);
	virtual void SetSpeed(float s);
	virtual void Draw(sf::RenderWindow &win);
	sf::Vector2f GetPosition();
	sf::FloatRect GetRect();
	bool IsAlive();
	void Kill();

protected:

	void ClampPosition();

	sf::Sprite sprite;
	sf::Texture texture;
	float speed;
	bool isAlive;
};

#endif