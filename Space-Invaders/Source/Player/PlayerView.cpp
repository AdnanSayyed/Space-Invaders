#pragma once
#include <SFML/Graphics.hpp>

class PlayerView
{
private:

	const sf::String player_texture_path = "assets/textures/player_ship.png";
	const float player_sprite_width = 60.f;
	const float player_sprite_height = 60.f;

	sf::RenderWindow* game_window;

	sf::Texture player_texture;
	sf::Sprite player_sprite;

	void initializePlayerSprite();
	void scalePlayerSprite();

public:
	PlayerView();
	~PlayerView();

	void initialize();
	void update();
	void render();
};



#include "../../Header/Player/PlayerView.h"
#include "../../Header/ServiceLocator.h"

PlayerView::PlayerView() { }

PlayerView::~PlayerView() { }

void PlayerView::initialize(PlayerController* controller)
{
	player_controller = controller;
	game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();
	initializePlayerSprite();
}

void PlayerView::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
		scalePlayerSprite();
	}
}

void PlayerView::scalePlayerSprite()
{
	// setScale is an inbuilt method of the sprite class that takes two floats to scale the sprite. it scales the sprite to our desired height
	player_sprite.setScale(
		//Here we find the factor to scale our sprites with. Ignore the static_cast for now, we will discuss it later.
		static_cast<float>(player_sprite_width) / player_sprite.getTexture()->getSize().x,
		static_cast<float>(player_sprite_height) / player_sprite.getTexture()->getSize().y
	);
}

void PlayerView::update()
{
	player_sprite.setPosition(player_controller->getPlayerPosition());
}

void PlayerView::render()
{
	game_window->draw(player_sprite);
}