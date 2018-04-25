#include "Entity.h"



Entity::Entity()
{
	isAlive = true;

	//sf::Uint8* pixels = new sf::Uint8[30 * 30 * 4]; // * 4 because pixels have 4 components (RGBA)
	//for (int i = 0; i < 30 * 30 * 4; i += 4) {
	//
	//	pixels[i + 0] = 25;
	//	pixels[i + 1] = 157;
	//	pixels[i + 2] = 87;
	//	pixels[i + 3] = 255;
	//}
	//
	////texture.loadFromFile("TestTexture.png");
	//texture.create(30, 30);
	//texture.update(pixels);
	//sprite.setTexture(texture);
	//sprite.setOrigin(15, 15); // Pivot Center
}


Entity::~Entity()
{
}

void Entity::SetPosition(float x, float y)
{
	sprite.setPosition(x, y);

}

void Entity::Move(float x, float y)
{
	sprite.move(x * speed, y * speed);
}

void Entity::Draw(sf::RenderWindow & win)
{
	if (isAlive) {
		win.draw(sprite);
	}
}

sf::Vector2f Entity::GetPosition()
{
	return sprite.getPosition();
}

sf::FloatRect Entity::GetRect()
{
	return sprite.getGlobalBounds();
}

bool Entity::IsAlive()
{
	return isAlive;
}

void Entity::Kill()
{
	isAlive = false;
}

void Entity::SetSpeed(float s)
{
	speed = s;
}

void Entity::ClampPosition()
{
	
	sf::Vector2f pos = sprite.getPosition();
	sf::FloatRect rect = sprite.getLocalBounds();

	sf::Vector2f maxPos(Constants::WIN_WIDTH - rect.width * 0.5, Constants::WIN_HEIGHT - rect.height * 0.5);
	sf::Vector2f minPos(rect.width * 0.5, rect.height * 0.5);
	if (pos.x > maxPos.x) { pos.x = maxPos.x; }
	else if (pos.x < minPos.x) { pos.x = minPos.x; }

	if (pos.y > maxPos.y) { pos.y = maxPos.y; }
	else if (pos.y < minPos.y) { pos.y = minPos.y; }

	sprite.setPosition(pos);
}
