#include "../../Header/Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"

namespace Main {


	using namespace Global;

	GameState GameService::current_state = GameState::BOOT;
	void GameService::initialize() {
		//initialize things

		service_locator->initialize();
		initializeVariables();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
	}

	void GameService::destroy() {
		//clear resources
	}

	GameService::GameService() {
		//constructor
		game_window = nullptr;
		service_locator = nullptr;
	}

	GameService::~GameService() {
		//destructor

		destroy();
	}

	void GameService::ignite() {
		//start the game
		service_locator = service_locator->getInstance();
		initialize();
	}

	void GameService::update() {
		//update game logic and state

		service_locator->getEventService()->processEvents();

		service_locator->update();

	}


	void GameService::render() {
		//render each frame
		game_window->clear(service_locator->getGraphicService()->getWindowColor());
		service_locator->render();

		game_window->display();
	}

	bool GameService::isRunning() {
		//game is running or not
		return game_window->isOpen();
	}

	GameState GameService::getGameState()
	{
		return current_state;
	}

	void GameService::setGameState(GameState new_state)
	{
		current_state = new_state;
	}


}