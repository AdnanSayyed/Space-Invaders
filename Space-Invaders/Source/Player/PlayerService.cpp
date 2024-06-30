#include "../../Header/Player/PlayerService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h";
#include "../../Header/Event/EventService.h"

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




