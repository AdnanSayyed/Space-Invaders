#include "../Header/EventService.h"
#include "../Header/GameService.h"

EventService::EventService()
{
	game_window = nullptr;
}

EventService::~EventService() = default;

void EventService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();
}

bool EventService::isGameWindowOpen()
{
	return game_window != nullptr;
}

bool EventService::gameWindowWasClosed()
{
	return game_event.type == sf::Event::Closed;
}

bool EventService::hasQuitGame()
{
	return isKeyboardEvent() && EventService::pressedEscKey();
}


void EventService::update()
{
}

void EventService::processEvents()
{
	if (isGameWindowOpen()) {

		while (game_window->pollEvent(game_event))
		{
			if (gameWindowWasClosed() || hasQuitGame()) {
				game_window->close();
			}
		}
	}
}

bool EventService::pressedEscKey()
{
	return game_event.key.code == sf::Keyboard::Escape;
}

bool EventService::isKeyboardEvent()
{
	return game_event.type == sf::Event::KeyPressed;
}
