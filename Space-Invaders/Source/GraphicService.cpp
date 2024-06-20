#include "../Header/GraphicService.h"

void GraphicsService::setVideoMode()
{
	video_mode = new sf::VideoMode(game_window_width, game_window_height,
		sf::VideoMode::getDesktopMode().bitsPerPixel);
}

void GraphicsService::onDestroy()
{
	delete(video_mode);
	delete(game_window);
}

GraphicsService::GraphicsService()
{
	game_window = nullptr;
	video_mode = nullptr;
}

GraphicsService::~GraphicsService()
{
	onDestroy();
}

sf::RenderWindow* GraphicsService::createGameWindow()
{
	setVideoMode();
	return new sf::RenderWindow(*video_mode, game_window_title);
	return nullptr;
}

void GraphicsService::initialize()
{
	game_window = createGameWindow();
	game_window->setFramerateLimit(frame_rate);
}

void GraphicsService::update()
{
}

void GraphicsService::render()
{
}

bool GraphicsService::isGameWindowOpen()
{
	return game_window->isOpen();
}

sf::RenderWindow* GraphicsService::getGameWindow()
{
	return game_window;
}

sf::Color GraphicsService::getWindowColor()
{
	return window_color;
}