#include <SFML/Graphics.hpp>
#include "Header/GameService.h";
//class Player {
//private:
//	int player_score = 0;
//	int health = 3;
//	int movement_speed = 2;
//	sf::Vector2f position = sf::Vector2f(200, 200);
//
//public:
//	sf::Texture playerTexture;
//	sf::Sprite playerSprite;
//
//	void takeDamage(int amt) {
//
//	}
//
//	void shootBullets() {
//
//	}
//
//	void move(int offsetX) {
//		position.x += offsetX;
//
//	}
//	sf::Vector2f getPosition() {
//		return position;
//	}
//
//	int getMoveSpeed() {
//		return movement_speed;
//	}
//};

int main() {


	/*sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

	sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

	Player player;
	player.playerTexture.loadFromFile("assets/textures/player_ship.png");
	player.playerSprite.setTexture(player.playerTexture);

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear(sf::Color::Blue);

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			player.move(-1*player.getMoveSpeed());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			player.move(1*player.getMoveSpeed());
		}

		player.playerSprite.setPosition(player.getPosition());
		window->draw(player.playerSprite);



		window->display();
	}*/

	GameService* gameService = new GameService();
	gameService->ignite();
	while (gameService->isRunning())	{

		gameService->update();
		gameService->render();
	}


	return 0;
}
