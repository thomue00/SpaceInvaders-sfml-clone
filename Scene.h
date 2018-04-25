#pragma once
#ifndef SCENEH
#define SCENEH

#include "Entity.h"
#include "PlayerShip.h"
#include "BulletList.h"
#include "Enemy.h"

using namespace std;

class Scene
{
public:
	Scene(sf::RenderWindow &_win);
	~Scene();

	void Restart();

	void Update(sf::Time);
	void Draw();

	void InvaderShoot();

	sf::RenderWindow &win;

	PlayerShip* player;
	Bullet *playerBullet;
	Enemy invader[Constants::INVADER_COUNT];
	std::vector<Bullet> bullets;
	//struct Bullet *bullets;

private:
	int currentDirX;
};

#endif