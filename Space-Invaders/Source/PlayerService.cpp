#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"

void PlayerService::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
	}
}

void PlayerService::processPlayerInput()
{
	// Handle keyboard input
	if (event_service->pressedLeftKey()) {
		move(-1.0f * getMoveSpeed());
	}
	if (event_service->pressedRightKey()) {
		move(1.0f * getMoveSpeed());
	}
}

PlayerService::PlayerService()
{
	game_window = nullptr;
	event_service = nullptr;
}

PlayerService::~PlayerService() = default;

void PlayerService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();
	event_service = ServiceLocator::getInstance()->getEventService();
	initializePlayerSprite();
}

void PlayerService::update()
{
	processPlayerInput();
	player_sprite.setPosition(getPosition());
}

void PlayerService::render()
{
	game_window->draw(player_sprite);
}

void PlayerService::move(float offsetX)
{
	position.x += offsetX;
}

int PlayerService::getMoveSpeed()
{
	return movement_speed;
}

sf::Vector2f PlayerService::getPosition()
{
	return position;
}


