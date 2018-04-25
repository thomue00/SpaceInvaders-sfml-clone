#pragma once
#ifndef COLLISIONMANAGERH
#define COLLISIONMANAGERH
#include <SFML\Graphics.hpp>
#include "Entity.h"
class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	static bool Overlap(sf::FloatRect r1, sf::FloatRect r2);
	static bool Overlap(Entity e1, Entity e2);
};

#endif