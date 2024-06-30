#pragma once
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