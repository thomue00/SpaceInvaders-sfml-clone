#pragma once
#include "Entity.h"
struct Enemy : public Entity
{
public:
	Enemy() : Enemy(0, 0) { }
	Enemy(float,float);
	~Enemy();

	void Draw(sf::RenderWindow &win) override;

	void Reset();
};

