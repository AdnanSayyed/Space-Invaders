#include "../../Header/Player/PlayerService.h"

#include "../../Header/Player/PlayerController.h"

namespace Player {

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


}
