#include "../Header/GameService.h";
#include "../Header/Global/ServiceLocator.h";
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"


void GameService::initialize() {
	//initialize things

	service_locator->initialize();
	initializeVariables();
}

void GameService::initializeVariables()
{
	game_window = service_locator->getGraphicsService()->getGameWindow();
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
	game_window->clear(service_locator->getGraphicsService()->getWindowColor());
	service_locator->render();

	game_window->display();
}

bool GameService::isRunning() {
	//game is running or not
	return game_window->isOpen();
}