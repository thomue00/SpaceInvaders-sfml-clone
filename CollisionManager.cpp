#include "CollisionManager.h"



CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

bool CollisionManager::Overlap(sf::FloatRect r1, sf::FloatRect r2)
{
	return r1.intersects(r2);
}

bool CollisionManager::Overlap(Entity e1, Entity e2)
{
	if (!e1.IsAlive() || !e2.IsAlive()) {
		return false;
	}
	return CollisionManager::Overlap(e1.GetRect(), e2.GetRect());
}
