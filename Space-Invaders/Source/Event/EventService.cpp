#include "../../Header/Event/EventService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include"../../Header/Graphic/GraphicService.h"

namespace Event {
	using namespace Global;

	EventService::EventService()
	{
		game_window = nullptr;
	}

	EventService::~EventService() = default;

	void EventService::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
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
		updateMouseButtonsState(left_mouse_button_state, sf::Mouse::Left);
		updateMouseButtonsState(right_mouse_button_state, sf::Mouse::Right);
		updateKeyboardButtonsState(left_arrow_button_state, sf::Keyboard::Left);
		updateKeyboardButtonsState(right_arrow_button_state, sf::Keyboard::Right);
		updateKeyboardButtonsState(A_button_state, sf::Keyboard::A);
		updateKeyboardButtonsState(D_button_state, sf::Keyboard::D);
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

	bool EventService::pressedLeftKey()
	{
		return game_event.key.code == sf::Keyboard::Left;
	}

	bool EventService::pressedRightKey()
	{
		return game_event.key.code == sf::Keyboard::Right;
	}

	bool EventService::pressedLeftMouseButton()
	{
		return game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Left;
	}

	bool EventService::pressedRightMouseButton()
	{
		return game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Right;
	}

	bool EventService::pressedAKey()
	{
		return A_button_state == ButtonState::HELD;
	}

	bool EventService::pressedDKey() {
		return D_button_state == ButtonState::HELD;
	}


	void EventService::updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button)
	{
		if (sf::Mouse::isButtonPressed(mouse_button))
		{
			switch (current_button_state)
			{
			case ButtonState::RELEASED:
				current_button_state = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				current_button_state = ButtonState::HELD;
				break;
			}
		}
		else
		{
			current_button_state = ButtonState::RELEASED;
		}
	}

	void EventService::updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button)
	{
		if (sf::Keyboard::isKeyPressed(keyboard_button))
		{
			switch (current_button_state)
			{
			case ButtonState::RELEASED:
				current_button_state = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				current_button_state = ButtonState::HELD;
				break;
			}
		}
		else
		{
			current_button_state = ButtonState::RELEASED;
		}
	}


}

