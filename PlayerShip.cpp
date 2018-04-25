#include "PlayerShip.h"



PlayerShip::PlayerShip(float _speed)
{
	speed = _speed;

	//sf::Uint8* pixels = new sf::Uint8[80 * 50 * 4]; // * 4 because pixels have 4 components (RGBA)
	//for (int i = 0; i < 80 * 50 * 4; i += 4) {
		//pixels[i + 0] = 25;
		//pixels[i + 1] = 157;
		//pixels[i + 2] = 87;
		//pixels[i + 3] = 255;
	//}
	//texture.create(80, 50);
	//texture.update(pixels);
	//texture.loadFromFile("TestTexture.png");
	

	if (!texture.loadFromFile("PlayerShip_Sprite.png")) {
		throw std::invalid_argument("Texture not loaded");
	}
	sprite.setTexture(texture);
	sprite.setOrigin(40, 25); // Pivot Center
}

PlayerShip::~PlayerShip()
{

}

void PlayerShip::SetPosition(float x, float y)
{
	Entity::SetPosition(x, y);
	ClampPosition();
}

void PlayerShip::Move(float x, float y)
{
	Entity::Move(x, y);
	ClampPosition();
}

void PlayerShip::Hit(float dmg)
{
	health -= dmg;
	if (health < 0) {
		Kill();
	}
}
