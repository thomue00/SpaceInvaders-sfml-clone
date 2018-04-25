#include <SFML\Graphics.hpp>
#include "Scene.h"


int main() {

	bool paused = false;

	sf::Clock clock;
	sf::Clock shootClock;
	shootClock.restart();

	sf::RenderWindow window(sf::VideoMode(Constants::WIN_WIDTH, Constants::WIN_WIDTH), "Space Invaders!");
	window.setVerticalSyncEnabled(true);
	Scene scene(window);

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		sf::Event event;
		while (scene.win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				scene.win.close();
			}

			if (event.type == sf::Event::KeyReleased) {

				if (event.key.code == sf::Keyboard::Space && scene.player->IsAlive()) {
					scene.playerBullet->Fire(scene.player->GetPosition(), sf::Vector2f(0, 1), 20);
				}
				if (event.key.code == sf::Keyboard::Pause) {
					paused = !paused;
				}
				if (event.key.code == sf::Keyboard::R) {
					scene.Restart();
				}
			}
		}

		if (shootClock.getElapsedTime().asSeconds() > Constants::SHOT_CLOCK_TIMER)
		{
			scene.InvaderShoot();
			shootClock.restart();
		}

		if (!paused) {
	
			scene.Update(elapsed);
			scene.win.clear();
			scene.Draw();
			scene.win.display();
		}
	}

	return 0;
}