#include "Bullet.h"


Bullet::Bullet(float x, float y)
{
	int w = 2;
	int h = 30;
	sf::Uint8* pixels = new sf::Uint8[w * h* 4]; // * 4 because pixels have 4 components (RGBA)
	for (int i = 0; i < w + h * 4; i += 4) {

		pixels[i + 0] = 255;
		pixels[i + 1] = 255;
		pixels[i + 2] = 255;
		pixels[i + 3] = 255;
	}

	//texture.loadFromFile("TestTexture.png");
	texture.create(w, h);
	texture.update(pixels);
	sprite.setTexture(texture);
	sprite.setOrigin(w/2, h/2); // Pivot Center

	SetPosition(x, y);
}


Bullet::~Bullet()
{
}

bool Bullet::Fire(sf::Vector2f _dir, float _speed)
{
	if (isAlive || _speed == 0) {
		return false;
	}

	dir = _dir;
	SetSpeed(_speed);
	isAlive = true;
	return true;

}

bool Bullet::Fire(sf::Vector2f _start, sf::Vector2f _dir, float _speed)
{
	if (Fire(_dir, _speed)) {
	
		SetPosition(_start.x, _start.y);
		return true;
	}
	return false;
}

void Bullet::SetPosition(float x, float y)
{
	Entity::SetPosition(x, y);
	CheckBounds();
}

void Bullet::Move(float x, float y)
{
	Entity::Move(x, y);
	CheckBounds();
}

void Bullet::Update(sf::Time deltaTime)
{
	if (isAlive) {
		Move(dir.x * deltaTime.asSeconds() * 50, dir.y * deltaTime.asSeconds() * -50);
	}
}

float Bullet::GetDmg()
{
	return dmg;
}

void Bullet::CheckBounds()
{
	if (isAlive) {

		sf::Vector2f pos = sprite.getPosition();
		if (pos.x > Constants::WIN_WIDTH || pos.x < 0 || pos.y > Constants::WIN_HEIGHT || pos.y < -80) { 
			Kill(); 
		}
	}
}
