#pragma once
#include "Entity.h"
struct PlayerShip : public Entity
{

public:

	PlayerShip() : PlayerShip(1) { }
	PlayerShip(float speed);
	~PlayerShip();

	void SetPosition(float, float) override;
	void Move(float, float) override;
	
	void Hit(float dmg);


private:

	float health;
	
};

