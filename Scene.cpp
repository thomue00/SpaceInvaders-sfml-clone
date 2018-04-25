#include "Scene.h"
#include "CollisionManager.h"

Scene::Scene(sf::RenderWindow &_win) : win(_win)
{
	player = new PlayerShip(0.3);
	playerBullet = new Bullet();

	for (int i = 0; i < Constants::INVADER_COUNT; i++) {
		Enemy enemy(0, 0);
		invader[i] = enemy;
	}

	Restart();

	//currentDirX = 1;
	//playerBullet->Kill();
	//player->SetPosition(Constants::WIN_HALF_WIDTH, Constants::WIN_WIDTH - 60);



	// Create Invader
	/*float saveAreaX = Constants::WIN_WIDTH - 200;
	float ocSpace = Constants::INVADER_COUNT_PER_ROW * Constants::INVADER_WIDTH;
	float freeSpace = saveAreaX - ocSpace;
	float offsetX = freeSpace / Constants::INVADER_COUNT_PER_ROW;

	int i = 0;
	for (int x = 0; x < Constants::INVADER_COUNT_PER_ROW; x++) {
	
		for (int y = 1; y <= Constants::INVADER_COUNT_ROWS; y++) {

			Enemy enemy(100 + Constants::INVADER_WIDTH / 2 + x * (Constants::INVADER_WIDTH + offsetX), y * 70);
			invader[i++] = enemy;
		}
	}*/
}


Scene::~Scene()
{
}

void Scene::Restart()
{
	currentDirX = 1;
	playerBullet->Kill();
	player->SetPosition(Constants::WIN_HALF_WIDTH, Constants::WIN_WIDTH - 60);

	float saveAreaX = Constants::WIN_WIDTH - 200;
	float ocSpace = Constants::INVADER_COUNT_PER_ROW * Constants::INVADER_WIDTH;
	float freeSpace = saveAreaX - ocSpace;
	float offsetX = freeSpace / Constants::INVADER_COUNT_PER_ROW;
	int i = 0;
	for (int x = 0; x < Constants::INVADER_COUNT_PER_ROW; x++) {
		for (int y = 1; y <= Constants::INVADER_COUNT_ROWS; y++) {

			invader[i].Reset();
			invader[i++].SetPosition(100 + Constants::INVADER_WIDTH / 2 + x * (Constants::INVADER_WIDTH + offsetX), y * 70);
		}
	}
}

void Scene::Update(sf::Time deltaTime)
{
	float dt = deltaTime.asMilliseconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player->Move(-dt , 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player->Move(dt, 0);
	}

	playerBullet->Update(deltaTime);

	bool moveY = false;
	for (int i = 0; i < Constants::INVADER_COUNT; i++) {

		if (invader[i].IsAlive()) {

			if (invader[i].GetPosition().x > Constants::WIN_WIDTH - 10 - Constants::INVADER_WIDTH / 2) {

				moveY = true;
				currentDirX = 1;
				break;
			}
			if (invader[i].GetPosition().x < 10 + Constants::INVADER_WIDTH / 2) {

				moveY = true;
				currentDirX = -1;
				break;
			}
		}
	}

	
	for (int i = 0; i < Constants::INVADER_COUNT; i++) {
		invader[i].Move(currentDirX * 0.000001 * deltaTime.asSeconds(), moveY ? -0.0000001 : 0);
	}

	//for (int i = 0; i < bullets.size(); i++) {
	for (int i = bullets.size() - 1; i >= 0; i--) {

		bullets[i].Update(deltaTime);
		if (!bullets[i].IsAlive()) {
			bullets.erase(bullets.begin() + i);
		}
	}


	if (playerBullet->IsAlive()) {

		for (int i = 0; i < Constants::INVADER_COUNT; i++) {

			if (invader[i].IsAlive()) {

				if (CollisionManager::Overlap(invader[i].GetRect(), playerBullet->GetRect())) {

					invader[i].Kill();
					playerBullet->Kill();
				}
			}
		}
	}

	for (int i = 0; i < bullets.size(); i++) {

		if (CollisionManager::Overlap(bullets[i].GetRect(), player->GetRect())) {
			player->Hit(bullets[i].GetDmg());
		}
	}

	if (!player->IsAlive()) {
		Restart();
	}

}

void Scene::Draw()
{

	player->Draw(win);
	playerBullet->Draw(win);

	for (int i = 0; i < Constants::INVADER_COUNT; i++) {
		invader[i].Draw(win);
	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].Draw(win);
	}
}

void Scene::InvaderShoot()
{
	
	bool shot = false;
	while (!shot) {

		int i = rand() % Constants::INVADER_COUNT;
		if (invader[i].IsAlive()) {

			shot = true;
			Bullet bul(0, 0);
			bul.Kill();

			float speed = 5 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (12 - 5)));
			bul.Fire(invader[i].GetPosition(), sf::Vector2f(0, -1), speed);
			//bul.Fire(invader[i].GetPosition(), sf::Vector2f(0, -1), 6);
			bullets.push_back(bul);
			return;
		}
	}

}
