#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"


PlayerService::PlayerService()
{
	player_controller = new PlayerController();

}

PlayerService::~PlayerService() = default;

void PlayerService::initialize()
{
	player_controller->initialize();
}

void PlayerService::update()
{
	player_controller->update();
}

void PlayerService::render()
{
	player_controller->render();
}




