#pragma once
#include "Entity.h"
struct Bullet :
	public Entity
{
public:
	Bullet() : Bullet(0, 0) { }
	Bullet(float, float);
	~Bullet();

	bool Fire(sf::Vector2f _dir, float _speed);
	bool Fire(sf::Vector2f _start, sf::Vector2f _dir, float _speed);

	void SetPosition(float, float) override;
	void Move(float, float) override;
	void Update(sf::Time deltaTime);

	float GetDmg();

private:

	void CheckBounds();
	float dmg = 0.2;
	sf::Vector2f dir;
};

