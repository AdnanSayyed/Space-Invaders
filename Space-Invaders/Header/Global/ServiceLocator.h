#pragma once

#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"

namespace Global
{
	class ServiceLocator {

	private:

		Graphic::GraphicService* graphic_service;
		Event::EventService* event_service;
		Player::PlayerService* player_service;
		Time::TimeService* time_service;

		ServiceLocator();
		~ServiceLocator();

		void createServices();
		void clearAllServices();

	public:
		static ServiceLocator* getInstance();

		void initialize();
		void update();
		void render();

		Graphic::GraphicService* getGraphicService();
		Event::EventService* getEventService();
		Player::PlayerService* getPlayerService();
		Time::TimeService* getTimeService();
	};
}
=======
#include "../../Header/Time/TimeService.h"

class GraphicsService;
class EventService;
class PlayerService;

class ServiceLocator {

private:

	GraphicsService* graphics_service;
	TimeService* time_service;
	EventService* event_service;
	PlayerService* player_service;

	ServiceLocator();
	~ServiceLocator();

	void createServices();
	void clearAllServices();

public:
	static ServiceLocator* getInstance();

	void initialize();
	void update();
	void render();

	GraphicsService* getGraphicsService();
	TimeService* getTimeService();
	EventService* getEventService();
	PlayerService* getPlayerService();
};

