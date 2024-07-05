#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"

namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Graphic;


		MainMenuUIController::MainMenuUIController() { game_window = nullptr; }

		void MainMenuUIController::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeBackgroundImage();
			initializeButtons();
		}

		void MainMenuUIController::initializeBackgroundImage()
		{   //check if a texture loaded properly
			if (background_texture.loadFromFile(background_texture_path))
			{   //if it did then set the bg image and scale it
				background_sprite.setTexture(background_texture);
				scaleBackgroundImage();
			}
		}

		void MainMenuUIController::scaleBackgroundImage()
		{
			background_sprite.setScale(
				static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
				static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
			);
		}

		void MainMenuUIController::initializeButtons()
		{
			// check if the tectures loaded
			if (loadButtonTexturesFromFile())
			{
				// order of function calls matter
				setButtonSprites();
				scaleAllButttons();
				positionButtons();
			}
		}
		// only returns true if all tectures are loaded
		bool MainMenuUIController::loadButtonTexturesFromFile()
		{
			return play_button_texture.loadFromFile(play_button_texture_path) &&
				instructions_button_texture.loadFromFile(instructions_button_texture_path) &&
				quit_button_texture.loadFromFile(quit_button_texture_path);
		}

		void MainMenuUIController::setButtonSprites()
		{
			play_button_sprite.setTexture(play_button_texture);
			instructions_button_sprite.setTexture(instructions_button_texture);
			quit_button_sprite.setTexture(quit_button_texture);
		}


		void MainMenuUIController::scaleAllButttons()
		{
			scaleButton(&play_button_sprite);
			scaleButton(&instructions_button_sprite);
			scaleButton(&quit_button_sprite);
		}

		void MainMenuUIController::scaleButton(sf::Sprite* button_to_scale)
		{
			button_to_scale->setScale(
				button_width / button_to_scale->getTexture()->getSize().x,
				button_height / button_to_scale->getTexture()->getSize().y
			);
		}

		void MainMenuUIController::positionButtons()
		{
			float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

			play_button_sprite.setPosition({ x_position, 300.f });
			instructions_button_sprite.setPosition({ x_position, 450.f });
			quit_button_sprite.setPosition({ x_position, 600.f });
		}
		void MainMenuUIController::update()
		{

		}

		void MainMenuUIController::render()
		{
			game_window->draw(background_sprite);
			game_window->draw(play_button_sprite);
			game_window->draw(instructions_button_sprite);
			game_window->draw(quit_button_sprite);
		}


	}
}