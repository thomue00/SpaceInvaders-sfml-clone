#include "Enemy.h"
#include "Scene.h"
#include <sstream>
#include <string>

Enemy::Enemy(float x, float y)
{
	int w = Constants::INVADER_WIDTH;
	int h = Constants::INVADER_HEIGHT;

	int id = (1 + (rand() % static_cast<int>(6 - 1 + 1)));
	std::stringstream ss;
	ss << "imgs/Invader_0" << id << ".png";

	if (!texture.loadFromFile(ss.str())) {
		throw std::invalid_argument("Texture not loaded");
	}
	else {
		sprite.setTexture(texture);
	}
	//sprite.setColor(sf::Color::Red);
	sprite.setOrigin(w/2, h/2); // Pivot Center

	SetPosition(x, y);
}


Enemy::~Enemy()
{
}

void Enemy::Draw(sf::RenderWindow & win)
{

	sprite.setTexture(texture);
	Entity::Draw(win);

}

void Enemy::Reset()
{
	isAlive = true;
}
